#include "xmlreader.h"
#include <QDebug>
#include <QtXml>

XMLReader::XMLReader(const QString &fileName)
{
    QFile f(fileName);
    if (!f.open(QIODevice::ReadOnly )){
        // Error while loading file
        qDebug() << "Error while loading file";
        return;
    }
    QDomDocument xmlDoc;
    xmlDoc.setContent(&f);
    f.close();
    root = xmlDoc.documentElement();
}

QStringList XMLReader::getSenzorList()
{
    QDomNodeList senzorList = root.elementsByTagName("senzor");
    QStringList ret;
    for (int i = 0; i <  senzorList.length(); i++){
        QDomElement elem = senzorList.at(i).toElement();
        QDomNodeList elemsPoloha = elem.elementsByTagName("poloha");
        if (elemsPoloha.length() != 1)
            continue;
        ret.append(elemsPoloha.at(0).toElement().text());
    }
    return ret;
}

QString XMLReader::extractElementValue(const QDomElement &elem, const QString elemName)
{
    QDomNodeList elemsPoloha = elem.elementsByTagName(elemName);
    if (elemsPoloha.length() != 1)
        return QStringLiteral("Invalid");
    return elemsPoloha.at(0).toElement().text();
}

QVector<MeasuredData> XMLReader::getData()
{
    QVector<MeasuredData> ret;
    QDomNodeList senzorList = root.elementsByTagName("senzor");
    for (int i = 0; i <  senzorList.length(); i++){
        MeasuredData data;
        QDomElement elem = senzorList.at(i).toElement();
        data.name         = extractElementValue(elem,"poloha");
        data.temperature1 = extractElementValue(elem,"teplota");
        data.temperature2 = extractElementValue(elem,"teplota2");
        data.humidity     = extractElementValue(elem,"vlhkost");
        data.pressure     = extractElementValue(elem,"tlak");
        data.windSpeed    = extractElementValue(elem,"rychlost");
        data.perceptedTemperature = extractElementValue(elem,"pocitove");
        ret.append(data);
    }
    return ret;
}

