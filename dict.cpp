#include "dict.h"
#include "ui_dict.h"

#include "row.h"

Dict::Dict(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dict)
{
    ui->setupUi(this);
    setLayout(ui->main);

    connect(ui->rowsList, SIGNAL(currentTextChanged(QString)), this, SLOT(selectedItem(QString)));
}

Dict::~Dict()
{
    delete ui;
}

void Dict::on_closeBtn_clicked()
{
    close();
}

void Dict::on_addBtn_clicked()
{
    emit showAddUI();
}

void Dict::updateList(QList<Row> *list)
{
    ui->rowsList->clear();
    for(QList<Row>::iterator i = list->begin(); i != list->end(); i++){
        ui->rowsList->addItem(i->getFormat());
    }
}

void Dict::selectedItem(QString str)
{
    emit selectItem(str);
}

void Dict::on_saveBtn_clicked()
{
    emit saveDict();
}
