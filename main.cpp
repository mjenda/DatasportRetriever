#include <DatasportModel.h>

#include <QApplication>

#include <QTableView>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <DatasportHtmlGetter.h>

#include <QTextCodec>
#include <QHeaderView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTableView tableView {};
    DatasportModel model {};

    tableView.verticalHeader ()->hide();
    QHeaderView *verticalHeader = tableView.verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
    verticalHeader->setDefaultSectionSize(20);

    tableView.setModel(&model);

    DatasportHtmlGetter getter;

    QObject::connect(&getter, &DatasportHtmlGetter::finished,
                         &model, &DatasportModel::newData);


    getter.get(2020);
    tableView.showMaximized();
    app.exec();
}
