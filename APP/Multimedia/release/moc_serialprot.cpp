/****************************************************************************
** Meta object code from reading C++ file 'serialprot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Send/serialprot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialprot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialProt_t {
    QByteArrayData data[13];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialProt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialProt_t qt_meta_stringdata_SerialProt = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SerialProt"
QT_MOC_LITERAL(1, 11, 8), // "sendFile"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "QSerialPort*"
QT_MOC_LITERAL(4, 34, 6), // "serial"
QT_MOC_LITERAL(5, 41, 4), // "data"
QT_MOC_LITERAL(6, 46, 18), // "on_refresh_clicked"
QT_MOC_LITERAL(7, 65, 21), // "on_openSerial_clicked"
QT_MOC_LITERAL(8, 87, 21), // "on_selectPath_clicked"
QT_MOC_LITERAL(9, 109, 19), // "on_downLoad_clicked"
QT_MOC_LITERAL(10, 129, 22), // "on_closeSerial_clicked"
QT_MOC_LITERAL(11, 152, 8), // "readData"
QT_MOC_LITERAL(12, 161, 17) // "on_cancel_clicked"

    },
    "SerialProt\0sendFile\0\0QSerialPort*\0"
    "serial\0data\0on_refresh_clicked\0"
    "on_openSerial_clicked\0on_selectPath_clicked\0"
    "on_downLoad_clicked\0on_closeSerial_clicked\0"
    "readData\0on_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialProt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,
      11,    0,   64,    2, 0x08 /* Private */,
      12,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SerialProt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialProt *_t = static_cast<SerialProt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFile((*reinterpret_cast< QSerialPort*(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->on_refresh_clicked(); break;
        case 2: _t->on_openSerial_clicked(); break;
        case 3: _t->on_selectPath_clicked(); break;
        case 4: _t->on_downLoad_clicked(); break;
        case 5: _t->on_closeSerial_clicked(); break;
        case 6: _t->readData(); break;
        case 7: _t->on_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SerialProt::*_t)(QSerialPort * , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialProt::sendFile)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SerialProt::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SerialProt.data,
      qt_meta_data_SerialProt,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialProt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialProt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialProt.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SerialProt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SerialProt::sendFile(QSerialPort * _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
