#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTabWidget>
#include "dataframe.h"

void MainWindow::loadXMLData(const QString &fileName)
{
    reader.loadFile(fileName);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText(settings.value("DataFile",QString("http://tomsik.eu/sites/tomsik.eu/files/example.xml")).toString());
    connect(&reader,SIGNAL(xmlReady()),this,SLOT(on_DataReady()));
    loadXMLData(settings.value("DataFile").toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    loadXMLData(ui->lineEdit->text());
    settings.setValue("DataFile",ui->lineEdit->text());
}

void MainWindow::on_DataReady()
{
    ui->tabWidget->clear();
    foreach (MeasuredData data, reader.getData()) {
        ui->tabWidget->addTab(new DataFrame(data),data.name);
    }
}
