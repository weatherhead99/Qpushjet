#pragma once
#include "ui_settings.h"
#include <string>
#include <QObject>
#include <QDialog>
#include <QUuid>


using std::string;

class QWidget;
class QSystemTrayIcon;
class QMenu;
class QAction;
class QSettings;
class services_model;
class desktop_notifier;

class qpushjet : public QDialog
{
    Q_OBJECT
  
  public:
    qpushjet(QWidget* parent = nullptr, bool opensettings=false);
    virtual ~qpushjet();
  
    public slots:
    void new_device_uuid();
protected:
    Ui::Dialog _ui;
    desktop_notifier* _notifier;
  
private:
    void savesettings();
    void revertsettings();
    void setuptrayicon();
    
    QSystemTrayIcon* _systrayicon;
    QMenu* _systraymenu;
    QAction* _quitaction;
    QAction* _settingsaction;
    QSettings* _settings;
    QUuid _uuid;
    services_model* _services;
};


class qpushjet_debugmode : public qpushjet
{
  Q_OBJECT
  
public:
    qpushjet_debugmode(QWidget* parent = nullptr, bool opensettings=false);
    
    
};
