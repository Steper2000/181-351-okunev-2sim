/****************************************************************************
** Meta object code from reading C++ file 'add.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../add.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'add.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_add_t {
    QByteArrayData data[9];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_add_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_add_t qt_meta_stringdata_add = {
    {
QT_MOC_LITERAL(0, 0, 3), // "add"
QT_MOC_LITERAL(1, 4, 25), // "on_pushButton_add_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 25), // "on_pushButton_del_clicked"
QT_MOC_LITERAL(4, 57, 14), // "slot_connected"
QT_MOC_LITERAL(5, 72, 15), // "slot_ready_read"
QT_MOC_LITERAL(6, 88, 19), // "slot_send_to_server"
QT_MOC_LITERAL(7, 108, 4), // "mess"
QT_MOC_LITERAL(8, 113, 16) // "slot_disconected"

    },
    "add\0on_pushButton_add_clicked\0\0"
    "on_pushButton_del_clicked\0slot_connected\0"
    "slot_ready_read\0slot_send_to_server\0"
    "mess\0slot_disconected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_add[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void add::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<add *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_add_clicked(); break;
        case 1: _t->on_pushButton_del_clicked(); break;
        case 2: _t->slot_connected(); break;
        case 3: _t->slot_ready_read(); break;
        case 4: _t->slot_send_to_server((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slot_disconected(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject add::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_add.data,
    qt_meta_data_add,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *add::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *add::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_add.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::add"))
        return static_cast< Ui::add*>(this);
    return QDialog::qt_metacast(_clname);
}

int add::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
