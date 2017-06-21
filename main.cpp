#include <QApplication>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <DatasportHtmlGetter.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QNetworkAccessManager nam;
    DatasportHtmlGetter * obj = new DatasportHtmlGetter(&nam);

    QNetworkReply * reply = nam.get(QNetworkRequest(QUrl("http://wyniki.datasport.pl/results2200/src/advlist.php?dyst=1&od=0")));
    QObject::connect(reply, SIGNAL(finished()), obj, SLOT(onFinished()));

    app.exec();
}
