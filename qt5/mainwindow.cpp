#include "mainwindow.h"
#include "display.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QSettings>
#include <QMessageBox>
#include <QProcess>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Display *display = new Display;
    qDebug() << display->getWidth() << ":" << display->getHeight();

    ui->setupUi(this);

    int fontsize = display->getHeight()/18;
    QFont f("PibotoLt", fontsize, QFont::Bold);
    ui->label->setFont(f);
    qDebug() << "PibotoLt font set.";

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

    // http://pido.seesaa.net/article/183717126.html
    QSettings settings("setting.ini", QSettings::IniFormat);
    restoreGeometry(settings.value("geometry").toByteArray());
    qDebug() << "restoreGeometry called.";
    restoreState(settings.value("windowState").toByteArray());
    qDebug() << "restoreState called.";

}

MainWindow::~MainWindow()
{
    // http://pido.seesaa.net/article/183717126.html
    QSettings setting("setting.ini", QSettings::IniFormat);
    setting.setValue("geometry", saveGeometry());
    setting.setValue("windowState", saveState());
    delete ui;
}
