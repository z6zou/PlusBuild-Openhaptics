/****************************************************************************
** Meta object code from reading C++ file 'vtkQtConnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../vtk/GUISupport/Qt/vtkQtConnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vtkQtConnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_vtkQtConnection_t {
    QByteArrayData data[8];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vtkQtConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vtkQtConnection_t qt_meta_stringdata_vtkQtConnection = {
    {
QT_MOC_LITERAL(0, 0, 15), // "vtkQtConnection"
QT_MOC_LITERAL(1, 16, 11), // "EmitExecute"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "vtkObject*"
QT_MOC_LITERAL(4, 40, 11), // "client_data"
QT_MOC_LITERAL(5, 52, 9), // "call_data"
QT_MOC_LITERAL(6, 62, 11), // "vtkCommand*"
QT_MOC_LITERAL(7, 74, 16) // "deleteConnection"

    },
    "vtkQtConnection\0EmitExecute\0\0vtkObject*\0"
    "client_data\0call_data\0vtkCommand*\0"
    "deleteConnection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vtkQtConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   35,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::ULong, QMetaType::VoidStar, QMetaType::VoidStar, 0x80000000 | 6,    2,    2,    4,    5,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void vtkQtConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vtkQtConnection *_t = static_cast<vtkQtConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EmitExecute((*reinterpret_cast< vtkObject*(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2])),(*reinterpret_cast< void*(*)>(_a[3])),(*reinterpret_cast< void*(*)>(_a[4])),(*reinterpret_cast< vtkCommand*(*)>(_a[5]))); break;
        case 1: _t->deleteConnection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vtkQtConnection::*_t)(vtkObject * , unsigned long , void * , void * , vtkCommand * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vtkQtConnection::EmitExecute)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject vtkQtConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_vtkQtConnection.data,
      qt_meta_data_vtkQtConnection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vtkQtConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vtkQtConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vtkQtConnection.stringdata0))
        return static_cast<void*>(const_cast< vtkQtConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int vtkQtConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void vtkQtConnection::EmitExecute(vtkObject * _t1, unsigned long _t2, void * _t3, void * _t4, vtkCommand * _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
