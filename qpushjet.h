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


class qpushjet : public QDialog
{
    Q_OBJECT
  
  public:
    qpushjet(QWidget* parent = nullptr);
  
    public slots:
    void new_device_uuid();
    
  private:
    
    void setuptrayicon();
    
    
    
    Ui::Dialog _ui;
    QSystemTrayIcon* _systrayicon;
    QMenu* _systraymenu;
    QAction* _quitaction;
    QAction* _settingsaction;
    QSettings* _settings;
    QUuid _uuid;
};
