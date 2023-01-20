#ifndef MAINFILEGENERATOR_H
#define MAINFILEGENERATOR_H

#include <QObject>
#include <structmetatype.h>
class mainfilegenerator : public QObject
{
    Q_OBJECT
public:
    explicit mainfilegenerator(QObject *parent = nullptr);

    QMap<int,struct_description> structlist;
    QMap<QString,struct_description> structlist_nameindex;
signals:

public slots:
    void slot_start_gen(QString target);
};

#endif // MAINFILEGENERATOR_H
