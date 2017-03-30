#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "row.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->main);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked(){

}

void MainWindow::on_toClpbBtn_clicked()
{
}
