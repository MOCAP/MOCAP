/****************************************************************************
** Meta object code from reading C++ file 'qwt_dial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwt_dial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_dial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtDial_t {
    QByteArrayData data[14];
    char stringdata[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QwtDial_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QwtDial_t qt_meta_stringdata_QwtDial = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 9),
QT_MOC_LITERAL(2, 18, 11),
QT_MOC_LITERAL(3, 30, 6),
QT_MOC_LITERAL(4, 37, 4),
QT_MOC_LITERAL(5, 42, 4),
QT_MOC_LITERAL(6, 47, 6),
QT_MOC_LITERAL(7, 54, 11),
QT_MOC_LITERAL(8, 66, 11),
QT_MOC_LITERAL(9, 78, 5),
QT_MOC_LITERAL(10, 84, 6),
QT_MOC_LITERAL(11, 91, 6),
QT_MOC_LITERAL(12, 98, 12),
QT_MOC_LITERAL(13, 111, 11)
    },
    "QwtDial\0lineWidth\0frameShadow\0Shadow\0"
    "mode\0Mode\0origin\0minScaleArc\0maxScaleArc\0"
    "Plain\0Raised\0Sunken\0RotateNeedle\0"
    "RotateScale\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtDial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       6,   14, // properties
       2,   32, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095103,
       2, 0x80000000 | 3, 0x0009510b,
       4, 0x80000000 | 5, 0x0009510b,
       6, QMetaType::Double, 0x00095103,
       7, QMetaType::Double, 0x00095103,
       8, QMetaType::Double, 0x00095103,

 // enums: name, flags, count, data
       3, 0x0,    3,   40,
       5, 0x0,    2,   46,

 // enum data: key, value
       9, uint(QwtDial::Plain),
      10, uint(QwtDial::Raised),
      11, uint(QwtDial::Sunken),
      12, uint(QwtDial::RotateNeedle),
      13, uint(QwtDial::RotateScale),

       0        // eod
};

void QwtDial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QwtDial::staticMetaObject = {
    { &QwtAbstractSlider::staticMetaObject, qt_meta_stringdata_QwtDial.data,
      qt_meta_data_QwtDial,  qt_static_metacall, 0, 0}
};


const QMetaObject *QwtDial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtDial::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtDial.stringdata))
        return static_cast<void*>(const_cast< QwtDial*>(this));
    return QwtAbstractSlider::qt_metacast(_clname);
}

int QwtDial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtAbstractSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = lineWidth(); break;
        case 1: *reinterpret_cast< Shadow*>(_v) = frameShadow(); break;
        case 2: *reinterpret_cast< Mode*>(_v) = mode(); break;
        case 3: *reinterpret_cast< double*>(_v) = origin(); break;
        case 4: *reinterpret_cast< double*>(_v) = minScaleArc(); break;
        case 5: *reinterpret_cast< double*>(_v) = maxScaleArc(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setLineWidth(*reinterpret_cast< int*>(_v)); break;
        case 1: setFrameShadow(*reinterpret_cast< Shadow*>(_v)); break;
        case 2: setMode(*reinterpret_cast< Mode*>(_v)); break;
        case 3: setOrigin(*reinterpret_cast< double*>(_v)); break;
        case 4: setMinScaleArc(*reinterpret_cast< double*>(_v)); break;
        case 5: setMaxScaleArc(*reinterpret_cast< double*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
