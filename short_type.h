#ifndef SHORT_TYPE_H
#define SHORT_TYPE_H

#include <QObject>
#include "metafile.h"
class short_type : public QObject,public metafile
{
    Q_OBJECT
public:
    explicit short_type(QObject *parent = nullptr);
    void  operation(int i) override;
    void rename_iterate() override;
    QString getvariablename() override;
    metafile *deep_copy() override;
    void setparents(metafile* parents) override;
    void setvariablename(QString name) override;
     int getsize() override;
    QString variable_name;
signals:

};

#endif // SHORT_TYPE_H
