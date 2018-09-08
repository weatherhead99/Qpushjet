#pragma once
#include <QObject>
#include <QVariantMap>

class QDBusInterface;

class desktop_notifier : public QObject
{
    Q_OBJECT

public:
    desktop_notifier();
    ~desktop_notifier();
    unsigned send_freedesktop_notification(const QString& app_name, quint32 replaces_id, const QString& icon,
                                           const QString& summary, const QString& body, const QStringList& actions=QStringList(),
                                           const QVariantMap& hints=QVariantMap(), qint32 expire_timeout=-1);
    
public slots:
    void send_test_notify();
    
private:
    QDBusInterface* _interface;
};
