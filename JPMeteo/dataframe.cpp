#include "dataframe.h"
#include <QHBoxLayout>
#include <QLabel>


DataFrame::DataFrame(const MeasuredData &data, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    this->setLayout(mainLayout);
    mainLayout->addWidget(new QLabel(tr("teplota: ")+data.temperature1));
    mainLayout->addWidget(new QLabel(tr("teplota2: ")+data.temperature2));
    mainLayout->addWidget(new QLabel(tr("vlhkost: ")+data.humidity));
    mainLayout->addWidget(new QLabel(tr("tlak: ")+data.pressure));
    mainLayout->addWidget(new QLabel(tr("rychlost: ")+data.windSpeed));
    mainLayout->addWidget(new QLabel(tr("pocitove: ")+data.perceptedTemperature));
}

