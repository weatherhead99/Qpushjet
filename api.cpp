#include "api.h"
#include <QSslSocket>
#include <QJsonObject>

pushjet_api::pushjet_api(const QUuid& device_uuid, const QUrl& server_url)
: _device_uuid(device_uuid), _server_url(server_url)
{
}

pushjet_api::~pushjet_api()
{
}

pushjet_TCP::pushjet_TCP(const QUuid& device_uuid, const QUrl& server_url, unsigned int port)
: pushjet_api(device_uuid, server_url), _port(port)
{
    
}

pushjet_TCP::~pushjet_TCP()
{
    if(_socket)
        delete _socket;
}

void pushjet_TCP::subscribe(const QString& pubkey)
{
}

void pushjet_TCP::unsubscribe(const QString& pubkey)
{
}

void pushjet_TCP::connect()
{
    _socket = new QSslSocket(this);
    
    //TODO: signals & slots for ready??
    _socket->connectToHostEncrypted(_server_url.toString(),_port);
    
}

QJsonDocument create_subscription_request(const QUuid& device_uuid, const QString& pubkey)
{
    QJsonDocument out;
    QJsonObject contents{
        {"uuid" , device_uuid.toString()},
        {"service", pubkey}
    };
    
    out.setObject(contents);
    return out;
}

pushjet_service parse_subscription_response(const QJsonDocument& doc)
{
    
    
    
}

