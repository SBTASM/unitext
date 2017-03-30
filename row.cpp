#include "row.h"
#include <QString>

Row::Row()
{
    original = replace = 0;
}
Row::Row(QChar original, QChar replace)
{
    this->original = original; this->replace = replace;
}
QChar Row::getOriginal(){ return original; }
QChar Row::getReplace(){ return replace; }
void Row::setOriginal(QChar original){ this->original = original; }
void Row::setReplace(QChar replace){ this->replace = replace; }
QString Row::getFormat(){
    return QString::asprintf("%s(0x%.8X) ----> %s(0x%.8X)", QString(original).toStdString().c_str(), original, QString(replace).toStdString().c_str(), replace);
}
bool Row::operator ==(Row &row){
    if(this->original == row.original && this->replace == row.replace) return true;
    else return false;
}

bool Row::operator==(QString &str)
{
    if(QString::compare(this->getFormat(), str) == 0) return true;
    else return false;
}
QDataStream &operator<<(QDataStream &out, const Row &row)
{
    out << QString(row.original) << QString(row.replace);
    return out;
}
QDataStream &operator>>(QDataStream &in, Row &row)
{
    QString org, rep;
    in >> org >> rep;
    Row tmp(org[0], rep[0]);
    memcpy(&row, &tmp, sizeof(Row));
    return in;
}
