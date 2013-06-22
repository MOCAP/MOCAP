/****************************************************************************
** Meta object code from reading C++ file 'qwt_abstract_slider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qwt_abstract_slider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_abstract_slider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtAbstractSlider_t {
    QByteArrayData data[17];
    char stringdata[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QwtAbstractSlider_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QwtAbstractSlider_t qt_meta_stringdata_QwtAbstractSlider = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 12),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 5),
QT_MOC_LITERAL(4, 38, 13),
QT_MOC_LITERAL(5, 52, 14),
QT_MOC_LITERAL(6, 67, 11),
QT_MOC_LITERAL(7, 79, 8),
QT_MOC_LITERAL(8, 88, 3),
QT_MOC_LITERAL(9, 92, 10),
QT_MOC_LITERAL(10, 103, 11),
QT_MOC_LITERAL(11, 115, 9),
QT_MOC_LITERAL(12, 125, 13),
QT_MOC_LITERAL(13, 139, 8),
QT_MOC_LITERAL(14, 148, 8),
QT_MOC_LITERAL(15, 157, 8),
QT_MOC_LITERAL(16, 166, 16)
    },
    "QwtAbstractSlider\0valueChanged\0\0value\0"
    "sliderPressed\0sliderReleased\0sliderMoved\0"
    "setValue\0val\0totalSteps\0singleSteps\0"
    "pageSteps\0stepAlignment\0readOnly\0"
    "tracking\0wrapping\0invertedControls\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtAbstractSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       9,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x05,
       4,    0,   42,    2, 0x05,
       5,    0,   43,    2, 0x05,
       6,    1,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    1,   47,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    8,

 // properties: name, type, flags
       3, QMetaType::Double, 0x00095103,
       9, QMetaType::UInt, 0x00095103,
      10, QMetaType::UInt, 0x00095103,
      11, QMetaType::UInt, 0x00095103,
      12, QMetaType::Bool, 0x00095103,
      13, QMetaType::Bool, 0x00095103,
      14, QMetaType::Bool, 0x00095103,
      15, QMetaType::Bool, 0x00095103,
      16, QMetaType::Bool, 0x00095103,

       0        // eod
};

void QwtAbstractSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QwtAbstractSlider *_t = static_cast<QwtAbstractSlider *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->sliderPressed(); break;
        case 2: _t->sliderReleased(); break;
        case 3: _t->sliderMoved((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QwtAbstractSlider::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtAbstractSlider::valueChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QwtAbstractSlider::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtAbstractSlider::sliderPressed)) {
                *result = 1;
            }
        }
        {
            typedef void (QwtAbstractSlider::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtAbstractSlider::sliderReleased)) {
                *result = 2;
            }
        }
        {
            typedef void (QwtAbstractSlider::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtAbstractSlider::sliderMoved)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject QwtAbstractSlider::staticMetaObject = {
    { &QwtAbstractScale::staticMetaObject, qt_meta_stringdata_QwtAbstractSlider.data,
      qt_meta_data_QwtAbstractSlider,  qt_static_metacall, 0, 0}
};


const QMetaObject *QwtAbstractSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtAbstractSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtAbstractSlider.stringdata))
        return static_cast<void*>(const_cast< QwtAbstractSlider*>(this));
    return QwtAbstractScale::qt_metacast(_clname);
}

int QwtAbstractSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtAbstractScale::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = value(); break;
        case 1: *reinterpret_cast< uint*>(_v) = totalSteps(); break;
        case 2: *reinterpret_cast< uint*>(_v) = singleSteps(); break;
        case 3: *reinterpret_cast< uint*>(_v) = pageSteps(); break;
        case 4: *reinterpret_cast< bool*>(_v) = stepAlignment(); break;
        case 5: *reinterpret_cast< bool*>(_v) = isReadOnly(); break;
        case 6: *reinterpret_cast< bool*>(_v) = isTracking(); break;
        case 7: *reinterpret_cast< bool*>(_v) = wrapping(); break;
        case 8: *reinterpret_cast< bool*>(_v) = invertedControls(); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setValue(*reinterpret_cast< double*>(_v)); break;
        case 1: setTotalSteps(*reinterpret_cast< uint*>(_v)); break;
        case 2: setSingleSteps(*reinterpret_cast< uint*>(_v)); break;
        case 3: setPageSteps(*reinterpret_cast< uint*>(_v)); break;
        case 4: setStepAlignment(*reinterpret_cast< bool*>(_v)); break;
        case 5: setReadOnly(*reinterpret_cast< bool*>(_v)); break;
        case 6: setTracking(*reinterpret_cast< bool*>(_v)); break;
        case 7: setWrapping(*reinterpret_cast< bool*>(_v)); break;
        case 8: setInvertedControls(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QwtAbstractSlider::valueChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwtAbstractSlider::sliderPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QwtAbstractSlider::sliderReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QwtAbstractSlider::sliderMoved(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
