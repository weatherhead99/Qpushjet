#include <QApplication>
#include <QMessageBox>
#include <QSystemTrayIcon>


#include "qpushjet.h"

int main(int argc, char** argv)
{
  Q_INIT_RESOURCE(resources);
  
  QApplication app(argc,argv);
  
  
  if(!QSystemTrayIcon::isSystemTrayAvailable())
  {
      QMessageBox::critical(0, QObject::tr("Systray"),
			    QObject::tr("no system tray available"));
      return -1;
    
  }
  
  QApplication::setQuitOnLastWindowClosed(false);
  
  qpushjet qpush;
  
  
  
  return app.exec();
}