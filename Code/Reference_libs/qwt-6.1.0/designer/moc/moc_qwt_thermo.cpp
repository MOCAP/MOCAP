/****************************************************************************
** Meta object code from reading C++ file 'qwt_thermo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qwt_thermo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_thermo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtThermo_t {
    QByteArrayData data[23];
    char stringdata[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QwtThermo_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QwtThermo_t qt_meta_stringdata_QwtThermo = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 8),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 3),
QT_MOC_LITERAL(4, 24, 11),
QT_MOC_LITERAL(5, 36, 15),
QT_MOC_LITERAL(6, 52, 13),
QT_MOC_LITERAL(7, 66, 13),
QT_MOC_LITERAL(8, 80, 10),
QT_MOC_LITERAL(9, 91, 10),
QT_MOC_LITERAL(10, 102, 12),
QT_MOC_LITERAL(11, 115, 10),
QT_MOC_LITERAL(12, 126, 6),
QT_MOC_LITERAL(13, 133, 7),
QT_MOC_LITERAL(14, 141, 11),
QT_MOC_LITERAL(15, 153, 9),
QT_MOC_LITERAL(16, 163, 5),
QT_MOC_LITERAL(17, 169, 7),
QT_MOC_LITERAL(18, 177, 12),
QT_MOC_LITERAL(19, 190, 13),
QT_MOC_LITERAL(20, 204, 13),
QT_MOC_LITERAL(21, 218, 13),
QT_MOC_LITERAL(22, 232, 12)
    },
    "QwtThermo\0setValue\0\0val\0orientation\0"
    "Qt::Orientation\0scalePosition\0"
    "ScalePosition\0originMode\0OriginMode\0"
    "alarmEnabled\0alarmLevel\0origin\0spacing\0"
    "borderWidth\0pipeWidth\0value\0NoScale\0"
    "LeadingScale\0TrailingScale\0OriginMinimum\0"
    "OriginMaximum\0OriginCustom\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtThermo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
      10,   22, // properties
       2,   52, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // properties: name, type, flags
       4, 0x80000000 | 5, 0x0009510b,
       6, 0x80000000 | 7, 0x0009510b,
       8, 0x80000000 | 9, 0x0009510b,
      10, QMetaType::Bool, 0x00095103,
      11, QMetaType::Double, 0x00095103,
      12, QMetaType::Double, 0x00095103,
      13, QMetaType::Int, 0x00095103,
      14, QMetaType::Int, 0x00095103,
      15, QMetaType::Int, 0x00095103,
      16, QMetaType::Double, 0x00095103,

 // enums: name, flags, count, data
       7, 0x0,    3,   60,
       9, 0x0,    3,   66,

 // enum data: key, value
      17, uint(QwtThermo::NoScale),
      18, uint(QwtThermo::LeadingScale),
      19, uint(QwtThermo::TrailingScale),
      20, uint(QwtThermo::OriginMinimum),
      21, uint(QwtThermo::OriginMaximum),
      22, uint(QwtThermo::OriginCustom),

       0        // eod
};

void QwtThermo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QwtThermo *_t = static_cast<QwtThermo *>(_o);
        switch (_id) {
        case 0: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QwtThermo::staticMetaObject = {
    { &QwtAbstractScale::staticMetaObject, qt_meta_stringdata_QwtThermo.data,
      qt_meta_data_QwtThermo,  qt_static_metacall, 0, 0}
};


const QMetaObject *QwtThermo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtThermo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtThermo.stringdata))
        return static_cast<void*>(const_cast< QwtThermo*>(this));
    return QwtAbstractScale::qt_metacast(_clname);
}

int QwtThermo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtAbstractScale::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Qt::Orientation*>(_v) = orientation(); break;
        case 1: *reinterpret_cast< ScalePosition*>(_v) = scalePosition(); break;
        case 2: *reinterpret_cast< OriginMode*>(_v) = originMode(); break;
        case 3: *reinterpret_cast< bool*>(_v) = alarmEnabled(); break;
        case 4: *reinterpret_cast< double*>(_v) = alarmLevel(); break;
        case 5: *reinterpret_cast< double*>(_v) = origin(); break;
        case 6: *reinterpret_cast< int*>(_v) = spacing(); break;
        case 7: *reinterpret_cast< int*>(_v) = borderWidth(); break;
        case 8: *reinterpret_cast< int*>(_v) = pipeWidth(); break;
        case 9: *reinterpret_cast< double*>(_v) = value(); break;
        }
        _id -= 10;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setOrientation(*reinterpret_cast< Qt::Orientation*>(_v)); break;
        case 1: setScalePosition(*reinterpret_cast< ScalePosition*>(_v)); break;
        case 2: setOriginMode(*reinterpret_cast< OriginMode*>(_v)); break;
        case 3: setAlarmEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 4: setAlarmLevel(*reinterpret_cast< double*>(_v)); break;
        case 5: setOrigin(*reinterpret_cast< double*>(_v)); break;
        case 6: setSpacing(*reinterpret_cast< int*>(_v)); break;
        case 7: setBorderWidth(*reinterpret_cast< int*>(_v)); break;
        case 8: setPipeWidth(*reinterpret_cast< int*>(_v)); break;
        case 9: setValue(*reinterpret_cast< double*>(_v)); break;
        }
        _id -= 10;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
