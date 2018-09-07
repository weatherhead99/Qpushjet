#include "device.h"

#include <QSettings>
#include <QDebug>
#include <array>

const QString uuid_settings_string = "device/uuid";


QUuid get_or_create_device_uuid()
{
    QSettings settings;
    
    auto existing_uuid = settings.value("device/uuid");
    if(existing_uuid.isNull())
    {
        qDebug() << "no existing uuid found in settings, creating a new one...";
        auto new_uuid = QUuid::createUuid();
        settings.setValue("device/uuid",new_uuid.toString());
        return new_uuid;
        
    }
    
    qDebug() << "using existing uuid...";
    
#if (QT_VERSION >= QT_VERSION_CHECK(5,10,0) )
    auto uuid = QUuid::fromString(existing_uuid.toString());
#else
    auto uuid = QUuid(existing_uuid.toString());
    
#endif
    
    return uuid;
    
    
}
