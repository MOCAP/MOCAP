/****************************************************************************
** Meta object code from reading C++ file 'qwt_wheel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qwt_wheel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_wheel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtWheel_t {
    QByteArrayData data[29];
    char stringdata[313];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QwtWheel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QwtWheel_t qt_meta_stringdata_QwtWheel = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 12),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 5),
QT_MOC_LITERAL(4, 29, 12),
QT_MOC_LITERAL(5, 42, 13),
QT_MOC_LITERAL(6, 56, 10),
QT_MOC_LITERAL(7, 67, 8),
QT_MOC_LITERAL(8, 76, 13),
QT_MOC_LITERAL(9, 90, 12),
QT_MOC_LITERAL(10, 103, 7),
QT_MOC_LITERAL(11, 111, 11),
QT_MOC_LITERAL(12, 123, 15),
QT_MOC_LITERAL(13, 139, 7),
QT_MOC_LITERAL(14, 147, 7),
QT_MOC_LITERAL(15, 155, 10),
QT_MOC_LITERAL(16, 166, 13),
QT_MOC_LITERAL(17, 180, 13),
QT_MOC_LITERAL(18, 194, 8),
QT_MOC_LITERAL(19, 203, 8),
QT_MOC_LITERAL(20, 212, 8),
QT_MOC_LITERAL(21, 221, 4),
QT_MOC_LITERAL(22, 226, 14),
QT_MOC_LITERAL(23, 241, 10),
QT_MOC_LITERAL(24, 252, 9),
QT_MOC_LITERAL(25, 262, 9),
QT_MOC_LITERAL(26, 272, 10),
QT_MOC_LITERAL(27, 283, 11),
QT_MOC_LITERAL(28, 295, 16)
    },
    "QwtWheel\0valueChanged\0\0value\0wheelPressed\0"
    "wheelReleased\0wheelMoved\0setValue\0"
    "setTotalAngle\0setViewAngle\0setMass\0"
    "orientation\0Qt::Orientation\0minimum\0"
    "maximum\0singleStep\0pageStepCount\0"
    "stepAlignment\0tracking\0wrapping\0"
    "inverted\0mass\0updateInterval\0totalAngle\0"
    "viewAngle\0tickCount\0wheelWidth\0"
    "borderWidth\0wheelBorderWidth\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtWheel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
      18,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x05,
       4,    0,   57,    2, 0x05,
       5,    0,   58,    2, 0x05,
       6,    1,   59,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    1,   62,    2, 0x0a,
       8,    1,   65,    2, 0x0a,
       9,    1,   68,    2, 0x0a,
      10,    1,   71,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,

 // properties: name, type, flags
      11, 0x80000000 | 12, 0x0009510b,
       3, QMetaType::Double, 0x00095103,
      13, QMetaType::Double, 0x00095103,
      14, QMetaType::Double, 0x00095103,
      15, QMetaType::Double, 0x00095103,
      16, QMetaType::Int, 0x00095103,
      17, QMetaType::Bool, 0x00095103,
      18, QMetaType::Bool, 0x00095103,
      19, QMetaType::Bool, 0x00095103,
      20, QMetaType::Bool, 0x00095103,
      21, QMetaType::Double, 0x00095103,
      22, QMetaType::Int, 0x00095103,
      23, QMetaType::Double, 0x00095103,
      24, QMetaType::Double, 0x00095103,
      25, QMetaType::Int, 0x00095103,
      26, QMetaType::Int, 0x00095103,
      27, QMetaType::Int, 0x00095103,
      28, QMetaType::Int, 0x00095103,

       0        // eod
};

void QwtWheel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QwtWheel *_t = static_cast<QwtWheel *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->wheelPressed(); break;
        case 2: _t->wheelReleased(); break;
        case 3: _t->wheelMoved((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setTotalAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setViewAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setMass((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QwtWheel::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtWheel::valueChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QwtWheel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtWheel::wheelPressed)) {
                *result = 1;
            }
        }
        {
            typedef void (QwtWheel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtWheel::wheelReleased)) {
                *result = 2;
            }
        }
        {
            typedef void (QwtWheel::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtWheel::wheelMoved)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject QwtWheel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwtWheel.data,
      qt_meta_data_QwtWheel,  qt_static_metacall, 0, 0}
};


const QMetaObject *QwtWheel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtWheel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtWheel.stringdata))
        return static_cast<void*>(const_cast< QwtWheel*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwtWheel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Qt::Orientation*>(_v) = orientation(); break;
        case 1: *reinterpret_cast< double*>(_v) = value(); break;
        case 2: *reinterpret_cast< double*>(_v) = minimum(); break;
        case 3: *reinterpret_cast< double*>(_v) = maximum(); break;
        case 4: *reinterpret_cast< double*>(_v) = singleStep(); break;
        case 5: *reinterpret_cast< int*>(_v) = pageStepCount(); break;
        case 6: *reinterpret_cast< bool*>(_v) = stepAlignment(); break;
        case 7: *reinterpret_cast< bool*>(_v) = isTracking(); break;
        case 8: *reinterpret_cast< bool*>(_v) = wrapping(); break;
        case 9: *reinterpret_cast< bool*>(_v) = isInverted(); break;
        case 10: *reinterpret_cast< double*>(_v) = mass(); break;
        case 11: *reinterpret_cast< int*>(_v) = updateInterval(); break;
        case 12: *reinterpret_cast< double*>(_v) = totalAngle(); break;
        case 13: *reinterpret_cast< double*>(_v) = viewAngle(); break;
        case 14: *reinterpret_cast< int*>(_v) = tickCount(); break;
        case 15: *reinterpret_cast< int*>(_v) = wheelWidth(); break;
        case 16: *reinterpret_cast< int*>(_v) = borderWidth(); break;
        case 17: *reinterpret_cast< int*>(_v) = wheelBorderWidth(); break;
        }
        _id -= 18;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setOrientation(*reinterpret_cast< Qt::Orientation*>(_v)); break;
        case 1: setValue(*reinterpret_cast< double*>(_v)); break;
        case 2: setMinimum(*reinterpret_cast< double*>(_v)); break;
        case 3: setMaximum(*reinterpret_cast< double*>(_v)); break;
        case 4: setSingleStep(*reinterpret_cast< double*>(_v)); break;
        case 5: setPageStepCount(*reinterpret_cast< int*>(_v)); break;
        case 6: setStepAlignment(*reinterpret_cast< bool*>(_v)); break;
        case 7: setTracking(*reinterpret_cast< bool*>(_v)); break;
        case 8: setWrapping(*reinterpret_cast< bool*>(_v)); break;
        case 9: setInverted(*reinterpret_cast< bool*>(_v)); break;
        case 10: setMass(*reinterpret_cast< double*>(_v)); break;
        case 11: setUpdateInterval(*reinterpret_cast< int*>(_v)); break;
        case 12: setTotalAngle(*reinterpret_cast< double*>(_v)); break;
        case 13: setViewAngle(*reinterpret_cast< double*>(_v)); break;
        case 14: setTickCount(*reinterpret_cast< int*>(_v)); break;
        case 15: setWheelWidth(*reinterpret_cast< int*>(_v)); break;
        case 16: setBorderWidth(*reinterpret_cast< int*>(_v)); break;
        case 17: setWheelBorderWidth(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 18;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 18;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QwtWheel::valueChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwtWheel::wheelPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QwtWheel::wheelReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QwtWheel::wheelMoved(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
