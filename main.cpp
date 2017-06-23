#include "DatasportModel.h"
#include "mainwindow.h"

#include <QApplication>
#include <QTableView>
#include <QHeaderView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.showMaximized();

    app.exec();
}
