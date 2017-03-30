#ifndef ROW_H
#define ROW_H

#include <QString>

class Row
{
public:
    bool operator==(Row &row);
    Row(char original, char replace);

    void setOriginal(char original);
    void setReplace(char replace);

    char getOriginal();
    char getReplace();

    QString getFormat();

private:
    char original, replace;
};

#endif // ROW_H
