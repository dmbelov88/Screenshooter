#include "nativeeventfilter.h"
#include <QVector>
#include <QDebug>
#include <QX11Info>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <xcb/xcb.h>

namespace
{
    Display * m_display;        // Соединение с сервером X11
    Window m_win;               // Захватываемое окно - в данном случае будет вся система
    int keycode;                // код клавиши
    unsigned int modifier;      // код модификаторов

    QVector<quint32> maskModifiers(){
        return QVector<quint32>() << 0 << Mod2Mask << LockMask << (Mod2Mask | LockMask);
    }
}

NativeEventFilter::NativeEventFilter(QObject *parent) : QObject(parent)
{
    m_display = QX11Info::display();        // Создадим подключение к серверу
    m_win = DefaultRootWindow(m_display);   // и вытащим из него захватываемое окно с помощью макроса
}

bool NativeEventFilter::nativeEventFilter(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType)
    Q_UNUSED(result)

    xcb_key_press_event_t *keyEvent = 0;

    if (eventType == "xcb_generic_event_t") {
        xcb_generic_event_t *event = static_cast<xcb_generic_event_t *>(message);

        if ((event->response_type & 127) == XCB_KEY_PRESS){

            keyEvent = static_cast<xcb_key_press_event_t *>(message);

            foreach (quint32 maskMods, maskModifiers()) {
                qDebug() << modifier << " " << maskMods << "" << (modifier | maskMods );
                if((keyEvent->state == (modifier | maskMods ))
                        &&  keyEvent->detail == keycode){
                    emit activated();
                    return true;
                }
            }
        }
    }
    return false;
}

void NativeEventFilter::setShortcut()
{
    unsetShortcut();

    keycode = XKeysymToKeycode(m_display, XK_E);
    modifier = ControlMask;

    foreach (quint32 maskMods, maskModifiers()) {
        XGrabKey(m_display,         // указываем соединение с X11
                 keycode ,          // код клавиши
                 modifier | maskMods,   // модификатор со всеми возможными масками
                 m_win,             // Захватываемое окно
                 True,              // Является ли приложение владельцем события. в данном примере не принципиально.
                 GrabModeAsync,     // Обязательно Ассинхронный режим обработки, иначе, рискуете встрять
                 GrabModeAsync);    // с замороженной системой, не реагирующей ни на какие воздействия, если
                                    // заранее не напишите корректную передачу события обратно в систему,
                                    // а скорее всего так и будет
    }
}

void NativeEventFilter::unsetShortcut()
{
    foreach (quint32 maskMods, maskModifiers()) {
        XUngrabKey(m_display,
                   keycode,
                   modifier | maskMods,
                   m_win);
    }
}

