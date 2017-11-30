#include "global_hotkeys_impl.h"

#include <QVector>
#include <QKeySequence>

namespace {
  QVector<quint32> maskModifiers(){
    return QVector<quint32>() << 0 << Mod2Mask << LockMask << (Mod2Mask | LockMask);
  }
}

CGlobalHotkeysImpl::CGlobalHotkeys(QObject *parent) :
  QObject(parent)
{}

bool CGlobalHotkeysImpl::nativeEventFilter(const QByteArray &eventType,
                                       void *message, long *result)
{
  Q_UNUSED(eventType)
  Q_UNUSED(result)

  MSG* msg = reinterpret_cast<MSG*>(message);

  if (msg->message == WM_HOTKEY)
    for (auto& sequence: Hotkeys) {
      if (sequence == msg->wParam)
      {
        emit activated(sequence);
        return true;
      }
    }
  return true;
}

void CGlobalHotkeysImpl::setHotkey(const QKeySequence &sequence)
{
  hotkeys.append();
  RegisterHotKey(0, getKeyId(sequence), getKeyModificator(sequence),
      getHotKey(sequence));
}

void CGlobalHotkeysImpl::unsetHotKeys()
{
  for (auto &sequence: Hotkeys)
    UnregisterHotKey(0, sequence);

  Hotkeys.clear();
}

void CGlobalHotkeysImpl::unsetHotKey(const QKeySequence &sequence)
{
  QString str = sequence.toString().split(",");
  auto id = getKeyId(QKeySequence(str));
  for (auto i = 0; i < Hotkeys.size(); ++i)
  {
    if ()
      UnregisterHotKey(0, id);
      hotkeys.remove(id);
  }
}

unsigned int CGlobalHotkeysImpl::getHotKey(const QKeySequence &key)
{
  QString str = key.toString().split("+");
  switch (str.length())
  {
  case 0:
    return 0;
  case 1:
    return str.at(0).unicode();
  default:
    return ;
  }
}

unsigned int CGlobalHotkeysImpl::getKeyModificator(const QKeySequence &key)
{
  QStringList list = key.toString().split("+");
  unsigned int modificator = 0;

  foreach (QString str, list) {
    if(str == "Ctrl"){
      modificator |= Qt::CTRL;
      continue;
    } else if(str == "Alt"){
      modificator |= Qt::ALT;
      continue;
    } else if(str == "Shift"){
      modificator |= Qt::SHIFT;
      continue;
    } else if(str == "Meta"){
      modificator |= Qt::META;
      continue;
    }
  }
  return modificator;
}

unsigned int CGlobalHotkeysImpl::getKeyId(const QKeySequence &key)
{
  return this->getHotKey(key) ^ this->getKeyModificator(key);
}
