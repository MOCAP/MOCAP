/****************************************************************************
** Meta object code from reading C++ file 'qwt_scale_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwt_scale_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_scale_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtScaleWidget_t {
    QByteArrayData data[3];
    char stringdata[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QwtScaleWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QwtScaleWidget_t qt_meta_stringdata_QwtScaleWidget = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 15),
QT_MOC_LITERAL(2, 31, 0)
    },
    "QwtScaleWidget\0scaleDivChanged\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtScaleWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x05,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void QwtScaleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QwtScaleWidget *_t = static_cast<QwtScaleWidget *>(_o);
        switch (_id) {
        case 0: _t->scaleDivChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QwtScaleWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtScaleWidget::scaleDivChanged)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QwtScaleWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwtScaleWidget.data,
      qt_meta_data_QwtScaleWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *QwtScaleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtScaleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtScaleWidget.stringdata))
        return static_cast<void*>(const_cast< QwtScaleWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwtScaleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void QwtScaleWidget::scaleDivChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
