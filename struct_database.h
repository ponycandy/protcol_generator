#ifndef STRUCT_DATABASE_H
#define STRUCT_DATABASE_H

#include <QObject>
#include <structmetatype.h>
#include <QMap>
#include <typelist.h>
#include "meta_struct_list.h"
#include "writer_manage.h"
class struct_database : public QObject
{
    Q_OBJECT
public:
    explicit struct_database(QObject *parent = nullptr);
    QString parsefilename;
    QString makefilename;
    QString headerfilename;

    void delete_struct(QString structname);
    QMap<int,struct_description> gettypelist();
    void update_structlist();
    metafile* create_metafile(QString type,QString name);
    writer_manage* m_writer;
    void add_struct(QString structname);

     QMap<int,struct_description> structlist;
     QMap<QString,struct_description> structlist_nameindex;
     QMap<QString,complex_TYPE*> meta_struct_listss;//structname,struct_contens

     int current_item_num_total=0;
public slots:
    void slot_on_new_added(struct_description structnew);
    void slot_on_generated(QString targetname);

signals:

};

#endif // STRUCT_DATABASE_H
