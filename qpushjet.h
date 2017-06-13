#pragma once
#include "ui_settings.h"
#include <string>
#include <QObject>
#include <QDialog>

using std::string;

class QWidget;
class QSystemTrayIcon;
class QMenu;
class QAction;

class qpushjet : public QDialog
{
  
  public:
    qpushjet(QWidget* parent = nullptr);
  
  private:
    
    void setuptrayicon();
    
    
    
    Ui::Dialog _ui;
    QSystemTrayIcon* _systrayicon;
    QMenu* _systraymenu;
    QAction* _quitaction;
    QAction* _settingsaction;
};