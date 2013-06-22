/****************************************************************************
** Meta object code from reading C++ file 'qwt_knob.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qwt_knob.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_knob.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtKnob_t {
    QByteArrayData data[22];
    char stringdata[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QwtKnob_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QwtKnob_t qt_meta_stringdata_QwtKnob = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 9),
QT_MOC_LITERAL(2, 18, 9),
QT_MOC_LITERAL(3, 28, 9),
QT_MOC_LITERAL(4, 38, 9),
QT_MOC_LITERAL(5, 48, 13),
QT_MOC_LITERAL(6, 62, 10),
QT_MOC_LITERAL(7, 73, 8),
QT_MOC_LITERAL(8, 82, 11),
QT_MOC_LITERAL(9, 94, 11),
QT_MOC_LITERAL(10, 106, 10),
QT_MOC_LITERAL(11, 117, 11),
QT_MOC_LITERAL(12, 129, 4),
QT_MOC_LITERAL(13, 134, 6),
QT_MOC_LITERAL(14, 141, 6),
QT_MOC_LITERAL(15, 148, 6),
QT_MOC_LITERAL(16, 155, 8),
QT_MOC_LITERAL(17, 164, 4),
QT_MOC_LITERAL(18, 169, 8),
QT_MOC_LITERAL(19, 178, 3),
QT_MOC_LITERAL(20, 182, 3),
QT_MOC_LITERAL(21, 186, 5)
    },
    "QwtKnob\0knobStyle\0KnobStyle\0knobWidth\0"
    "alignment\0Qt::Alignment\0totalAngle\0"
    "numTurns\0markerStyle\0MarkerStyle\0"
    "markerSize\0borderWidth\0Flat\0Raised\0"
    "Sunken\0Styled\0NoMarker\0Tick\0Triangle\0"
    "Dot\0Nub\0Notch\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtKnob[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       8,   14, // properties
       2,   38, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x0009510b,
       3, QMetaType::Int, 0x00095103,
       4, 0x80000000 | 5, 0x0009510b,
       6, QMetaType::Double, 0x00095103,
       7, QMetaType::Int, 0x00095103,
       8, 0x80000000 | 9, 0x0009510b,
      10, QMetaType::Int, 0x00095103,
      11, QMetaType::Int, 0x00095103,

 // enums: name, flags, count, data
       2, 0x0,    4,   46,
       9, 0x0,    6,   54,

 // enum data: key, value
      12, uint(QwtKnob::Flat),
      13, uint(QwtKnob::Raised),
      14, uint(QwtKnob::Sunken),
      15, uint(QwtKnob::Styled),
      16, uint(QwtKnob::NoMarker),
      17, uint(QwtKnob::Tick),
      18, uint(QwtKnob::Triangle),
      19, uint(QwtKnob::Dot),
      20, uint(QwtKnob::Nub),
      21, uint(QwtKnob::Notch),

       0        // eod
};

void QwtKnob::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QwtKnob::staticMetaObject = {
    { &QwtAbstractSlider::staticMetaObject, qt_meta_stringdata_QwtKnob.data,
      qt_meta_data_QwtKnob,  qt_static_metacall, 0, 0}
};


const QMetaObject *QwtKnob::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtKnob::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtKnob.stringdata))
        return static_cast<void*>(const_cast< QwtKnob*>(this));
    return QwtAbstractSlider::qt_metacast(_clname);
}

int QwtKnob::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtAbstractSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< KnobStyle*>(_v) = knobStyle(); break;
        case 1: *reinterpret_cast< int*>(_v) = knobWidth(); break;
        case 2: *reinterpret_cast< Qt::Alignment*>(_v) = alignment(); break;
        case 3: *reinterpret_cast< double*>(_v) = totalAngle(); break;
        case 4: *reinterpret_cast< int*>(_v) = numTurns(); break;
        case 5: *reinterpret_cast< MarkerStyle*>(_v) = markerStyle(); break;
        case 6: *reinterpret_cast< int*>(_v) = markerSize(); break;
        case 7: *reinterpret_cast< int*>(_v) = borderWidth(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setKnobStyle(*reinterpret_cast< KnobStyle*>(_v)); break;
        case 1: setKnobWidth(*reinterpret_cast< int*>(_v)); break;
        case 2: setAlignment(*reinterpret_cast< Qt::Alignment*>(_v)); break;
        case 3: setTotalAngle(*reinterpret_cast< double*>(_v)); break;
        case 4: setNumTurns(*reinterpret_cast< int*>(_v)); break;
        case 5: setMarkerStyle(*reinterpret_cast< MarkerStyle*>(_v)); break;
        case 6: setMarkerSize(*reinterpret_cast< int*>(_v)); break;
        case 7: setBorderWidth(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
