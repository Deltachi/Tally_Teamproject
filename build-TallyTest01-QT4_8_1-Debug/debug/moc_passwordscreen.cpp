/****************************************************************************
** Meta object code from reading C++ file 'passwordscreen.h'
**
** Created: Wed 6. May 17:22:21 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TallyOnRaspberry/passwordscreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'passwordscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_passwordscreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      42,   15,   15,   15, 0x08,
      68,   15,   15,   15, 0x08,
      94,   15,   15,   15, 0x08,
     120,   15,   15,   15, 0x08,
     146,   15,   15,   15, 0x08,
     172,   15,   15,   15, 0x08,
     198,   15,   15,   15, 0x08,
     224,   15,   15,   15, 0x08,
     250,   15,   15,   15, 0x08,
     279,   15,   15,   15, 0x08,
     305,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_passwordscreen[] = {
    "passwordscreen\0\0on_pushButton_1_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_back_clicked()\0"
    "on_pushButton_0_clicked()\0"
    "on_pushButton_login_clicked()\0"
};

void passwordscreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        passwordscreen *_t = static_cast<passwordscreen *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_1_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: _t->on_pushButton_5_clicked(); break;
        case 5: _t->on_pushButton_6_clicked(); break;
        case 6: _t->on_pushButton_7_clicked(); break;
        case 7: _t->on_pushButton_8_clicked(); break;
        case 8: _t->on_pushButton_9_clicked(); break;
        case 9: _t->on_pushButton_back_clicked(); break;
        case 10: _t->on_pushButton_0_clicked(); break;
        case 11: _t->on_pushButton_login_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData passwordscreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject passwordscreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_passwordscreen,
      qt_meta_data_passwordscreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &passwordscreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *passwordscreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *passwordscreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_passwordscreen))
        return static_cast<void*>(const_cast< passwordscreen*>(this));
    return QWidget::qt_metacast(_clname);
}

int passwordscreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
