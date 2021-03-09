/****************************************************************************
** Meta object code from reading C++ file 'PlusCaptureControlWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../PlusApp/fCal/PlusCaptureControlWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlusCaptureControlWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PlusCaptureControlWidget_t {
    QByteArrayData data[11];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlusCaptureControlWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlusCaptureControlWidget_t qt_meta_stringdata_PlusCaptureControlWidget = {
    {
QT_MOC_LITERAL(0, 0, 24), // "PlusCaptureControlWidget"
QT_MOC_LITERAL(1, 25, 17), // "EmitStatusMessage"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 11), // "std::string"
QT_MOC_LITERAL(4, 56, 12), // "TakeSnapshot"
QT_MOC_LITERAL(5, 69, 22), // "StartStopButtonPressed"
QT_MOC_LITERAL(6, 92, 17), // "SaveButtonPressed"
QT_MOC_LITERAL(7, 110, 19), // "SaveAsButtonPressed"
QT_MOC_LITERAL(8, 130, 19), // "SamplingRateChanged"
QT_MOC_LITERAL(9, 150, 6), // "aValue"
QT_MOC_LITERAL(10, 157, 18) // "ClearButtonPressed"

    },
    "PlusCaptureControlWidget\0EmitStatusMessage\0"
    "\0std::string\0TakeSnapshot\0"
    "StartStopButtonPressed\0SaveButtonPressed\0"
    "SaveAsButtonPressed\0SamplingRateChanged\0"
    "aValue\0ClearButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlusCaptureControlWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x09 /* Protected */,
       5,    0,   53,    2, 0x09 /* Protected */,
       6,    0,   54,    2, 0x09 /* Protected */,
       7,    0,   55,    2, 0x09 /* Protected */,
       8,    1,   56,    2, 0x09 /* Protected */,
      10,    0,   59,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void PlusCaptureControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlusCaptureControlWidget *_t = static_cast<PlusCaptureControlWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EmitStatusMessage((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 1: _t->TakeSnapshot(); break;
        case 2: _t->StartStopButtonPressed(); break;
        case 3: _t->SaveButtonPressed(); break;
        case 4: _t->SaveAsButtonPressed(); break;
        case 5: _t->SamplingRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->ClearButtonPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PlusCaptureControlWidget::*_t)(const std::string & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlusCaptureControlWidget::EmitStatusMessage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PlusCaptureControlWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlusCaptureControlWidget.data,
      qt_meta_data_PlusCaptureControlWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlusCaptureControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlusCaptureControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlusCaptureControlWidget.stringdata0))
        return static_cast<void*>(const_cast< PlusCaptureControlWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlusCaptureControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PlusCaptureControlWidget::EmitStatusMessage(const std::string & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
