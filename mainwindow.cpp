#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "DatasportModel.h"

#include <QSortFilterProxyModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::getNewData);

    DatasportModel * model = new DatasportModel(this);

    QSortFilterProxyModel * proxyModel = new QSortFilterProxyModel(model);
    proxyModel->sort(1);
    proxyModel->setSourceModel(model);

    QHeaderView *verticalHeader = ui->tableView->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
    verticalHeader->setDefaultSectionSize(20);

    ui->tableView->verticalHeader ()->hide();
    ui->tableView->setSortingEnabled(true);

    ui->tableView->setModel(proxyModel);
    ui->tableView->showMaximized();

    getNewData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getNewData()
{
    int competitionId = ui->competitionIdLineEdit->text().toInt();

    if (competitionId == 0)
    {
        return;
    }

    auto proxySortModel = qobject_cast<QSortFilterProxyModel*>(ui->tableView->model());
    auto datasportModel = qobject_cast<DatasportModel*>(proxySortModel->sourceModel());
    datasportModel->setCompetition(competitionId);
}
