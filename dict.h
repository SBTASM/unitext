#ifndef DICT_H
#define DICT_H

#include <QDialog>

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

public slots:
    void updateList(QList<Row> *list);

signals:
    void showAddUI();
    void saveDict();

private:
    Ui::Dict *ui;

};

#endif // DICT_H
