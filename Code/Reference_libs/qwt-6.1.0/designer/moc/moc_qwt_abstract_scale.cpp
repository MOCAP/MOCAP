/****************************************************************************
** Meta object code from reading C++ file 'qwt_abstract_scale.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qwt_abstract_scale.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_abstract_scale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtAbstractScale_t {
    QByteArrayData data[6];
    char stringdata[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QwtAbstractScale_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QwtAbstractScale_t qt_meta_stringdata_QwtAbstractScale = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 10),
QT_MOC_LITERAL(2, 28, 10),
QT_MOC_LITERAL(3, 39, 13),
QT_MOC_LITERAL(4, 53, 13),
QT_MOC_LITERAL(5, 67, 13)
    },
    "QwtAbstractScale\0lowerBound\0upperBound\0"
    "scaleMaxMajor\0scaleMaxMinor\0scaleStepSize\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtAbstractScale[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Double, 0x00095103,
       2, QMetaType::Double, 0x00095103,
       3, QMetaType::Int, 0x00095103,
       4, QMetaType::Int, 0x00095103,
       5, QMetaType::Double, 0x00095103,

       0        // eod
};

void QwtAbstractScale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QwtAbstractScale::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwtAbstractScale.data,
      qt_meta_data_QwtAbstractScale,  qt_static_metacall, 0, 0}
};


const QMetaObject *QwtAbstractScale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtAbstractScale::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtAbstractScale.stringdata))
        return static_cast<void*>(const_cast< QwtAbstractScale*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwtAbstractScale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = lowerBound(); break;
        case 1: *reinterpret_cast< double*>(_v) = upperBound(); break;
        case 2: *reinterpret_cast< int*>(_v) = scaleMaxMajor(); break;
        case 3: *reinterpret_cast< int*>(_v) = scaleMaxMinor(); break;
        case 4: *reinterpret_cast< double*>(_v) = scaleStepSize(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setLowerBound(*reinterpret_cast< double*>(_v)); break;
        case 1: setUpperBound(*reinterpret_cast< double*>(_v)); break;
        case 2: setScaleMaxMajor(*reinterpret_cast< int*>(_v)); break;
        case 3: setScaleMaxMinor(*reinterpret_cast< int*>(_v)); break;
        case 4: setScaleStepSize(*reinterpret_cast< double*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
