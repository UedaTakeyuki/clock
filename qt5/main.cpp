#include "mainwindow.h"
#include "display.h"

#include <QApplication>
#include <QDebug>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Display *display = new Display;

    // set default geometory
    int screenWidth = display->getWidth();
    int screenHeight = display->getHeight();
    int height = screenHeight/10;
    int width = screenWidth/6;
    int x=0, y=0;
    if (screenWidth >= 1800 && screenHeight >= 1080){
      x=screenWidth - width*1.1;
      y=screenHeight - height*1.7;
    } else {
      /* screenWidth = 720, screenHeight = 480 */
      x=screenWidth - width*1.7;
      y=screenHeight - height*2.2;
    }
    qDebug() << "screenWidth: " << screenWidth;
    qDebug() << "screenHeight: " << screenHeight;
    qDebug() << "height: " << height;
    qDebug() << "width: " << width;
    qDebug() << "x: " << x;
    qDebug() << "y: " << y;
    w.setGeometry(x,y,width,height);

    // set stored geometory if available
    QSettings settings("setting.ini", QSettings::IniFormat);
    const auto geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (!geometry.isEmpty()){
        w.restoreGeometry(settings.value("geometry").toByteArray());
    }
    qDebug() << "restoreGeometry called.";
    w.restoreState(settings.value("windowState").toByteArray());
    qDebug() << "restoreState called.";


    w.show();


    return a.exec();
}
