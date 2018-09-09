#include "client.h"

#include <QSettings>
#include <QDebug>

QUrl default_pushjet_api = QString("https://api.pushjet.io/");

QUrl get_server_url()
{
    QSettings settings;
    
    auto existing_server = settings.value("client/apiurl");
    if(existing_server.isNull())
    {
        qDebug() << "no existing server setting found, using default";
        settings.setValue("client/apiurl",default_pushjet_api);
        return default_pushjet_api;
    };
    
    qDebug() << "using existing server setting...";
    return QUrl(existing_server.toString());
    
}
