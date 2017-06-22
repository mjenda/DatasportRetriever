#include <DatasportModel.h>

#include <QApplication>

#include <QTableView>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <DatasportHtmlGetter.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTableView tableView {};
    DatasportModel model {};

    tableView.setModel(&model);
    tableView.show();

    DatasportHtmlGetter getter;

    getter.get(2200);


    app.exec();
}
