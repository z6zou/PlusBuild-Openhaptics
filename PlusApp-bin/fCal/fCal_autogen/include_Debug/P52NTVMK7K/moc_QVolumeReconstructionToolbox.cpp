/****************************************************************************
** Meta object code from reading C++ file 'QVolumeReconstructionToolbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../PlusApp/fCal/Toolboxes/QVolumeReconstructionToolbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QVolumeReconstructionToolbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QVolumeReconstructionToolbox_t {
    QByteArrayData data[10];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QVolumeReconstructionToolbox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QVolumeReconstructionToolbox_t qt_meta_stringdata_QVolumeReconstructionToolbox = {
    {
QT_MOC_LITERAL(0, 0, 28), // "QVolumeReconstructionToolbox"
QT_MOC_LITERAL(1, 29, 30), // "OpenVolumeReconstructionConfig"
QT_MOC_LITERAL(2, 60, 0), // ""
QT_MOC_LITERAL(3, 61, 17), // "InputImageChanged"
QT_MOC_LITERAL(4, 79, 10), // "aItemIndex"
QT_MOC_LITERAL(5, 90, 14), // "OpenInputImage"
QT_MOC_LITERAL(6, 105, 11), // "Reconstruct"
QT_MOC_LITERAL(7, 117, 4), // "Save"
QT_MOC_LITERAL(8, 122, 39), // "RecomputeContourFromReconstru..."
QT_MOC_LITERAL(9, 162, 6) // "aValue"

    },
    "QVolumeReconstructionToolbox\0"
    "OpenVolumeReconstructionConfig\0\0"
    "InputImageChanged\0aItemIndex\0"
    "OpenInputImage\0Reconstruct\0Save\0"
    "RecomputeContourFromReconstructedVolume\0"
    "aValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QVolumeReconstructionToolbox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x09 /* Protected */,
       3,    1,   45,    2, 0x09 /* Protected */,
       5,    0,   48,    2, 0x09 /* Protected */,
       6,    0,   49,    2, 0x09 /* Protected */,
       7,    0,   50,    2, 0x09 /* Protected */,
       8,    1,   51,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void QVolumeReconstructionToolbox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QVolumeReconstructionToolbox *_t = static_cast<QVolumeReconstructionToolbox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OpenVolumeReconstructionConfig(); break;
        case 1: _t->InputImageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OpenInputImage(); break;
        case 3: _t->Reconstruct(); break;
        case 4: _t->Save(); break;
        case 5: _t->RecomputeContourFromReconstructedVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QVolumeReconstructionToolbox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QVolumeReconstructionToolbox.data,
      qt_meta_data_QVolumeReconstructionToolbox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QVolumeReconstructionToolbox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QVolumeReconstructionToolbox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QVolumeReconstructionToolbox.stringdata0))
        return static_cast<void*>(const_cast< QVolumeReconstructionToolbox*>(this));
    if (!strcmp(_clname, "QAbstractToolbox"))
        return static_cast< QAbstractToolbox*>(const_cast< QVolumeReconstructionToolbox*>(this));
    return QWidget::qt_metacast(_clname);
}

int QVolumeReconstructionToolbox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
