/****************************************************************************
** Meta object code from reading C++ file 'QPhantomRegistrationToolbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../PlusApp/fCal/Toolboxes/QPhantomRegistrationToolbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QPhantomRegistrationToolbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPhantomRegistrationToolbox_t {
    QByteArrayData data[13];
    char stringdata0[331];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPhantomRegistrationToolbox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPhantomRegistrationToolbox_t qt_meta_stringdata_QPhantomRegistrationToolbox = {
    {
QT_MOC_LITERAL(0, 0, 27), // "QPhantomRegistrationToolbox"
QT_MOC_LITERAL(1, 28, 21), // "OpenStylusCalibration"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 11), // "RecordPoint"
QT_MOC_LITERAL(4, 63, 4), // "Undo"
QT_MOC_LITERAL(5, 68, 5), // "Reset"
QT_MOC_LITERAL(6, 74, 29), // "StartLinearObjectRegistration"
QT_MOC_LITERAL(7, 104, 28), // "StopLinearObjectRegistration"
QT_MOC_LITERAL(8, 133, 29), // "ResetLinearObjectRegistration"
QT_MOC_LITERAL(9, 163, 34), // "StartLandmarkDetectionRegistr..."
QT_MOC_LITERAL(10, 198, 32), // "StopLandmarkPivotingRegistration"
QT_MOC_LITERAL(11, 231, 47), // "AddStylusTipTransformToLinear..."
QT_MOC_LITERAL(12, 279, 51) // "AddStylusTipTransformToLandma..."

    },
    "QPhantomRegistrationToolbox\0"
    "OpenStylusCalibration\0\0RecordPoint\0"
    "Undo\0Reset\0StartLinearObjectRegistration\0"
    "StopLinearObjectRegistration\0"
    "ResetLinearObjectRegistration\0"
    "StartLandmarkDetectionRegistration\0"
    "StopLandmarkPivotingRegistration\0"
    "AddStylusTipTransformToLinearObjectRegistration\0"
    "AddStylusTipTransformToLandmarkPivotingRegistration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPhantomRegistrationToolbox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x09 /* Protected */,
       3,    0,   70,    2, 0x09 /* Protected */,
       4,    0,   71,    2, 0x09 /* Protected */,
       5,    0,   72,    2, 0x09 /* Protected */,
       6,    0,   73,    2, 0x09 /* Protected */,
       7,    0,   74,    2, 0x09 /* Protected */,
       8,    0,   75,    2, 0x09 /* Protected */,
       9,    0,   76,    2, 0x09 /* Protected */,
      10,    0,   77,    2, 0x09 /* Protected */,
      11,    0,   78,    2, 0x09 /* Protected */,
      12,    0,   79,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QPhantomRegistrationToolbox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QPhantomRegistrationToolbox *_t = static_cast<QPhantomRegistrationToolbox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OpenStylusCalibration(); break;
        case 1: _t->RecordPoint(); break;
        case 2: _t->Undo(); break;
        case 3: _t->Reset(); break;
        case 4: _t->StartLinearObjectRegistration(); break;
        case 5: _t->StopLinearObjectRegistration(); break;
        case 6: _t->ResetLinearObjectRegistration(); break;
        case 7: _t->StartLandmarkDetectionRegistration(); break;
        case 8: _t->StopLandmarkPivotingRegistration(); break;
        case 9: _t->AddStylusTipTransformToLinearObjectRegistration(); break;
        case 10: _t->AddStylusTipTransformToLandmarkPivotingRegistration(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QPhantomRegistrationToolbox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QPhantomRegistrationToolbox.data,
      qt_meta_data_QPhantomRegistrationToolbox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QPhantomRegistrationToolbox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPhantomRegistrationToolbox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QPhantomRegistrationToolbox.stringdata0))
        return static_cast<void*>(const_cast< QPhantomRegistrationToolbox*>(this));
    if (!strcmp(_clname, "QAbstractToolbox"))
        return static_cast< QAbstractToolbox*>(const_cast< QPhantomRegistrationToolbox*>(this));
    return QWidget::qt_metacast(_clname);
}

int QPhantomRegistrationToolbox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
