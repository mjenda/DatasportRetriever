#include <QApplication>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <DatasportHtmlGetter.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DatasportHtmlGetter getter;

    getter.get(2200);

    app.exec();
}
