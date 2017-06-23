#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "DatasportModel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::getNewData);

    DatasportModel * model = new DatasportModel(this);

    QHeaderView *verticalHeader = ui->tableView->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
    verticalHeader->setDefaultSectionSize(20);

    ui->tableView->verticalHeader ()->hide();
    ui->tableView->setModel(model);
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

    qobject_cast<DatasportModel*>(ui->tableView->model())->setCompetition(competitionId);
}
