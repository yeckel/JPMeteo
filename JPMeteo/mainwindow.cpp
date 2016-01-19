#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xmlreader.h"
#include <QDebug>
#include <QTabWidget>
#include "dataframe.h"

void MainWindow::loadXMLData()
{
    XMLReader reader("/home/libor/qt_projects/JPMeteo/JPMeteo/example.xml");
    foreach (MeasuredData data, reader.getData()) {
        ui->tabWidget->addTab(new DataFrame(data),data.name);
    }
    for (int i  = 0; i < ui->tabWidget->count(); i++){
        ui->tabWidget->removeTab(0);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadXMLData();
}

MainWindow::~MainWindow()
{
    delete ui;
}