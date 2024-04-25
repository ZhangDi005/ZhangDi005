/****************************************************************************
** Meta object code from reading C++ file 'calculatemag.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Gather/calculatemag.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculatemag.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalculateMag_t {
    QByteArrayData data[9];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalculateMag_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalculateMag_t qt_meta_stringdata_CalculateMag = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CalculateMag"
QT_MOC_LITERAL(1, 13, 7), // "setData"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "flag"
QT_MOC_LITERAL(4, 27, 10), // "SeatManage"
QT_MOC_LITERAL(5, 38, 9), // "m_project"
QT_MOC_LITERAL(6, 48, 20), // "on_importBtn_clicked"
QT_MOC_LITERAL(7, 69, 32), // "on_selectBox_currentIndexChanged"
QT_MOC_LITERAL(8, 102, 5) // "index"

    },
    "CalculateMag\0setData\0\0flag\0SeatManage\0"
    "m_project\0on_importBtn_clicked\0"
    "on_selectBox_currentIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalculateMag[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   34,    2, 0x08 /* Private */,
       7,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void CalculateMag::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CalculateMag *_t = static_cast<CalculateMag *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< SeatManage(*)>(_a[2]))); break;
        case 1: _t->on_importBtn_clicked(); break;
        case 2: _t->on_selectBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CalculateMag::*_t)(int , SeatManage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalculateMag::setData)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CalculateMag::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CalculateMag.data,
      qt_meta_data_CalculateMag,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CalculateMag::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalculateMag::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalculateMag.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CalculateMag::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CalculateMag::setData(int _t1, SeatManage _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
