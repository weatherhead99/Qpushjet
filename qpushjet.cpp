#include "qpushjet.h"
#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QSettings>
#include "device.h"
#include <QPushButton>
#include <QMessageBox>
#include "notifications.h"

const string RESOURCE_ICON_PATH = ":/resources/pushjet.svg";

qpushjet::qpushjet(QWidget* parent)
: QDialog(parent)
{
  _ui.setupUi(this);

  
  _uuid = get_or_create_device_uuid();
  _ui.uuidLine->setReadOnly(true);
  _ui.uuidLine->setText(_uuid.toString());
  
  setuptrayicon();
  _systrayicon->show();
  
  QObject::connect(_ui.generateuuidButton, &QPushButton::pressed, this, &qpushjet::new_device_uuid);
  
  _ui.debug_options->setVisible(false);
  
  _notifier = new desktop_notifier;
  
}

qpushjet::~qpushjet()
{
    if(_notifier)
    {
        delete _notifier;
    }
}



void qpushjet::setuptrayicon()
{
    _quitaction = new QAction(tr("quit"),this);
  connect(_quitaction,&QAction::triggered,this,&QApplication::quit);
  
  _settingsaction = new QAction(tr("settings..."),this);
  connect(_settingsaction,&QAction::triggered,this,&QDialog::show);
  
  _systrayicon = new QSystemTrayIcon(this);
  _systraymenu = new QMenu(this);
  
  _systraymenu->addAction(_settingsaction);
  _systraymenu->addAction(_quitaction);

  _systrayicon->setContextMenu(_systraymenu);

  _systrayicon->setIcon(QIcon(RESOURCE_ICON_PATH.c_str()));
  
}

void qpushjet::new_device_uuid()
{
    QMessageBox::StandardButton areyousure = QMessageBox::question(this, "Confirm new uuid" , 
                                                                   "This will create a new device uuid, your old uuid will be lost. Are you sure?",
                                                                   QMessageBox::Yes | QMessageBox::No);
    
    if(areyousure == QMessageBox::Yes) {
        
        auto newuuid = QUuid::createUuid();
        QSettings settings;
        settings.setValue("device/uuid",newuuid.toString());
        _ui.uuidLine->setText(newuuid.toString());
    }
    
        
    
}


qpushjet_debugmode::qpushjet_debugmode(QWidget* parent)
{
    
    _ui.debug_options->setVisible(true);
    
    QObject::connect(_ui.testNotificationButton, &QPushButton::pressed, _notifier, &desktop_notifier::send_test_notify);
}


