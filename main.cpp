#include <QApplication>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QCommandLineParser>
#include <QDebug>
#include <memory>

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
  QApplication::setOrganizationName("qpushjet");
  QApplication::setApplicationName("qpushjet");
  
  
  QCommandLineParser parser;
  parser.addHelpOption();
  
  QCommandLineOption debug(QStringList() << "debug" << "d", "start gui in debug mode" );
  parser.addOption(debug);
  
  QCommandLineOption settings(QStringList() << "settings" << "s", "start with settings gui open");
  parser.addOption(settings);
  
  parser.process(app);
  
  
  std::unique_ptr<qpushjet> qpush;
  
  if(parser.isSet(debug))
  {
      qDebug() << "running in debug mode...";
      qpush.reset(new qpushjet_debugmode(nullptr,parser.isSet(settings)));
  }
  else
  {
        qpush.reset(new qpushjet(nullptr,parser.isSet(settings)));
  }
  
  
  
  return app.exec();
}
