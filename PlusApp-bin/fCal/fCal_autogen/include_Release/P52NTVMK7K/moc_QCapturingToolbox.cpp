/****************************************************************************
** Meta object code from reading C++ file 'QCapturingToolbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../PlusApp/fCal/Toolboxes/QCapturingToolbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QCapturingToolbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QCapturingToolbox_t {
    QByteArrayData data[17];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCapturingToolbox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCapturingToolbox_t qt_meta_stringdata_QCapturingToolbox = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QCapturingToolbox"
QT_MOC_LITERAL(1, 18, 12), // "TakeSnapshot"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "Record"
QT_MOC_LITERAL(4, 39, 4), // "Stop"
QT_MOC_LITERAL(5, 44, 19), // "ClearRecordedFrames"
QT_MOC_LITERAL(6, 64, 8), // "ClearAll"
QT_MOC_LITERAL(7, 73, 12), // "StartStopAll"
QT_MOC_LITERAL(8, 86, 4), // "Save"
QT_MOC_LITERAL(9, 91, 6), // "SaveAs"
QT_MOC_LITERAL(10, 98, 7), // "SaveAll"
QT_MOC_LITERAL(11, 106, 19), // "SamplingRateChanged"
QT_MOC_LITERAL(12, 126, 6), // "aValue"
QT_MOC_LITERAL(13, 133, 7), // "Capture"
QT_MOC_LITERAL(14, 141, 19), // "HandleStatusMessage"
QT_MOC_LITERAL(15, 161, 11), // "std::string"
QT_MOC_LITERAL(16, 173, 8) // "aMessage"

    },
    "QCapturingToolbox\0TakeSnapshot\0\0Record\0"
    "Stop\0ClearRecordedFrames\0ClearAll\0"
    "StartStopAll\0Save\0SaveAs\0SaveAll\0"
    "SamplingRateChanged\0aValue\0Capture\0"
    "HandleStatusMessage\0std::string\0"
    "aMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCapturingToolbox[] = {

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
       5,    0,   77,    2, 0x09 /* Protected */,
       6,    0,   78,    2, 0x09 /* Protected */,
       7,    0,   79,    2, 0x09 /* Protected */,
       8,    0,   80,    2, 0x09 /* Protected */,
       9,    0,   81,    2, 0x09 /* Protected */,
      10,    0,   82,    2, 0x09 /* Protected */,
      11,    1,   83,    2, 0x09 /* Protected */,
      13,    0,   86,    2, 0x09 /* Protected */,
      14,    1,   87,    2, 0x09 /* Protected */,

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
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void QCapturingToolbox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QCapturingToolbox *_t = static_cast<QCapturingToolbox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TakeSnapshot(); break;
        case 1: _t->Record(); break;
        case 2: _t->Stop(); break;
        case 3: _t->ClearRecordedFrames(); break;
        case 4: _t->ClearAll(); break;
        case 5: _t->StartStopAll(); break;
        case 6: _t->Save(); break;
        case 7: _t->SaveAs(); break;
        case 8: _t->SaveAll(); break;
        case 9: _t->SamplingRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->Capture(); break;
        case 11: _t->HandleStatusMessage((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QCapturingToolbox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QCapturingToolbox.data,
      qt_meta_data_QCapturingToolbox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QCapturingToolbox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCapturingToolbox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QCapturingToolbox.stringdata0))
        return static_cast<void*>(const_cast< QCapturingToolbox*>(this));
    if (!strcmp(_clname, "QAbstractToolbox"))
        return static_cast< QAbstractToolbox*>(const_cast< QCapturingToolbox*>(this));
    return QWidget::qt_metacast(_clname);
}

int QCapturingToolbox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
