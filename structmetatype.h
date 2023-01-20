#ifndef STRUCTMETATYPE_H
#define STRUCTMETATYPE_H

#include <QObject>
#include <QMap>
#include <name_pair.h>

//class structmetatype
//{
//public:
//    virtual ~structmetatype(){}
//    virtual void  operation() = 0;
//    QMap<int,name_pair> structpair;
//};
class struct_description
{
public:
    QString tytpename;
    QMap<int,name_pair*> structpair;
    QMap<QString,QString> structpair_nameindex;//variablenamefirst then vtype
    void operation();

};
#endif // STRUCTMETATYPE_H
