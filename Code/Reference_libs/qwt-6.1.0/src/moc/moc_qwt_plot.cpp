/****************************************************************************
** Meta object code from reading C++ file 'qwt_plot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwt_plot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_plot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtPlot_t {
    QByteArrayData data[15];
    char stringdata[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QwtPlot_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QwtPlot_t qt_meta_stringdata_QwtPlot = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 12),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 12),
QT_MOC_LITERAL(4, 35, 8),
QT_MOC_LITERAL(5, 44, 2),
QT_MOC_LITERAL(6, 47, 17),
QT_MOC_LITERAL(7, 65, 8),
QT_MOC_LITERAL(8, 74, 20),
QT_MOC_LITERAL(9, 95, 4),
QT_MOC_LITERAL(10, 100, 6),
QT_MOC_LITERAL(11, 107, 11),
QT_MOC_LITERAL(12, 119, 17),
QT_MOC_LITERAL(13, 137, 16),
QT_MOC_LITERAL(14, 154, 10)
    },
    "QwtPlot\0itemAttached\0\0QwtPlotItem*\0"
    "plotItem\0on\0legendDataChanged\0itemInfo\0"
    "QList<QwtLegendData>\0data\0replot\0"
    "autoRefresh\0updateLegendItems\0"
    "canvasBackground\0autoReplot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtPlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x05,
       6,    2,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      10,    0,   49,    2, 0x0a,
      11,    0,   50,    2, 0x0a,
      12,    2,   51,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, QMetaType::QVariant, 0x80000000 | 8,    7,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant, 0x80000000 | 8,    7,    9,

 // properties: name, type, flags
      13, QMetaType::QBrush, 0x00095103,
      14, QMetaType::Bool, 0x00095103,

       0        // eod
};

void QwtPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QwtPlot *_t = static_cast<QwtPlot *>(_o);
        switch (_id) {
        case 0: _t->itemAttached((*reinterpret_cast< QwtPlotItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->legendDataChanged((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QList<QwtLegendData>(*)>(_a[2]))); break;
        case 2: _t->replot(); break;
        case 3: _t->autoRefresh(); break;
        case 4: _t->updateLegendItems((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QList<QwtLegendData>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QwtPlotItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QwtPlot::*_t)(QwtPlotItem * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtPlot::itemAttached)) {
                *result = 0;
            }
        }
        {
            typedef void (QwtPlot::*_t)(const QVariant & , const QList<QwtLegendData> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtPlot::legendDataChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject QwtPlot::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_QwtPlot.data,
      qt_meta_data_QwtPlot,  qt_static_metacall, 0, 0}
};


const QMetaObject *QwtPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtPlot.stringdata))
        return static_cast<void*>(const_cast< QwtPlot*>(this));
    if (!strcmp(_clname, "QwtPlotDict"))
        return static_cast< QwtPlotDict*>(const_cast< QwtPlot*>(this));
    return QFrame::qt_metacast(_clname);
}

int QwtPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QBrush*>(_v) = canvasBackground(); break;
        case 1: *reinterpret_cast< bool*>(_v) = autoReplot(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCanvasBackground(*reinterpret_cast< QBrush*>(_v)); break;
        case 1: setAutoReplot(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QwtPlot::itemAttached(QwtPlotItem * _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwtPlot::legendDataChanged(const QVariant & _t1, const QList<QwtLegendData> & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
