#ifndef NAME_PAIR_H
#define NAME_PAIR_H

#include <QString>
#include <QMap>
class struct_description;
class name_pair
{
public:
    name_pair();
    QString type;
    QString name;
    QMap<QString,struct_description> structlist_nameindex;
};
#endif // NAME_PAIR_H
