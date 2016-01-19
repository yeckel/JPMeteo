#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xmlreader.h"
#include <QDebug>
#include <QTabWidget>
#include "dataframe.h"

void MainWindow::loadXMLData(const QString &fileName)
{
    XMLReader reader(fileName);
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
    ui->lineEdit->setText(settings.value("DataFile",QString("/home/libor/qt_projects/JPMeteo/JPMeteo/example.xml")).toString());
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
