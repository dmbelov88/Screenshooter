/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../source/settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSettingsHelper_t {
    QByteArrayData data[15];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSettingsHelper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSettingsHelper_t qt_meta_stringdata_CSettingsHelper = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CSettingsHelper"
QT_MOC_LITERAL(1, 16, 11), // "setSettings"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "replaseHotkey"
QT_MOC_LITERAL(4, 43, 10), // "new_hotkey"
QT_MOC_LITERAL(5, 54, 10), // "old_hotkey"
QT_MOC_LITERAL(6, 65, 13), // "retranslateUi"
QT_MOC_LITERAL(7, 79, 7), // "setInfo"
QT_MOC_LITERAL(8, 87, 3), // "str"
QT_MOC_LITERAL(9, 91, 12), // "saveSettings"
QT_MOC_LITERAL(10, 104, 10), // "setAutorun"
QT_MOC_LITERAL(11, 115, 12), // "unsetAutorun"
QT_MOC_LITERAL(12, 128, 11), // "setLocaleId"
QT_MOC_LITERAL(13, 140, 2), // "id"
QT_MOC_LITERAL(14, 143, 4) // "info"

    },
    "CSettingsHelper\0setSettings\0\0replaseHotkey\0"
    "new_hotkey\0old_hotkey\0retranslateUi\0"
    "setInfo\0str\0saveSettings\0setAutorun\0"
    "unsetAutorun\0setLocaleId\0id\0info"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSettingsHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       1,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    2,   55,    2, 0x06 /* Public */,
       6,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   61,    2, 0x0a /* Public */,
       9,    0,   64,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,
      11,    0,   66,    2, 0x0a /* Public */,
      12,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QKeySequence, QMetaType::QKeySequence,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

 // properties: name, type, flags
      14, QMetaType::QString, 0x00095001,

       0        // eod
};

void CSettingsHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSettingsHelper *_t = static_cast<CSettingsHelper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSettings(); break;
        case 1: _t->replaseHotkey((*reinterpret_cast< const QKeySequence(*)>(_a[1])),(*reinterpret_cast< const QKeySequence(*)>(_a[2]))); break;
        case 2: _t->retranslateUi(); break;
        case 3: _t->setInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->saveSettings(); break;
        case 5: _t->setAutorun(); break;
        case 6: _t->unsetAutorun(); break;
        case 7: _t->setLocaleId((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSettingsHelper::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSettingsHelper::setSettings)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CSettingsHelper::*_t)(const QKeySequence , const QKeySequence );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSettingsHelper::replaseHotkey)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CSettingsHelper::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSettingsHelper::retranslateUi)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CSettingsHelper *_t = static_cast<CSettingsHelper *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->info(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject CSettingsHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CSettingsHelper.data,
      qt_meta_data_CSettingsHelper,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CSettingsHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSettingsHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSettingsHelper.stringdata0))
        return static_cast<void*>(const_cast< CSettingsHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int CSettingsHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CSettingsHelper::setSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CSettingsHelper::replaseHotkey(const QKeySequence _t1, const QKeySequence _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CSettingsHelper::retranslateUi()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
