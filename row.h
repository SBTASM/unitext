#ifndef ROW_H
#define ROW_H

#include <QString>

class Row
{
public:
    bool operator==(const Row &row);
    bool operator==(QString &str);

    friend QDataStream &operator<<(QDataStream &out, const Row &row);
    friend QDataStream &operator>>(QDataStream &in, Row &row);

    Row(QChar original, QChar replace);
    Row();

    void setOriginal(QChar original);
    void setReplace(QChar replace);

    QChar getOriginal();
    QChar getReplace();

    QString getFormat();

private:
    QChar original, replace;
};

#endif // ROW_H
