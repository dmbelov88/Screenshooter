#CONFIG(debug, debug|release) {
#} else {
#}

CONFIG += c++14

QT += core widgets qml quick concurrent quickcontrols2

SOURCES += \
    source/global_hotkeys.cpp \
    source/screen_shooter.cpp \
    source/settings.cpp

HEADERS += \
    source/global_hotkeys.h \
    source/global_hotkeys_impl.h \
    source/screen_shooter.h \
    source/settings.h \
    source/worker.h \

RESOURCES += source/qml.qrc \
             resources/image.qrc

TRANSLATIONS += translations/Language_ru.ts

linux {
    QT       += x11extras
    CONFIG   += link_pkgconfig
    PKGCONFIG += x11
    SOURCES += source/global_hotkeys_linux.cpp
}
win32{
    SOURCES += source/global_hotkeys_win.cpp
}

win32-mingw {
    QMAKE_CXXFLAGS += -Wliteral-suffix
}

win32-msvc* {
    LIBS += -luser32
}

macos {
    LIBS += -framework AppKit
}

#-std=c++14
