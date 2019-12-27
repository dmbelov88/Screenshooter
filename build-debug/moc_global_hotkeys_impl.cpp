/****************************************************************************
** Meta object code from reading C++ file 'global_hotkeys_impl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../source/global_hotkeys_impl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'global_hotkeys_impl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CGlobalHotkeysImpl_t {
    QByteArrayData data[7];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGlobalHotkeysImpl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGlobalHotkeysImpl_t qt_meta_stringdata_CGlobalHotkeysImpl = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CGlobalHotkeysImpl"
QT_MOC_LITERAL(1, 19, 9), // "activated"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "sequence"
QT_MOC_LITERAL(4, 39, 15), // "onReplaceHotkey"
QT_MOC_LITERAL(5, 55, 6), // "newKey"
QT_MOC_LITERAL(6, 62, 6) // "oldKey"

    },
    "CGlobalHotkeysImpl\0activated\0\0sequence\0"
    "onReplaceHotkey\0newKey\0oldKey"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGlobalHotkeysImpl[] = {

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
       4,    2,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QKeySequence,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QKeySequence, QMetaType::QKeySequence,    5,    6,

       0        // eod
};

void CGlobalHotkeysImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGlobalHotkeysImpl *_t = static_cast<CGlobalHotkeysImpl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activated((*reinterpret_cast< QKeySequence(*)>(_a[1]))); break;
        case 1: _t->onReplaceHotkey((*reinterpret_cast< const QKeySequence(*)>(_a[1])),(*reinterpret_cast< const QKeySequence(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CGlobalHotkeysImpl::*_t)(QKeySequence );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CGlobalHotkeysImpl::activated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CGlobalHotkeysImpl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CGlobalHotkeysImpl.data,
      qt_meta_data_CGlobalHotkeysImpl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGlobalHotkeysImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGlobalHotkeysImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGlobalHotkeysImpl.stringdata0))
        return static_cast<void*>(const_cast< CGlobalHotkeysImpl*>(this));
    if (!strcmp(_clname, "CGlobalHotkeys"))
        return static_cast< CGlobalHotkeys*>(const_cast< CGlobalHotkeysImpl*>(this));
    return QObject::qt_metacast(_clname);
}

int CGlobalHotkeysImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void CGlobalHotkeysImpl::activated(QKeySequence _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
