#pragma once

#include <QAbstractTableModel>
#include <QDateTime>
#include <QString>
#include <QMap>

using std::string;

class QSettings;

struct pushjet_service {
    QString name;
    QDateTime refreshed;
    QDateTime created;
    QString pubkey;
    
};


class services_model : public QAbstractTableModel
{
public:
    services_model();
    ~services_model();
 
    int rowCount(const QModelIndex & parent) const override;
    int columnCount(const QModelIndex & parent) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QVariant data(const QModelIndex & index, int role) const override;
    
    
private:
    QSettings* _settings;
    QMap<QString, pushjet_service> _servicemap;
    
    
};
