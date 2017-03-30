#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dict.h"

#include "row.h"
#include <QFile>
#include <qmath.h>
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->main);
    ui->depthEdt->setValidator(new QIntValidator(0, pow(2, 16) - 1, this));

    AddRowUI = new AddRow(this);
    DictUI = new Dict(this);

    connect(AddRowUI, SIGNAL(avialableNewElement(Row*)),
            this, SLOT(addDictElement(Row*)));

    connect(DictUI, SIGNAL(showAddUI()), this, SLOT(showAddUI()));
    connect(this, SIGNAL(updateList(QList<Row>*)),
            DictUI, SLOT(updateList(QList<Row>*)));

    connect(DictUI, SIGNAL(saveDict()), this, SLOT(saveDict()));

    QFile file("dict.bin");
    bool e = file.open(QIODevice::ReadOnly);
    if(!e){
        QMessageBox msg;
        msg.setText("Файл словаря не найден. Будет создан новый.");
        msg.setIcon(QMessageBox::Information);
        msg.exec();

        dictionary = new QList<Row>;
    }else{
        QList<Row> tmp;
        QDataStream stream(&file);
        stream >> tmp;
        setWindowTitle(tmp.begin()->getFormat());
        dictionary = new QList<Row>(tmp);
    }

    emit updateList(dictionary);
    file.close();
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

void MainWindow::on_dictBtn_clicked()
{
    DictUI->show();
}

void MainWindow::addDictElement(Row *row)
{
    for(QList<Row>::iterator i = dictionary->begin();
        i != dictionary->end(); i++){
        if(*i == *row){
            QMessageBox msg;
            msg.setText("Такя замена уже есть!");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();

            emit updateList(dictionary);

            return;
        }
    }
    dictionary->push_back(*row);
    emit updateList(dictionary);

}

void MainWindow::showAddUI()
{
    AddRowUI->show();
}

void MainWindow::saveDict()
{
    QFile file("dict.bin");
    QDataStream dataStream(&file);
    bool result = file.open(QIODevice::WriteOnly);
    dataStream << *dictionary;
    file.close();

    if(result){
        QMessageBox msg;
        msg.setText("Сохранения успешно");
        msg.setIcon(QMessageBox::Information);
        msg.exec();
    }else{
        QMessageBox msg;
        msg.setText("Ошибка сохранения!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}

void MainWindow::on_copyBtn_clicked()
{

}
