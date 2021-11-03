#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, []() {QDateTime dt = QDateTime::currentDateTime(); return qDebug() << dt.toString("hh:mm:ss.zzz"); });
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

