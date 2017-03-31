#include "match.h"

Match::Match(QChar org, QChar rep, QString *str, int position)
{
    original = org;
    replace = rep;
    string = str;
    processed = false;
    this->position = position;
}

QChar Match::getOriginal(){ return original; }
QChar Match::getReplace(){ return replace; }
QString *Match::getString(){ return string; }
bool Match::getProcessed(){ return processed; }
int Match::getPosition(){ return position; }

void Match::setOriginal(QChar org){ original = org; }
void Match::setReplace(QChar rep){ replace = rep; }
void Match::setString(QString *str){ string = str; }

bool Match::work(){
    string->replace(position, 1, replace);
    return true;
}
bool Match::cancel(){
    string[position] = original;
    return true;
}

