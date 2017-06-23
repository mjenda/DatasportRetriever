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

    QHeaderView *verticalHeader = tableView.verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
    verticalHeader->setDefaultSectionSize(20);

    tableView.verticalHeader ()->hide();
    tableView.setModel(&model);
    tableView.showMaximized();

    model.setCompetition(2020);

    app.exec();
}
