QT += widgets testlib

INCLUDEPATH += \
    build-debug \
    source

#HEADERS += \

SOURCES += \
    unittests/test_settings.cpp

include(common.pri)
