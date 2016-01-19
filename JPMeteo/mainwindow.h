#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include "xmlreader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void loadXMLData(const QString &fileName);
private slots:
    void on_pushButton_clicked();
    void on_DataReady();
private:
    Ui::MainWindow *ui;
    QSettings settings;
    XMLReader reader;
};

#endif // MAINWINDOW_H
