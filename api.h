#pragma once

#include <QUuid>
#include <QUrl>
#include <QObject>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include "pushjet_types.h"

class QString;
class QSslSocket;
class QNetworkReply;

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
    ~pushjet_api();
    
    void subscribe(const QString& pubkey);
    void unsubscribe(const QString& pubkey);
    
    void get_service_info(const QString& pubkey);
    
    void connect();

signals:
    void service_info_received(const pushjet_service&);
    
private slots:
    void process_reply(QNetworkReply* repl);
    
private:
    QNetworkRequest create_subscription_request(const QString& pubkey);
    
    
    QNetworkAccessManager _accessman;
    QUuid _device_uuid;
    QUrl _server_url;
    bool _connected = false;
};



