/****************************************************************************
** Meta object code from reading C++ file 'qwt_legend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwt_legend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_legend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtLegend_t {
    QByteArrayData data[11];
    char stringdata[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QwtLegend_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QwtLegend_t qt_meta_stringdata_QwtLegend = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 7),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 8),
QT_MOC_LITERAL(4, 28, 5),
QT_MOC_LITERAL(5, 34, 7),
QT_MOC_LITERAL(6, 42, 2),
QT_MOC_LITERAL(7, 45, 12),
QT_MOC_LITERAL(8, 58, 20),
QT_MOC_LITERAL(9, 79, 11),
QT_MOC_LITERAL(10, 91, 11)
    },
    "QwtLegend\0clicked\0\0itemInfo\0index\0"
    "checked\0on\0updateLegend\0QList<QwtLegendData>\0"
    "itemClicked\0itemChecked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtLegend[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x05,
       5,    3,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    2,   51,    2, 0x0a,
       9,    0,   56,    2, 0x09,
      10,    1,   57,    2, 0x09,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QVariant, QMetaType::Bool, QMetaType::Int,    3,    6,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant, 0x80000000 | 8,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void QwtLegend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QwtLegend *_t = static_cast<QwtLegend *>(_o);
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->checked((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->updateLegend((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QList<QwtLegendData>(*)>(_a[2]))); break;
        case 3: _t->itemClicked(); break;
        case 4: _t->itemChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QwtLegend::*_t)(const QVariant & , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtLegend::clicked)) {
                *result = 0;
            }
        }
        {
            typedef void (QwtLegend::*_t)(const QVariant & , bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtLegend::checked)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject QwtLegend::staticMetaObject = {
    { &QwtAbstractLegend::staticMetaObject, qt_meta_stringdata_QwtLegend.data,
      qt_meta_data_QwtLegend,  qt_static_metacall, 0, 0}
};


const QMetaObject *QwtLegend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtLegend::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtLegend.stringdata))
        return static_cast<void*>(const_cast< QwtLegend*>(this));
    return QwtAbstractLegend::qt_metacast(_clname);
}

int QwtLegend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtAbstractLegend::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void QwtLegend::clicked(const QVariant & _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwtLegend::checked(const QVariant & _t1, bool _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
