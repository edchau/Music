/****************************************************************************
** Meta object code from reading C++ file 'musicengine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "musicengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_musicEngine_t {
    QByteArrayData data[32];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_musicEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_musicEngine_t qt_meta_stringdata_musicEngine = {
    {
QT_MOC_LITERAL(0, 0, 11), // "musicEngine"
QT_MOC_LITERAL(1, 12, 10), // "currVolume"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "volume"
QT_MOC_LITERAL(4, 31, 8), // "songData"
QT_MOC_LITERAL(5, 40, 6), // "size_t"
QT_MOC_LITERAL(6, 47, 4), // "time"
QT_MOC_LITERAL(7, 52, 12), // "songFinished"
QT_MOC_LITERAL(8, 65, 18), // "currPositionInSong"
QT_MOC_LITERAL(9, 84, 4), // "play"
QT_MOC_LITERAL(10, 89, 7), // "unpause"
QT_MOC_LITERAL(11, 97, 4), // "loop"
QT_MOC_LITERAL(12, 102, 3), // "yes"
QT_MOC_LITERAL(13, 106, 5), // "pause"
QT_MOC_LITERAL(14, 112, 4), // "stop"
QT_MOC_LITERAL(15, 117, 11), // "fastForward"
QT_MOC_LITERAL(16, 129, 6), // "rewind"
QT_MOC_LITERAL(17, 136, 7), // "restart"
QT_MOC_LITERAL(18, 144, 9), // "setDevice"
QT_MOC_LITERAL(19, 154, 12), // "deviceNumber"
QT_MOC_LITERAL(20, 167, 9), // "setVolume"
QT_MOC_LITERAL(21, 177, 3), // "vol"
QT_MOC_LITERAL(22, 181, 16), // "setPlayingOffset"
QT_MOC_LITERAL(23, 198, 10), // "timeOffset"
QT_MOC_LITERAL(24, 209, 13), // "setWhatToPlay"
QT_MOC_LITERAL(25, 223, 6), // "string"
QT_MOC_LITERAL(26, 230, 10), // "whatToPlay"
QT_MOC_LITERAL(27, 241, 10), // "setBalance"
QT_MOC_LITERAL(28, 252, 3), // "pan"
QT_MOC_LITERAL(29, 256, 9), // "onTimeOut"
QT_MOC_LITERAL(30, 266, 14), // "onSoundStopped"
QT_MOC_LITERAL(31, 281, 10) // "posChanged"

    },
    "musicEngine\0currVolume\0\0volume\0songData\0"
    "size_t\0time\0songFinished\0currPositionInSong\0"
    "play\0unpause\0loop\0yes\0pause\0stop\0"
    "fastForward\0rewind\0restart\0setDevice\0"
    "deviceNumber\0setVolume\0vol\0setPlayingOffset\0"
    "timeOffset\0setWhatToPlay\0string\0"
    "whatToPlay\0setBalance\0pan\0onTimeOut\0"
    "onSoundStopped\0posChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_musicEngine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       4,    2,  117,    2, 0x06 /* Public */,
       7,    0,  122,    2, 0x06 /* Public */,
       8,    1,  123,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  126,    2, 0x0a /* Public */,
      10,    0,  127,    2, 0x0a /* Public */,
      11,    1,  128,    2, 0x0a /* Public */,
      13,    0,  131,    2, 0x0a /* Public */,
      14,    0,  132,    2, 0x0a /* Public */,
      15,    0,  133,    2, 0x0a /* Public */,
      16,    0,  134,    2, 0x0a /* Public */,
      17,    0,  135,    2, 0x0a /* Public */,
      18,    1,  136,    2, 0x0a /* Public */,
      20,    1,  139,    2, 0x0a /* Public */,
      22,    1,  142,    2, 0x0a /* Public */,
      24,    1,  145,    2, 0x0a /* Public */,
      27,    1,  148,    2, 0x0a /* Public */,
      29,    0,  151,    2, 0x0a /* Public */,
      30,    0,  152,    2, 0x0a /* Public */,
      31,    1,  153,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    3,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Float,   23,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    6,

       0        // eod
};

void musicEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        musicEngine *_t = static_cast<musicEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currVolume((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->songData((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 2: _t->songFinished(); break;
        case 3: _t->currPositionInSong((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->play(); break;
        case 5: _t->unpause(); break;
        case 6: _t->loop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->pause(); break;
        case 8: _t->stop(); break;
        case 9: _t->fastForward(); break;
        case 10: _t->rewind(); break;
        case 11: _t->restart(); break;
        case 12: _t->setDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setPlayingOffset((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 15: _t->setWhatToPlay((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 16: _t->setBalance((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->onTimeOut(); break;
        case 18: _t->onSoundStopped(); break;
        case 19: _t->posChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (musicEngine::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&musicEngine::currVolume)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (musicEngine::*_t)(size_t , size_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&musicEngine::songData)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (musicEngine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&musicEngine::songFinished)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (musicEngine::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&musicEngine::currPositionInSong)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject musicEngine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_musicEngine.data,
      qt_meta_data_musicEngine,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *musicEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *musicEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_musicEngine.stringdata0))
        return static_cast<void*>(const_cast< musicEngine*>(this));
    return QWidget::qt_metacast(_clname);
}

int musicEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void musicEngine::currVolume(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void musicEngine::songData(size_t _t1, size_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void musicEngine::songFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void musicEngine::currPositionInSong(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
