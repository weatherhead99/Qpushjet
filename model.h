#pragma once

#include <QAbstractTableModel>
#include <QDateTime>
#include <string>
using std::string;

class QSettings;

struct pushjet_service {
    string name;
    QDateTime refreshed;
    QDateTime created;
    string pubkey;
    
};


class services_model : public QAbstractTableModel
{
public:
    services_model();
    
    
    
private:
    QSettings* _settings;
    
};
