#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dict.h"
#include "listitem.h"
#include "textprocessor.h"

#include "row.h"
#include <QFile>
#include <qmath.h>
#include <qmessagebox.h>
#include <qclipboard.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->main);
    ui->depthEdt->setValidator(new QIntValidator(0, pow(2, 16) - 1, this));

    AddRowUI = new AddRow(this);
    DictUI = new Dict(this);

    connections();

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
//        setWindowTitle(tmp.begin()->getFormat());
        dictionary = new QList<Row>(tmp);
    }

    emit updateList(dictionary);
    file.close();
}

void MainWindow::connections()
{
    connect(AddRowUI, SIGNAL(avialableNewElement(Row*)),
            this, SLOT(addDictElement(Row*)));

    connect(DictUI, SIGNAL(showAddUI()), this, SLOT(showAddUI()));

    connect(this, SIGNAL(updateList(QList<Row>*)),
            DictUI, SLOT(updateList(QList<Row>*)));

    connect(DictUI, SIGNAL(saveDict()), this, SLOT(saveDict()));

    connect(DictUI, SIGNAL(sig_slectRowElement(QListWidgetItem*)),
            this, SLOT(on_slectRowElement(QListWidgetItem*)));

    connect(DictUI, SIGNAL(selectRowListElement(QListWidgetItem*)),
            this, SLOT(slectRowListElement(QListWidgetItem*)));

    connect(this, SIGNAL(selectRowElement(QList<Row>*,int)), DictUI, SLOT(deleteRowElement(QList<Row>*,int)));
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
    int Depth = atoi(ui->depthEdt->text().toStdString().c_str());
    QString text = ui->dataPlain->toPlainText();
    TextProcessor *processor = new TextProcessor(text, dictionary);
    QList<int> *positions = processor->procesData(Depth);
    text = processor->getString();
    QStringList *buff = new QStringList;

    ui->dataPlain->clear();
    ui->dataPlain->setPlainText(text);

//    for(QList<int>::iterator i = positions->begin(); i != positions->end(); i++){
//        buff->push_back(text.mid(*i, *(i+1) - *i));
//    }

//    ui->dataPlain->clear();

//    for(QList<QString>::iterator i = buff->begin(); i != buff->end(); i++){
//        QString element = i->mid(0, 1);
//        QString end = i->mid(1, i->length() - 1);

//        ui->dataPlain->setTextColor(QColor("red"));
//        ui->dataPlain->insertPlainText(element);
//        ui->dataPlain->setTextColor(QColor("blue"));
//        ui->dataPlain->insertPlainText(end);
//    }

    ui->dataPlain->setTextColor(QColor("black"));

}
void MainWindow::slectRowListElement(QListWidgetItem *itm)
{
    ListItem *item = (ListItem*)itm;
    Row *row = item->getRow();

    int index = dictionary->indexOf(*row);

    emit selectRowElement(dictionary, index);
}

void MainWindow::on_quitBtn_clicked()
{
    QApplication::quit();
}
