/****************************************************************************
** Meta object code from reading C++ file 'ConnectionPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RSNI_GUI/ConnectionPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConnectionPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConnectionPage_t {
    QByteArrayData data[9];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConnectionPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConnectionPage_t qt_meta_stringdata_ConnectionPage = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ConnectionPage"
QT_MOC_LITERAL(1, 15, 21), // "handleTCPStatusChange"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "isConnected"
QT_MOC_LITERAL(4, 50, 16), // "handleNewTCPData"
QT_MOC_LITERAL(5, 67, 4), // "data"
QT_MOC_LITERAL(6, 72, 25), // "on_ConnectButton_released"
QT_MOC_LITERAL(7, 98, 23), // "on_RawTextSend_released"
QT_MOC_LITERAL(8, 122, 25) // "on_LoopbackCheck_released"

    },
    "ConnectionPage\0handleTCPStatusChange\0"
    "\0isConnected\0handleNewTCPData\0data\0"
    "on_ConnectButton_released\0"
    "on_RawTextSend_released\0"
    "on_LoopbackCheck_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectionPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConnectionPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConnectionPage *_t = static_cast<ConnectionPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleTCPStatusChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->handleNewTCPData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->on_ConnectButton_released(); break;
        case 3: _t->on_RawTextSend_released(); break;
        case 4: _t->on_LoopbackCheck_released(); break;
        default: ;
        }
    }
}

const QMetaObject ConnectionPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConnectionPage.data,
      qt_meta_data_ConnectionPage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ConnectionPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectionPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectionPage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ConnectionPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
