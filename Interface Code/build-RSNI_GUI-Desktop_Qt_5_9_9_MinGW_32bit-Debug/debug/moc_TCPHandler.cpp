/****************************************************************************
** Meta object code from reading C++ file 'TCPHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RSNI_GUI/TCPHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TCPHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TCPHandler_t {
    QByteArrayData data[12];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPHandler_t qt_meta_stringdata_TCPHandler = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TCPHandler"
QT_MOC_LITERAL(1, 11, 16), // "TCPStatusChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "isConnected"
QT_MOC_LITERAL(4, 41, 16), // "newDataAvailable"
QT_MOC_LITERAL(5, 58, 4), // "data"
QT_MOC_LITERAL(6, 63, 16), // "handleTCPConnect"
QT_MOC_LITERAL(7, 80, 19), // "handleTCPDisconnect"
QT_MOC_LITERAL(8, 100, 14), // "enableLoopback"
QT_MOC_LITERAL(9, 115, 5), // "state"
QT_MOC_LITERAL(10, 121, 8), // "readData"
QT_MOC_LITERAL(11, 130, 16) // "handleTCPTimeout"

    },
    "TCPHandler\0TCPStatusChanged\0\0isConnected\0"
    "newDataAvailable\0data\0handleTCPConnect\0"
    "handleTCPDisconnect\0enableLoopback\0"
    "state\0readData\0handleTCPTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,
      10,    0,   60,    2, 0x08 /* Private */,
      11,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QByteArray,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TCPHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TCPHandler *_t = static_cast<TCPHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TCPStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->newDataAvailable((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->handleTCPConnect(); break;
        case 3: _t->handleTCPDisconnect(); break;
        case 4: _t->enableLoopback((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->readData(); break;
        case 6: _t->handleTCPTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TCPHandler::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPHandler::TCPStatusChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TCPHandler::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPHandler::newDataAvailable)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TCPHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TCPHandler.data,
      qt_meta_data_TCPHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TCPHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCPHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TCPHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TCPHandler::TCPStatusChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TCPHandler::newDataAvailable(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
