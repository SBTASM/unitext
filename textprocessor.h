#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <qstring.h>

#include "match.h"
#include "row.h"

class TextProcessor
{
public:
    TextProcessor(int Depth, QString string, QList<Row> *dict);

    QList<int>* getPositions();
    QString getString();

    void setString(QString string);

    QList<int>* procesData(int Depth = 0);

private:
    int Depth;
    QList<int> *positions;
    QString string;
    QList<Match> *data;
    QList<Row> *dict;
};

#endif // TEXTPROCESSOR_H
