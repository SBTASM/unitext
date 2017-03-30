#include "dict.h"
#include "ui_dict.h"

Dict::Dict(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dict)
{
    ui->setupUi(this);
    setLayout(ui->main);
}

Dict::~Dict()
{
    delete ui;
}

void Dict::on_closeBtn_clicked()
{
    this->close();
}
