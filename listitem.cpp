#include "listitem.h"

ListItem::ListItem(QString text, Row *row)
{
    this->setText(text);
    this->row = row;
}

Row* ListItem::getRow()
{
    return this->row;
}

