/****************************************************************************
** Meta object code from reading C++ file 'accumonitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../source/accumonitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accumonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AccuMonitor_t {
    QByteArrayData data[20];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AccuMonitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AccuMonitor_t qt_meta_stringdata_AccuMonitor = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AccuMonitor"
QT_MOC_LITERAL(1, 12, 11), // "portChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 17), // "enableEchoChanged"
QT_MOC_LITERAL(4, 43, 18), // "consoleDataChanged"
QT_MOC_LITERAL(5, 62, 8), // "readData"
QT_MOC_LITERAL(6, 71, 14), // "consoleConnect"
QT_MOC_LITERAL(7, 86, 17), // "consoleDisconnect"
QT_MOC_LITERAL(8, 104, 3), // "foo"
QT_MOC_LITERAL(9, 108, 12), // "writeConsole"
QT_MOC_LITERAL(10, 121, 4), // "data"
QT_MOC_LITERAL(11, 126, 17), // "updateSettingInfo"
QT_MOC_LITERAL(12, 144, 4), // "port"
QT_MOC_LITERAL(13, 149, 8), // "baudRate"
QT_MOC_LITERAL(14, 158, 8), // "dataBits"
QT_MOC_LITERAL(15, 167, 6), // "parity"
QT_MOC_LITERAL(16, 174, 8), // "stopBits"
QT_MOC_LITERAL(17, 183, 11), // "flowControl"
QT_MOC_LITERAL(18, 195, 10), // "enableEcho"
QT_MOC_LITERAL(19, 206, 11) // "consoleData"

    },
    "AccuMonitor\0portChanged\0\0enableEchoChanged\0"
    "consoleDataChanged\0readData\0consoleConnect\0"
    "consoleDisconnect\0foo\0writeConsole\0"
    "data\0updateSettingInfo\0port\0baudRate\0"
    "dataBits\0parity\0stopBits\0flowControl\0"
    "enableEcho\0consoleData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccuMonitor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       8,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    0,   63,    2, 0x02 /* Public */,
       7,    0,   64,    2, 0x02 /* Public */,
       8,    0,   65,    2, 0x02 /* Public */,
       9,    1,   66,    2, 0x02 /* Public */,
      11,    0,   69,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00095103,
      14, QMetaType::QString, 0x00095103,
      15, QMetaType::Int, 0x00095103,
      16, QMetaType::QString, 0x00095103,
      17, QMetaType::Int, 0x00095103,
      18, QMetaType::Bool, 0x00495103,
      19, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       1,
       2,

       0        // eod
};

void AccuMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AccuMonitor *_t = static_cast<AccuMonitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->portChanged(); break;
        case 1: _t->enableEchoChanged(); break;
        case 2: _t->consoleDataChanged(); break;
        case 3: _t->readData(); break;
        case 4: { bool _r = _t->consoleConnect();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->consoleDisconnect(); break;
        case 6: _t->foo(); break;
        case 7: _t->writeConsole((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->updateSettingInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AccuMonitor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AccuMonitor::portChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AccuMonitor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AccuMonitor::enableEchoChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AccuMonitor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AccuMonitor::consoleDataChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        AccuMonitor *_t = static_cast<AccuMonitor *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getPort(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getBaudRate(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getDataBits(); break;
        case 3: *reinterpret_cast< qint32*>(_v) = _t->getParity(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getStopBits(); break;
        case 5: *reinterpret_cast< qint32*>(_v) = _t->getFlowControl(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->getEnableEcho(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->getConsoleData(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        AccuMonitor *_t = static_cast<AccuMonitor *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPort(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setBaudRate(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setDataBits(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setParity(*reinterpret_cast< qint32*>(_v)); break;
        case 4: _t->setStopBits(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setFlowControl(*reinterpret_cast< qint32*>(_v)); break;
        case 6: _t->setEnableEcho(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setConsoleData(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject AccuMonitor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AccuMonitor.data,
      qt_meta_data_AccuMonitor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AccuMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccuMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AccuMonitor.stringdata0))
        return static_cast<void*>(const_cast< AccuMonitor*>(this));
    return QObject::qt_metacast(_clname);
}

int AccuMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AccuMonitor::portChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AccuMonitor::enableEchoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AccuMonitor::consoleDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
