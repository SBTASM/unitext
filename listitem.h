#ifndef LISTITEM_H
#define LISTITEM_H

#include <QObject>
#include <QWidget>

#include <QListWidget>

#include <row.h>

class ListItem : public QListWidgetItem
{
public:
    ListItem(QString text, Row *row);
    Row *getRow();

private:
    Row *row;
};

#endif // LISTITEM_H
