/****************************************************************************
** Meta object code from reading C++ file 'screen_shooter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../source/screen_shooter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screen_shooter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CScreenshooter_t {
    QByteArrayData data[6];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CScreenshooter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CScreenshooter_t qt_meta_stringdata_CScreenshooter = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CScreenshooter"
QT_MOC_LITERAL(1, 15, 7), // "warning"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 2), // "id"
QT_MOC_LITERAL(4, 27, 11), // "onActivated"
QT_MOC_LITERAL(5, 39, 8) // "sequence"

    },
    "CScreenshooter\0warning\0\0id\0onActivated\0"
    "sequence"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CScreenshooter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QKeySequence,    5,

       0        // eod
};

void CScreenshooter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CScreenshooter *_t = static_cast<CScreenshooter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->warning((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->onActivated((*reinterpret_cast< QKeySequence(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CScreenshooter::*_t)(uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CScreenshooter::warning)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CScreenshooter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CScreenshooter.data,
      qt_meta_data_CScreenshooter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CScreenshooter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CScreenshooter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CScreenshooter.stringdata0))
        return static_cast<void*>(const_cast< CScreenshooter*>(this));
    return QWidget::qt_metacast(_clname);
}

int CScreenshooter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CScreenshooter::warning(uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
