#include "notifications.h"
#include <QtDBus/QDBusConnection>
#include <QDBusInterface>
#include <QDebug>
#include <QApplication>

desktop_notifier::desktop_notifier()
{
    
    if(!QDBusConnection::sessionBus().isConnected())
    {
        qDebug() << "couldn't connect to session bus!";
    };
        
    _interface = new QDBusInterface("org.freedesktop.Notifications","/org/freedesktop/Notifications",
                                    "org.freedesktop.Notifications",QDBusConnection::sessionBus());
    
    if(!_interface->isValid())
    {
        qDebug() << "invalid dbus interface!";
    }
    
    else
    {
        qDebug() << "successfully connected to DBus service";
    }
    
}

desktop_notifier::~desktop_notifier()
{
    if(_interface)
        delete _interface;
}

unsigned int desktop_notifier::send_freedesktop_notification(const QString& app_name, quint32 replaces_id, const QString& icon, const QString& summary, const QString& body, const QStringList& actions, const QVariantMap& hints, qint32 expire_timeout)
{
    auto repl = _interface->call("Notify", app_name, replaces_id, icon, summary, body, actions, hints, expire_timeout);
    
    if(repl.errorName().size() > 0)
    {
        qDebug() << "dbus error: " << _interface->lastError();
        return 0;
    };
    
    return repl.arguments().at(0).toUInt();
}


void desktop_notifier::send_test_notify()
{
    qDebug() << "sending test notification via DBus";
    auto app_name = QApplication::applicationName();
    
    send_freedesktop_notification(app_name,0,"","test summary", "test body");
    
}
