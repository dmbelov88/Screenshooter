#include "global_hotkeys_impl.h"

#include <QApplication>
#include <QDebug>
#include <QPair>
#include <QVector>

#include <QX11Info>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <xcb/xcb.h>

namespace
{
  Display *display;
  Window window;

  QVector<quint32> maskModifiers()
  {
    return QVector<quint32>() << 0 << Mod2Mask << LockMask <<
                                 (Mod2Mask | LockMask);
  }
}

CGlobalHotkeysImpl::CGlobalHotkeysImpl(QObject *parent) : QObject(parent)
{
  display = QX11Info::display();
  window = DefaultRootWindow(display);
}

bool CGlobalHotkeysImpl::nativeEventFilter(const QByteArray &eventType,
                                           void *message, long *result)
{
  Q_UNUSED(eventType)
  Q_UNUSED(result)

  uint modifier = 0;

  xcb_key_press_event_t *keyEvent = 0;

  if (eventType == "xcb_generic_event_t") {
    xcb_generic_event_t *event = static_cast<xcb_generic_event_t *>(message);

    if ((event->response_type & 127) == XCB_KEY_PRESS) {
      keyEvent = static_cast<xcb_key_press_event_t *>(message);

      for (auto& sequence: Hotkeys) {
        if (keyEvent->detail == XKeysymToKeycode(display,
                                                 getHotkey(sequence)))
        {
          modifier = stringToModificator(sequence.toString());
          foreach (quint32 maskMods, maskModifiers()) {
            if (keyEvent->state == (modifier | maskMods))
            {
              emit activated(sequence);
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}

void CGlobalHotkeysImpl::setHotkey(const QKeySequence &sequence)
{
  if (sequence.isEmpty())
    return;

  uint keycode = XKeysymToKeycode(display, getHotkey(sequence));
  uint modifier = stringToModificator(sequence.toString());
  Hotkeys.append(sequence);

  foreach (auto maskMods, maskModifiers())
  {
    XGrabKey(display, keycode, modifier | maskMods, window, True,
             GrabModeAsync, GrabModeAsync);
  }
}

void CGlobalHotkeysImpl::unsetHotkey(const QKeySequence &sequence)
{
  if (sequence.isEmpty())
    return;

  uint keycode = XKeysymToKeycode(display, getHotkey(sequence));
  uint modifier = stringToModificator(sequence.toString());

  for (auto i = 0; i < Hotkeys.size(); ++i)
  {
    if (XKeysymToKeycode(display, getHotkey(Hotkeys[i])) == keycode &&
        stringToModificator(Hotkeys[i].toString()) == modifier )
      Hotkeys.remove(i);
  }
  foreach (auto maskMods, maskModifiers())
  {
    XUngrabKey(display, keycode, modifier | maskMods, window);
  }
}

void CGlobalHotkeysImpl::onReplaceHotkey(const QKeySequence &newKey,
                                         const QKeySequence &oldKey)
{
  replaceHotkey(newKey, oldKey);
}

void CGlobalHotkeysImpl::unsetHotkeys()
{
  XUngrabKey(display, 0, 0, window);
  Hotkeys.clear();
}

unsigned int CGlobalHotkeysImpl::getHotkey(const QKeySequence &sequence)
{
  QStringList list = sequence.toString().split("+");
  QString str = list.last();
  switch (str.length())
  {
  case 0:
    return 0;
  default:
    return XStringToKeysym(str.toStdString().c_str());
  }
}

unsigned int CGlobalHotkeysImpl::stringToModificator(const QString &sequence)
{
  QStringList list = sequence.split("+");
  unsigned int modificator = 0;

  foreach (QString str, list) {
    if (str == "Ctrl") {
      modificator |= ControlMask;
      continue;
    } else if (str == "Alt") {
      modificator |= Mod1Mask;
      continue;
    } else if (str == "Shift") {
      modificator |= ShiftMask;
      continue;
    } else if (str == "Meta") {
      modificator |= Mod4Mask;
      continue;
    }
  }
  return modificator;
}
