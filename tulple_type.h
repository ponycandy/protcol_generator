#ifndef TULPLE_TYPE_H
#define TULPLE_TYPE_H

#include <QObject>
#include <metafile.h>
class struct_database;
class Tulple_type : public QObject,public metafile
{
    Q_OBJECT
public:
    explicit Tulple_type(QObject *parent = nullptr);
    void  operation(int i) override;
    void rename_iterate() override;
    QString getvariablename() override;
    metafile *deep_copy() override;
    void setparents(metafile* parents) override;
    void setvariablename(QString name) override;
     int getsize() override;
    QString variable_name;
    int count;
    int self_size=-1;
    QString tupletype;
    struct_database *m_base;
signals:

};

#endif // TULPLE_TYPE_H
