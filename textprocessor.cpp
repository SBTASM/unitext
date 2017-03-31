#include "textprocessor.h"
#include <QList>

#include <qdebug.h>
#include <quuid.h>

TextProcessor::TextProcessor(QString string, QList<Row> *dict)
{
    positions = new QList<int>;
    data = new QList<Match>;
    this->string = string;
    this->dict = dict;
}

QString TextProcessor::getString(){ return string; }
QList<int>* TextProcessor::getPositions(){ return positions; }

QList<int>* TextProcessor::procesData(int Depth){
    int position = 0;
    for(QString::iterator i = string.begin(); i != string.end(); i++, position++){
        for(QList<Row>::iterator j = dict->begin(); j != dict->end(); j++){
            if(*i == j->getOriginal()){
                data->push_back(Match(j->getOriginal(), j->getReplace(), &string,  position));

            }
        }
    }

    srand(time(NULL));
    while(data->size() > Depth){
        data->removeAt(rand() % data->size());
    }

    for(QList<Match>::iterator i = data->begin(); i != data->end(); i++){
        i->work();
        positions->push_back(i->getPosition());
    }

    return positions;
}



