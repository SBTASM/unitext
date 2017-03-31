#include "dict.h"
#include "ui_dict.h"

#include "row.h"
#include "listitem.h"

Dict::Dict(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dict)
{
    ui->setupUi(this);
    setLayout(ui->main);

    connect(ui->rowsList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(selectRowElement(QListWidgetItem*)));
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
        ListItem *itm = new ListItem(i->getFormat(), &*i);
        ui->rowsList->addItem(itm);
    }
}

void Dict::deleteRowElement(QList<Row> *dict, int index)
{
    ui->deleteBtn->setEnabled(true);

    this->dict = dict;
    this->index = index;
}

void Dict::on_saveBtn_clicked()
{
    emit saveDict();
}

void Dict::selectRowElement(QListWidgetItem *item)
{
    emit selectRowListElement(item);
}

void Dict::on_deleteBtn_clicked()
{
    dict->removeAt(index);
    ui->deleteBtn->setEnabled(false);
    emit updateList(dict);

}
