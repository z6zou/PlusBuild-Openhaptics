/****************************************************************************
** Meta object code from reading C++ file 'QPlusStatusIcon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../PlusLib/src/PlusWidgets/QPlusStatusIcon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QPlusStatusIcon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_vtkDisplayMessageCallback_t {
    QByteArrayData data[3];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vtkDisplayMessageCallback_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vtkDisplayMessageCallback_t qt_meta_stringdata_vtkDisplayMessageCallback = {
    {
QT_MOC_LITERAL(0, 0, 25), // "vtkDisplayMessageCallback"
QT_MOC_LITERAL(1, 26, 10), // "AddMessage"
QT_MOC_LITERAL(2, 37, 0) // ""

    },
    "vtkDisplayMessageCallback\0AddMessage\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vtkDisplayMessageCallback[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void vtkDisplayMessageCallback::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vtkDisplayMessageCallback *_t = static_cast<vtkDisplayMessageCallback *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vtkDisplayMessageCallback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vtkDisplayMessageCallback::AddMessage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject vtkDisplayMessageCallback::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_vtkDisplayMessageCallback.data,
      qt_meta_data_vtkDisplayMessageCallback,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vtkDisplayMessageCallback::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vtkDisplayMessageCallback::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vtkDisplayMessageCallback.stringdata0))
        return static_cast<void*>(const_cast< vtkDisplayMessageCallback*>(this));
    if (!strcmp(_clname, "vtkCallbackCommand"))
        return static_cast< vtkCallbackCommand*>(const_cast< vtkDisplayMessageCallback*>(this));
    return QObject::qt_metacast(_clname);
}

int vtkDisplayMessageCallback::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void vtkDisplayMessageCallback::AddMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QPlusStatusIcon_t {
    QByteArrayData data[10];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPlusStatusIcon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPlusStatusIcon_t qt_meta_stringdata_QPlusStatusIcon = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QPlusStatusIcon"
QT_MOC_LITERAL(1, 16, 23), // "CreateCustomContextMenu"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 6), // "aPoint"
QT_MOC_LITERAL(4, 48, 16), // "ClearMessageList"
QT_MOC_LITERAL(5, 65, 24), // "ClearFilterButtonClicked"
QT_MOC_LITERAL(6, 90, 20), // "FilterLineEditEdited"
QT_MOC_LITERAL(7, 111, 21), // "ApplyFilterTimerFired"
QT_MOC_LITERAL(8, 133, 10), // "AddMessage"
QT_MOC_LITERAL(9, 144, 12) // "aInputString"

    },
    "QPlusStatusIcon\0CreateCustomContextMenu\0"
    "\0aPoint\0ClearMessageList\0"
    "ClearFilterButtonClicked\0FilterLineEditEdited\0"
    "ApplyFilterTimerFired\0AddMessage\0"
    "aInputString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPlusStatusIcon[] = {

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
       1,    1,   44,    2, 0x09 /* Protected */,
       4,    0,   47,    2, 0x09 /* Protected */,
       5,    0,   48,    2, 0x09 /* Protected */,
       6,    1,   49,    2, 0x09 /* Protected */,
       7,    0,   52,    2, 0x09 /* Protected */,
       8,    1,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void QPlusStatusIcon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QPlusStatusIcon *_t = static_cast<QPlusStatusIcon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateCustomContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->ClearMessageList(); break;
        case 2: _t->ClearFilterButtonClicked(); break;
        case 3: _t->FilterLineEditEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->ApplyFilterTimerFired(); break;
        case 5: _t->AddMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QPlusStatusIcon::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QPlusStatusIcon.data,
      qt_meta_data_QPlusStatusIcon,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QPlusStatusIcon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlusStatusIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QPlusStatusIcon.stringdata0))
        return static_cast<void*>(const_cast< QPlusStatusIcon*>(this));
    return QWidget::qt_metacast(_clname);
}

int QPlusStatusIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
