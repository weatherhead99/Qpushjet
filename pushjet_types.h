#pragma once
#include <QDateTime>
#include <QString>

struct pushjet_service {
    QString name;
    QString icon;
    QDateTime refreshed;
    QDateTime created;
    QString pubkey;
    
};
