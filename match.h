#ifndef MATCH_H
#define MATCH_H

#include <qstring.h>


class Match
{
public:
    Match(QChar org, QChar rep, QString *str, int position);

    bool work();
    bool cancel();

    QChar getOriginal();
    QChar getReplace();
    QString *getString();
    bool getProcessed();
    int getPosition();

    void setOriginal(QChar org);
    void setReplace(QChar rep);
    void setString(QString *str);

private:
    int position;
    QString *string;
    QChar original, replace;
    bool processed;
};

#endif // MATCH_H
