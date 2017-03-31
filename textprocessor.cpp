#include "textprocessor.h"
#include <QList>

#include <qdebug.h>

TextProcessor::TextProcessor(int Depth, QString string, QList<Row> *dict)
{
    positions = new QList<int>;
    data = new QList<Match>;
    this->string = string;
    this->Depth = Depth;
    this->dict = dict;
}

QString TextProcessor::getString(){ return string; }
QList<int>* TextProcessor::getPositions(){ return positions; }

QList<int>* TextProcessor::procesData(int Depth){
    int org_Depth = 0, position = 0;
    if(Depth > 0){org_Depth = this->Depth; this->Depth = Depth; }
    for(QString::iterator i = string.begin(); i != string.end(); i++, position++){
        for(QList<Row>::iterator j = dict->begin(); j != dict->end(); j++){
            if(*i == j->getOriginal()){
                data->push_back(Match(j->getOriginal(), j->getReplace(), &string,  position));
                positions->push_back(position);
            }
        }
    }

    data->first().work();

    return positions;
}



