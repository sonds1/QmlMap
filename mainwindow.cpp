#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QQuickItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();

    auto obj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
    connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));

    emit setCenter(25.000, 50.000);
    emit addMarker(25.000, 50.000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

