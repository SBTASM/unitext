#include "addrow.h"
#include "ui_addrow.h"

AddRow::AddRow(QWidget *parent) : QDialog(parent), ui(new Ui::AddRow)
{
    ui->setupUi(this);
    setLayout(ui->main);
}

AddRow::~AddRow()
{
    delete ui;
}

void AddRow::on_addBtn_clicked()
{
    QChar org = ui->orgEdt->text()[0];
    QChar rep = ui->repEdt->text()[0];
    Row *row = new Row(org, rep);

    emit avialableNewElement(row);

    close();
}
