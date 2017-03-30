#ifndef DICT_H
#define DICT_H

#include <QDialog>

namespace Ui {
class Dict;
}

class Dict : public QDialog
{
    Q_OBJECT

public:
    explicit Dict(QWidget *parent = 0);
    ~Dict();

private:
    Ui::Dict *ui;
};

#endif // DICT_H
