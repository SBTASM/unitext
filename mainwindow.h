#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "row.h"
#include "addrow.h"
#include "dict.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool processData();

private slots:
    void on_pushButton_2_clicked();

    void on_toClpbBtn_clicked();

    void on_dictBtn_clicked();

    void addDictElement(Row *row);
    void showAddUI();

    void saveDict();

    void on_copyBtn_clicked();

    void slectRowListElement(QListWidgetItem *itm);

private:
    Ui::MainWindow *ui;
    QList<Row> *dictionary;
    Dict *DictUI;
    AddRow *AddRowUI;

    void connections();

signals:
    void updateList(QList<Row> *list);
    void selectRowElement(QList<Row> *dict, int index);
};

#endif // MAINWINDOW_H
