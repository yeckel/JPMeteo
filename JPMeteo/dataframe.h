#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <QWidget>
#include "xmlreader.h"

class DataFrame : public QWidget
{
    Q_OBJECT
public:
    explicit DataFrame(const MeasuredData &data, QWidget *parent = 0);

signals:

public slots:
};

#endif // DATAFRAME_H
