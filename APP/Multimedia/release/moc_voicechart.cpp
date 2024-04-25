/****************************************************************************
** Meta object code from reading C++ file 'voicechart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Module/voicechart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'voicechart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VoiceChart_t {
    QByteArrayData data[8];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoiceChart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoiceChart_t qt_meta_stringdata_VoiceChart = {
    {
QT_MOC_LITERAL(0, 0, 10), // "VoiceChart"
QT_MOC_LITERAL(1, 11, 10), // "mousePress"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 36, 6), // "mevent"
QT_MOC_LITERAL(5, 43, 9), // "mouseMove"
QT_MOC_LITERAL(6, 53, 12), // "mouseRelease"
QT_MOC_LITERAL(7, 66, 21) // "slot_SelectionChanged"

    },
    "VoiceChart\0mousePress\0\0QMouseEvent*\0"
    "mevent\0mouseMove\0mouseRelease\0"
    "slot_SelectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoiceChart[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       7,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void VoiceChart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VoiceChart *_t = static_cast<VoiceChart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->mouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->slot_SelectionChanged(); break;
        default: ;
        }
    }
}

const QMetaObject VoiceChart::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VoiceChart.data,
      qt_meta_data_VoiceChart,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VoiceChart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoiceChart::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VoiceChart.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VoiceChart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
