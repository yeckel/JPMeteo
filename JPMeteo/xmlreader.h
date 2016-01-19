#ifndef XMLREADER_H
#define XMLREADER_H
#include <QtXml>

struct MeasuredData{
    int id;
    QString name;
    QString temperature1;
    QString temperature2;
    QString humidity;
    QString pressure;
    QString windSpeed;
    QString perceptedTemperature;
};

class XMLReader
{
public:
    XMLReader(const QString &fileName);
    QStringList getSenzorList();
    QVector<MeasuredData> getData();
    QString extractElementValue(const QDomElement &elem, const QString elemName);
private:
    QDomElement root;
};

#endif // XMLREADER_H
