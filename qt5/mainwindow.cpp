#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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
