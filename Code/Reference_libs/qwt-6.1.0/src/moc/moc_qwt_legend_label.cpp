/****************************************************************************
** Meta object code from reading C++ file 'qwt_legend_label.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwt_legend_label.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_legend_label.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtLegendLabel_t {
    QByteArrayData data[8];
    char stringdata[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QwtLegendLabel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QwtLegendLabel_t qt_meta_stringdata_QwtLegendLabel = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 7),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 7),
QT_MOC_LITERAL(4, 32, 8),
QT_MOC_LITERAL(5, 41, 7),
QT_MOC_LITERAL(6, 49, 10),
QT_MOC_LITERAL(7, 60, 2)
    },
    "QwtLegendLabel\0clicked\0\0pressed\0"
    "released\0checked\0setChecked\0on\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtLegendLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x05,
       3,    0,   40,    2, 0x05,
       4,    0,   41,    2, 0x05,
       5,    1,   42,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    1,   45,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void QwtLegendLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QwtLegendLabel *_t = static_cast<QwtLegendLabel *>(_o);
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->pressed(); break;
        case 2: _t->released(); break;
        case 3: _t->checked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QwtLegendLabel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtLegendLabel::clicked)) {
                *result = 0;
            }
        }
        {
            typedef void (QwtLegendLabel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtLegendLabel::pressed)) {
                *result = 1;
            }
        }
        {
            typedef void (QwtLegendLabel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtLegendLabel::released)) {
                *result = 2;
            }
        }
        {
            typedef void (QwtLegendLabel::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtLegendLabel::checked)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject QwtLegendLabel::staticMetaObject = {
    { &QwtTextLabel::staticMetaObject, qt_meta_stringdata_QwtLegendLabel.data,
      qt_meta_data_QwtLegendLabel,  qt_static_metacall, 0, 0}
};


const QMetaObject *QwtLegendLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtLegendLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtLegendLabel.stringdata))
        return static_cast<void*>(const_cast< QwtLegendLabel*>(this));
    return QwtTextLabel::qt_metacast(_clname);
}

int QwtLegendLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtTextLabel::qt_metacall(_c, _id, _a);
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
void QwtLegendLabel::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QwtLegendLabel::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QwtLegendLabel::released()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QwtLegendLabel::checked(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
