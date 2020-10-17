/****************************************************************************
** Meta object code from reading C++ file 'ProcessPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RSNI_GUI/ProcessPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProcessPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProcessPage_t {
    QByteArrayData data[10];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcessPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcessPage_t qt_meta_stringdata_ProcessPage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ProcessPage"
QT_MOC_LITERAL(1, 12, 14), // "processMessage"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "RxMessage"
QT_MOC_LITERAL(4, 38, 3), // "msg"
QT_MOC_LITERAL(5, 42, 24), // "stopProcessButtonPressed"
QT_MOC_LITERAL(6, 67, 8), // "sensorID"
QT_MOC_LITERAL(7, 76, 25), // "pauseProcessButtonPressed"
QT_MOC_LITERAL(8, 102, 25), // "resetProcessButtonPressed"
QT_MOC_LITERAL(9, 128, 29) // "on_StartSensorButton_released"

    },
    "ProcessPage\0processMessage\0\0RxMessage\0"
    "msg\0stopProcessButtonPressed\0sensorID\0"
    "pauseProcessButtonPressed\0"
    "resetProcessButtonPressed\0"
    "on_StartSensorButton_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessPage[] = {

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
       5,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,
       8,    1,   48,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void ProcessPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProcessPage *_t = static_cast<ProcessPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processMessage((*reinterpret_cast< RxMessage(*)>(_a[1]))); break;
        case 1: _t->stopProcessButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->pauseProcessButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->resetProcessButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_StartSensorButton_released(); break;
        default: ;
        }
    }
}

const QMetaObject ProcessPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ProcessPage.data,
      qt_meta_data_ProcessPage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ProcessPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessPage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ProcessPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
