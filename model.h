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
    
    bool insertRows(int row, int count, const QModelIndex & parent) override;
    bool removeRows(int row, int count, const QModelIndex & parent) override;

    bool setData(const QModelIndex & index, const QVariant & value, int role) override;
    
public slots:
    void addEmptyService();
    
    
private:
    QSettings* _settings;
    QMap<QString, pushjet_service> _servicemap;
    
    
};
