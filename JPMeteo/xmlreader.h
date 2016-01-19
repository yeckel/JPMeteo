#ifndef XMLREADER_H
#define XMLREADER_H
#include <QtXml>
#include <QNetworkReply>

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

class XMLReader: public QObject
{
    Q_OBJECT
public:
    XMLReader();
    QStringList getSenzorList();
    QVector<MeasuredData> getData();
    QString extractElementValue(const QDomElement &elem, const QString elemName);
    void loadFile(const QString &fileUrl);
private slots:
    void fileIsReady(QNetworkReply *reply);
private:
    QDomElement root;
signals:
    void xmlReady();
};

#endif // XMLREADER_H
