#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "DatasportModel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    DatasportModel * model = new DatasportModel(this);

    QHeaderView *verticalHeader = ui->tableView->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
    verticalHeader->setDefaultSectionSize(20);

    ui->tableView->verticalHeader ()->hide();
    ui->tableView->setModel(model);
    ui->tableView->showMaximized();

    model->setCompetition(2020);

}

MainWindow::~MainWindow()
{
    delete ui;
}
