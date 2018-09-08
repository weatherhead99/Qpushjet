#include "model.h"

#include <QSettings>
#include <QDebug>

services_model::services_model()
{
    _settings = new QSettings();
    
    QStringList groups = _settings->childGroups();
    qDebug() << "groups: " << groups;
    
    if(!groups.contains("services"))
    {
        qDebug() << "settings doesn't contain services group, creating...";
        _settings->beginGroup("services");
        _settings->endGroup();
    }
    
}

services_model::~services_model()
{
    if(_settings)
        delete _settings;
}

int services_model::columnCount(const QModelIndex& parent) const
{
    return 4;
}

int services_model::rowCount(const QModelIndex& parent) const
{
    return _servicemap.size();
}

QVariant services_model::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch(section)
    {
        case 0: return "name";
        case 1: return "refreshed";
        case 2: return "created";
        case 3: return "public key";
        default:
            qDebug() << "invalid column number in headerData";
    };
    
    
}



QVariant services_model::data(const QModelIndex& index, int role) const
{
    auto itemit = (_servicemap.begin() + index.row());
    
    switch(index.column())
    {
        case 0 : return itemit->name; break;
        case 1 : return itemit->refreshed; break;
        case 2 : return itemit->created; break;
        case 3 : return itemit->pubkey; break;
        default:
            qDebug() << "invalid column number in index...";
    }
    
    
    
    
}
