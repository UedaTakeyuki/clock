#include "mainwindow.h"
#include "display.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QSettings>
#include <QMessageBox>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Display *display = new Display;
    qDebug() << display->getWidth() << ":" << display->getHight();

    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    /*
    connect(timer, &QTimer::timeout, this, [](){
        QDateTime dt = QDateTime::currentDateTime();
        qDebug() << dt.toString("hh:mm:ss.zzz");
    });
    */
    connect(timer, &QTimer::timeout, this, [this](){
        QDateTime dt = QDateTime::currentDateTime();
        ui->label->setText(dt.toString("hh:mm:ss"));});
    timer->start(50);

    // https://stackoverflow.com/questions/24239822/how-to-remove-space-margin-that-between-qmainwindow-and-mdiarea/24240025
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
    statusBar()->hide();

    // http://pido.seesaa.net/article/183717126.html
    QSettings settings("setting.ini", QSettings::IniFormat);
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());


}

MainWindow::~MainWindow()
{
    // http://pido.seesaa.net/article/183717126.html
    QSettings setting("setting.ini", QSettings::IniFormat);
    setting.setValue("geometry", saveGeometry());
    setting.setValue("windowState", saveState());

    delete ui;
}
