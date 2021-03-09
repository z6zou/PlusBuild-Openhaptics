/****************************************************************************
** Meta object code from reading C++ file 'QPlusDeviceSetSelectorWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../PlusLib/src/PlusWidgets/QPlusDeviceSetSelectorWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QPlusDeviceSetSelectorWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPlusDeviceSetSelectorWidget_t {
    QByteArrayData data[16];
    char stringdata0[302];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPlusDeviceSetSelectorWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPlusDeviceSetSelectorWidget_t qt_meta_stringdata_QPlusDeviceSetSelectorWidget = {
    {
QT_MOC_LITERAL(0, 0, 28), // "QPlusDeviceSetSelectorWidget"
QT_MOC_LITERAL(1, 29, 29), // "ConfigurationDirectoryChanged"
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 11), // "std::string"
QT_MOC_LITERAL(4, 72, 17), // "DeviceSetSelected"
QT_MOC_LITERAL(5, 90, 35), // "ConnectToDevicesByConfigFileI..."
QT_MOC_LITERAL(6, 126, 12), // "ResetTracker"
QT_MOC_LITERAL(7, 139, 26), // "OpenConfigurationDirectory"
QT_MOC_LITERAL(8, 166, 13), // "InvokeConnect"
QT_MOC_LITERAL(9, 180, 16), // "InvokeDisconnect"
QT_MOC_LITERAL(10, 197, 13), // "RefreshFolder"
QT_MOC_LITERAL(11, 211, 17), // "EditConfiguration"
QT_MOC_LITERAL(12, 229, 19), // "ShowEditContextMenu"
QT_MOC_LITERAL(13, 249, 12), // "SelectEditor"
QT_MOC_LITERAL(14, 262, 13), // "EditAppConfig"
QT_MOC_LITERAL(15, 276, 25) // "ResetTrackerButtonClicked"

    },
    "QPlusDeviceSetSelectorWidget\0"
    "ConfigurationDirectoryChanged\0\0"
    "std::string\0DeviceSetSelected\0"
    "ConnectToDevicesByConfigFileInvoked\0"
    "ResetTracker\0OpenConfigurationDirectory\0"
    "InvokeConnect\0InvokeDisconnect\0"
    "RefreshFolder\0EditConfiguration\0"
    "ShowEditContextMenu\0SelectEditor\0"
    "EditAppConfig\0ResetTrackerButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPlusDeviceSetSelectorWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    1,   90,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   94,    2, 0x09 /* Protected */,
       4,    1,   95,    2, 0x09 /* Protected */,
       8,    0,   98,    2, 0x09 /* Protected */,
       9,    0,   99,    2, 0x09 /* Protected */,
      10,    0,  100,    2, 0x09 /* Protected */,
      11,    0,  101,    2, 0x09 /* Protected */,
      12,    1,  102,    2, 0x09 /* Protected */,
      13,    0,  105,    2, 0x09 /* Protected */,
      14,    0,  106,    2, 0x09 /* Protected */,
      15,    0,  107,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QPlusDeviceSetSelectorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QPlusDeviceSetSelectorWidget *_t = static_cast<QPlusDeviceSetSelectorWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ConfigurationDirectoryChanged((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->DeviceSetSelected((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->ConnectToDevicesByConfigFileInvoked((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->ResetTracker(); break;
        case 4: _t->OpenConfigurationDirectory(); break;
        case 5: _t->DeviceSetSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->InvokeConnect(); break;
        case 7: _t->InvokeDisconnect(); break;
        case 8: _t->RefreshFolder(); break;
        case 9: _t->EditConfiguration(); break;
        case 10: _t->ShowEditContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 11: _t->SelectEditor(); break;
        case 12: _t->EditAppConfig(); break;
        case 13: _t->ResetTrackerButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QPlusDeviceSetSelectorWidget::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QPlusDeviceSetSelectorWidget::ConfigurationDirectoryChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QPlusDeviceSetSelectorWidget::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QPlusDeviceSetSelectorWidget::DeviceSetSelected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QPlusDeviceSetSelectorWidget::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QPlusDeviceSetSelectorWidget::ConnectToDevicesByConfigFileInvoked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QPlusDeviceSetSelectorWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QPlusDeviceSetSelectorWidget::ResetTracker)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject QPlusDeviceSetSelectorWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QPlusDeviceSetSelectorWidget.data,
      qt_meta_data_QPlusDeviceSetSelectorWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QPlusDeviceSetSelectorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlusDeviceSetSelectorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QPlusDeviceSetSelectorWidget.stringdata0))
        return static_cast<void*>(const_cast< QPlusDeviceSetSelectorWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QPlusDeviceSetSelectorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QPlusDeviceSetSelectorWidget::ConfigurationDirectoryChanged(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QPlusDeviceSetSelectorWidget::DeviceSetSelected(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QPlusDeviceSetSelectorWidget::ConnectToDevicesByConfigFileInvoked(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QPlusDeviceSetSelectorWidget::ResetTracker()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
