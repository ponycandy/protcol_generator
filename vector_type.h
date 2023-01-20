#ifndef VECTOR_TYPE_H
#define VECTOR_TYPE_H

#include <QObject>
#include <metafile.h>
#include <writer_manage.h>
#include <complex_type.h>
class struct_database;
class vector_type : public QObject,public metafile
{
    Q_OBJECT
public:
    explicit vector_type(QObject *parent = nullptr);
    void  operation(int i) override;
    void rename_iterate() override;
    QString getvariablename() override;
    metafile *deep_copy() override;
    void setparents(metafile* parents) override;
    void setvariablename(QString name) override;
     int getsize() override;
    QString variable_name;
    QString countname;
    QString containedtype;
    int iterator;
    struct_database *m_base;

    QMap<QString,complex_TYPE*> meta_struct_listss;
signals:

};

#endif // VECTOR_TYPE_H
