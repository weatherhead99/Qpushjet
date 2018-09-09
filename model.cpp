#include "model.h"

#include <QSettings>
#include <QDebug>

services_model::services_model()
{
    _settings = new QSettings();
    
    QStringList groups = _settings->childGroups();
    qDebug() << "groups: " << groups;
    
    _settings->beginGroup("services");
    
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
    if(parent.isValid())
        return 0;
    
    return _services.size();
}

QVariant services_model::headerData(int section, Qt::Orientation orientation, int role) const
{
    
    if(orientation == Qt::Vertical)
    {
        return QString(section);
    }
    
    switch(section)
    {
    qDebug() << "section: " << section;
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
    auto itemit = (_services.begin() + index.row());
    
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
    beginInsertRows(parent,row , row + count - 1 );
    qDebug() << "inserting row: " << row;
    qDebug() << "count: " <<count;
    
    _services.insert(row,count,pushjet_service());
    qDebug() << "services size: " << _services.size();
    
    endInsertRows();
    return true;
}


bool services_model::removeRows(int row, int count, const QModelIndex& parent)
{
    beginRemoveRows(parent,row,row+count -1);
    _services.remove(row,count);
    endRemoveRows();
    return true;
    
}

bool services_model::setData(const QModelIndex& index, const QVariant& value, int role)
{
    auto it = _services.begin() + index.row();
    
    switch(index.column())
    {
        case 0 : 
            it->name = value.toString();break;
        case 1:
            it->refreshed = QDateTime::fromString(value.toString()); break;
        case 2:
            it->created = QDateTime::fromString(value.toString()); break;
    }
    
    return false;
    
}

void services_model::addEmptyService()
{
    insertRow(rowCount(QModelIndex()));
}

void services_model::syncServicesToFile()
{
    for(auto& item : _services)
    {
        if(item.name.size() == 0)
        {
            qDebug() << "empty service name, not syncing...";
            continue;
        }
        _settings->setValue(item.name + "/pubkey", item.pubkey);
        _settings->setValue(item.name + "/created", item.created.toString());
        _settings->setValue(item.name + "/refreshed", item.refreshed.toString());
        
        
    };
}

Qt::ItemFlags services_model::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEditable | Qt::ItemIsSelectable;
    
}


