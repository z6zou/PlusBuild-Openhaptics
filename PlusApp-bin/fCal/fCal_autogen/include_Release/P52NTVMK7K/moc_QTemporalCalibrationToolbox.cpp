/****************************************************************************
** Meta object code from reading C++ file 'QTemporalCalibrationToolbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../PlusApp/fCal/Toolboxes/QTemporalCalibrationToolbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTemporalCalibrationToolbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QTemporalCalibrationToolbox_t {
    QByteArrayData data[16];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTemporalCalibrationToolbox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTemporalCalibrationToolbox_t qt_meta_stringdata_QTemporalCalibrationToolbox = {
    {
QT_MOC_LITERAL(0, 0, 27), // "QTemporalCalibrationToolbox"
QT_MOC_LITERAL(1, 28, 15), // "StartDelayTimer"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 12), // "DelayStartup"
QT_MOC_LITERAL(4, 58, 13), // "DoCalibration"
QT_MOC_LITERAL(5, 72, 16), // "ShowPlotsToggled"
QT_MOC_LITERAL(6, 89, 3), // "aOn"
QT_MOC_LITERAL(7, 93, 16), // "StartCalibration"
QT_MOC_LITERAL(8, 110, 17), // "CancelCalibration"
QT_MOC_LITERAL(9, 128, 25), // "ComputeCalibrationResults"
QT_MOC_LITERAL(10, 154, 18), // "FixedSignalChanged"
QT_MOC_LITERAL(11, 173, 8), // "newIndex"
QT_MOC_LITERAL(12, 182, 19), // "MovingSignalChanged"
QT_MOC_LITERAL(13, 202, 18), // "FixedSourceChanged"
QT_MOC_LITERAL(14, 221, 19), // "MovingSourceChanged"
QT_MOC_LITERAL(15, 241, 20) // "OnSavePlotsRequested"

    },
    "QTemporalCalibrationToolbox\0StartDelayTimer\0"
    "\0DelayStartup\0DoCalibration\0"
    "ShowPlotsToggled\0aOn\0StartCalibration\0"
    "CancelCalibration\0ComputeCalibrationResults\0"
    "FixedSignalChanged\0newIndex\0"
    "MovingSignalChanged\0FixedSourceChanged\0"
    "MovingSourceChanged\0OnSavePlotsRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTemporalCalibrationToolbox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x09 /* Protected */,
       3,    0,   75,    2, 0x09 /* Protected */,
       4,    0,   76,    2, 0x09 /* Protected */,
       5,    1,   77,    2, 0x09 /* Protected */,
       7,    0,   80,    2, 0x09 /* Protected */,
       8,    0,   81,    2, 0x09 /* Protected */,
       9,    0,   82,    2, 0x09 /* Protected */,
      10,    1,   83,    2, 0x09 /* Protected */,
      12,    1,   86,    2, 0x09 /* Protected */,
      13,    1,   89,    2, 0x09 /* Protected */,
      14,    1,   92,    2, 0x09 /* Protected */,
      15,    0,   95,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

void QTemporalCalibrationToolbox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTemporalCalibrationToolbox *_t = static_cast<QTemporalCalibrationToolbox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->StartDelayTimer(); break;
        case 1: _t->DelayStartup(); break;
        case 2: _t->DoCalibration(); break;
        case 3: _t->ShowPlotsToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->StartCalibration(); break;
        case 5: _t->CancelCalibration(); break;
        case 6: _t->ComputeCalibrationResults(); break;
        case 7: _t->FixedSignalChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->MovingSignalChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->FixedSourceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->MovingSourceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->OnSavePlotsRequested(); break;
        default: ;
        }
    }
}

const QMetaObject QTemporalCalibrationToolbox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QTemporalCalibrationToolbox.data,
      qt_meta_data_QTemporalCalibrationToolbox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QTemporalCalibrationToolbox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTemporalCalibrationToolbox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QTemporalCalibrationToolbox.stringdata0))
        return static_cast<void*>(const_cast< QTemporalCalibrationToolbox*>(this));
    if (!strcmp(_clname, "QAbstractToolbox"))
        return static_cast< QAbstractToolbox*>(const_cast< QTemporalCalibrationToolbox*>(this));
    return QWidget::qt_metacast(_clname);
}

int QTemporalCalibrationToolbox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
