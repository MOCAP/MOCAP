/****************************************************************************
** Meta object code from reading C++ file 'qwt_slider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qwt_slider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_slider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtSlider_t {
    QByteArrayData data[13];
    char stringdata[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QwtSlider_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QwtSlider_t qt_meta_stringdata_QwtSlider = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 11),
QT_MOC_LITERAL(2, 22, 15),
QT_MOC_LITERAL(3, 38, 13),
QT_MOC_LITERAL(4, 52, 13),
QT_MOC_LITERAL(5, 66, 6),
QT_MOC_LITERAL(6, 73, 6),
QT_MOC_LITERAL(7, 80, 10),
QT_MOC_LITERAL(8, 91, 11),
QT_MOC_LITERAL(9, 103, 7),
QT_MOC_LITERAL(10, 111, 7),
QT_MOC_LITERAL(11, 119, 12),
QT_MOC_LITERAL(12, 132, 13)
    },
    "QwtSlider\0orientation\0Qt::Orientation\0"
    "scalePosition\0ScalePosition\0trough\0"
    "groove\0handleSize\0borderWidth\0spacing\0"
    "NoScale\0LeadingScale\0TrailingScale\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
       1,   35, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x0009510b,
       3, 0x80000000 | 4, 0x0009510b,
       5, QMetaType::Bool, 0x00095103,
       6, QMetaType::Bool, 0x00095103,
       7, QMetaType::QSize, 0x00095103,
       8, QMetaType::Int, 0x00095103,
       9, QMetaType::Int, 0x00095103,

 // enums: name, flags, count, data
       4, 0x0,    3,   39,

 // enum data: key, value
      10, uint(QwtSlider::NoScale),
      11, uint(QwtSlider::LeadingScale),
      12, uint(QwtSlider::TrailingScale),

       0        // eod
};

void QwtSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QwtSlider::staticMetaObject = {
    { &QwtAbstractSlider::staticMetaObject, qt_meta_stringdata_QwtSlider.data,
      qt_meta_data_QwtSlider,  qt_static_metacall, 0, 0}
};


const QMetaObject *QwtSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtSlider.stringdata))
        return static_cast<void*>(const_cast< QwtSlider*>(this));
    return QwtAbstractSlider::qt_metacast(_clname);
}

int QwtSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtAbstractSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Qt::Orientation*>(_v) = orientation(); break;
        case 1: *reinterpret_cast< ScalePosition*>(_v) = scalePosition(); break;
        case 2: *reinterpret_cast< bool*>(_v) = hasTrough(); break;
        case 3: *reinterpret_cast< bool*>(_v) = hasGroove(); break;
        case 4: *reinterpret_cast< QSize*>(_v) = handleSize(); break;
        case 5: *reinterpret_cast< int*>(_v) = borderWidth(); break;
        case 6: *reinterpret_cast< int*>(_v) = spacing(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setOrientation(*reinterpret_cast< Qt::Orientation*>(_v)); break;
        case 1: setScalePosition(*reinterpret_cast< ScalePosition*>(_v)); break;
        case 2: setTrough(*reinterpret_cast< bool*>(_v)); break;
        case 3: setGroove(*reinterpret_cast< bool*>(_v)); break;
        case 4: setHandleSize(*reinterpret_cast< QSize*>(_v)); break;
        case 5: setBorderWidth(*reinterpret_cast< int*>(_v)); break;
        case 6: setSpacing(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
