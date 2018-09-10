#include "api.h"
#include <QSslSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QDebug>


namespace detail
{
    
    template<typename T> struct json_response_parser
    {
        json_response_parser(QJsonDocument& doc)
        {
            
            
        };
        
        
        
        
    };
    
    
    
}


pushjet_api::pushjet_api(const QUuid& device_uuid, const QUrl& server_url)
: _device_uuid(device_uuid), _server_url(server_url)
{
}

pushjet_api::~pushjet_api()
{
}

void pushjet_api::subscribe(const QString& pubkey)
{
}

void pushjet_api::unsubscribe(const QString& pubkey)
{
}

void pushjet_api::get_service_info(const QString& pubkey)
{
    auto endpoint = _server_url.toString() + "/service";
    QNetworkRequest req(endpoint);
    req.setRawHeader(QByteArray("service"), pubkey.toUtf8());
    
    auto repl = _accessman.get(req);
    QObject::connect(&_accessman,&QNetworkAccessManager::finished,this,&pushjet_api::process_reply);
    
}

void pushjet_api::process_reply(QNetworkReply* repl)
{
    try{
    //check network error
        if( repl->error() != QNetworkReply::NoError)
            throw std::runtime_error("error in network transmission");
    //check http response 
        auto http_response_variant = repl->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        if(!http_response_variant.isValid())
            throw std::runtime_error("invalid variant in HTTP response code");
        if(http_response_variant.toInt() != 200)
            throw std::runtime_error("got an error back in response!");
        
        
    }
    catch(std::runtime_error& err)
    {
        qDebug() << "error: " << err.what();
        
    };
        
    
    QJsonDocument parsed  ;
    
    
    
}






void pushjet_api::connect()
{

    
}

QNetworkRequest pushjet_api::create_subscription_request(const QString& pubkey)
{
    auto endpoint = _server_url.toString() + "/subscription";
    
    QNetworkRequest out(endpoint);
    
    out.setRawHeader(QByteArray("uuid"),_device_uuid.toByteArray());
    out.setRawHeader(QByteArray("service"),pubkey.toUtf8());
    
    return out;
}


