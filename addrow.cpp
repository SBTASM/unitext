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

void AddRow::on_orgEdt_textChanged(const QString &arg1)
{
    if(ui->orgEdt->text().length() > 1) ui->orgEdt->clear();
    else if(ui->orgEdt->text().length() < 1) ui->orgLbl->setText("Оригинал");
    else ui->orgLbl->setText(QString::asprintf("%s - 0x%.08X", arg1.toStdString().c_str(), arg1[0]));
}

void AddRow::on_repEdt_textChanged(const QString &arg1)
{
    if(ui->orgRep->text().length() > 1) ui->repRep->clear();
    else if(ui->repLbl->text().length() < 1) ui->repLbl->setText("Оригинал");
    else ui->repLbl->setText(QString::asprintf("%s - 0x%.08X", arg1.toStdString().c_str(), arg1[0]));
}

void AddRow::on_cancleBtn_clicked()
{
    close();
}
