#pragma once

#include <QUuid>
#include <QUrl>
#include <QObject>
#include <QJsonDocument>
#include "pushjet_types.h"

class QString;
class QSslSocket;

struct pushjet_message
{
    QString title;
    QString message;
    QUrl link;
    unsigned short level;
};


class pushjet_api : public QObject
{
    
    Q_OBJECT
    
public:
    pushjet_api(const QUuid& device_uuid, const QUrl& server_url);
    virtual ~pushjet_api();
    
    virtual void subscribe(const QString& pubkey) = 0;
    virtual void unsubscribe(const QString& pubkey) =0;
    
    virtual void connect() = 0;

signals:
    void newMessageReceived(const QString& title, const QString& message, 
                            const QUrl& link, unsigned short level);
    
protected:
    QUuid _device_uuid;
    QUrl _server_url;
    bool _connected = false;
    
private:
};


class pushjet_TCP : public pushjet_api 
{
    Q_OBJECT
    
public:
    pushjet_TCP(const QUuid& device_uuid, const QUrl& server_url, unsigned port);
    virtual ~pushjet_TCP() final;
    
    void subscribe(const QString & pubkey) final;
    void unsubscribe(const QString & pubkey) final;
    
    void connect() final;
    
private:
    QSslSocket* _socket;
    unsigned int _port;
    
    
};


QJsonDocument create_subscription_request(const QUuid& device_uuid, const QString& pubkey);
pushjet_service parse_subscription_response(const QJsonDocument& doc);

