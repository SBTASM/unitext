#ifndef ADDROW_H
#define ADDROW_H

#include <QDialog>

#include "row.h"

namespace Ui {
class AddRow;
}

class AddRow : public QDialog
{
    Q_OBJECT

public:
    explicit AddRow(QWidget *parent = 0);
    ~AddRow();

private slots:
    void on_addBtn_clicked();

signals:
    void avialableNewElement(Row *row);

private:
    Ui::AddRow *ui;
    Row *row;
};

#endif // ADDROW_H
