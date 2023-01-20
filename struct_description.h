#ifndef STRUCT_DESCRIPTION_H
#define STRUCT_DESCRIPTION_H

#include <QObject>
#include <name_pair.h>
#include <QMap>
class struct_description : public QObject
{
    Q_OBJECT
public:
    explicit struct_description(QObject *parent = nullptr);

    QString tytpename;
    QMap<int,name_pair*> structpair;
    QMap<QString,QString> structpair_nameindex;//variablenamefirst then vtype
    void operation();
signals:

};

#endif // STRUCT_DESCRIPTION_H
