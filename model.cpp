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
    qDebug() << "section: " << section;
    
    if(orientation == Qt::Vertical)
    {
        return QString(section);
    }
    
    switch(section)
    {
        case 0: return QString("name");
        case 1: return QString("refreshed");
        case 2: return QString("created");
        case 3: return QString("public key");
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


bool services_model::insertRows(int row, int count, const QModelIndex& parent)
{
    beginInsertRows(parent,_servicemap.size(), _servicemap.size() + count);
    
    
    endInsertRows();
    return true;
}


bool services_model::removeRows(int row, int count, const QModelIndex& parent)
{
    beginRemoveRows(parent,row,row+count);
    
    endRemoveRows();
    return true;
    
}

bool services_model::setData(const QModelIndex& index, const QVariant& value, int role)
{
    
    
}



void services_model::addEmptyService()
{
    insertRow(rowCount(QModelIndex()));
}


