#ifndef DICT_H
#define DICT_H

#include <QDialog>
#include <QListWidget>

#include "row.h"

namespace Ui {
class Dict;
}

class Dict : public QDialog
{
    Q_OBJECT

public:
    explicit Dict(QWidget *parent = 0);
    ~Dict();

private slots:
    void on_closeBtn_clicked();
    void on_addBtn_clicked();
    void on_saveBtn_clicked();

    void selectRowElement(QListWidgetItem* item);

    void on_deleteBtn_clicked();

public slots:
    void updateList(QList<Row> *list);
    void deleteRowElement(QList<Row> *dict, int index);

signals:
    void showAddUI();
    void saveDict();

    void selectRowListElement(QListWidgetItem* item);

private:
    Ui::Dict *ui;
    int index;
    QList<Row> *dict;

};

#endif // DICT_H
