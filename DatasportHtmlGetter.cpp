#include "DatasportHtmlGetter.h"

#include "DatasportParser.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

#include <iostream>

DatasportHtmlGetter::DatasportHtmlGetter(QObject *parent)
    : QObject(parent), networkAccessManager(new QNetworkAccessManager(this)), chunks(0)
{

}

void DatasportHtmlGetter::get(int _competitionId)
{
    chunks = 0;
    competitionId = _competitionId;
    getChunk();
}



void DatasportHtmlGetter::onFinished()
{
    std::cout << chunks << std::endl;
    QIODevice * content = static_cast<QIODevice*>(QObject::sender());
    QString results = content->readAll();

    if (results.isEmpty())
    {
        DatasportParser parser;
        parser.parse(rawHtml.toStdString());
        return;
    }

    rawHtml += results;

    getChunk();
}

void DatasportHtmlGetter::getChunk()
{
    QString competitionAddress =
            "http://wyniki.datasport.pl/results"
            + QString::number(competitionId)
            + "/src/advlist.php?dyst=1&od="
            + QString::number(chunks * 200)
            + "&miasto=&druzyna=&kraj=&plec=&katw=&sort1=&sort2=&sort3=&sort4=&"
              "sort5=&disp_msc=&disp_numer=&disp_nazwisko=&disp_imie=&disp_miasto=&"
              "disp_druzyna=&disp_kraj=&disp_plec=&disp_rokur=&disp_katw=&disp_czasm=&disp_plec=";
//    QString competitionAddress = "http://wyniki.datasport.pl/results"
//            + QString::number(competitionId)
//            + "/src/advlist.php?dyst=1&od="
//            + QString::number(chunks * 200);

    chunks++;

    QNetworkReply * reply = networkAccessManager->get(QNetworkRequest(QUrl(competitionAddress)));
    QObject::connect(reply, SIGNAL(finished()), this, SLOT(onFinished()));
}
