#include "dict.h"
#include "ui_dict.h"

Dict::Dict(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dict)
{
    ui->setupUi(this);
}

Dict::~Dict()
{
    delete ui;
}
