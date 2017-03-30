#include "row.h"
#include <QString>

Row::Row(char original, char replace)
{
    this->original = original;
    this->replace = replace;
}

char Row::getOriginal(){ return original; }
char Row::getReplace(){ return replace; }

void Row::setOriginal(char original){ this->original = original; }
void Row::setReplace(char replace){ this->replace = replace; }

QString Row::getFormat(){
    return QString::asprintf("%c(0x%.8x) ---> %c(0x%.8x)", original, original, replace, replace);
}

bool Row::operator ==(Row &row){
    if(this->original == row.original && this->replace == row.replace) return true;
    else return false;
}
