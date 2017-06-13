#include "qpushjet.h"
#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>


const string RESOURCE_ICON_PATH = ":/resources/pushjet.svg";


qpushjet::qpushjet(QWidget* parent)
: QDialog(parent)
{
  _ui.setupUi(this);

  
  setuptrayicon();
  _systrayicon->show();
   
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
