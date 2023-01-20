#ifndef COMPLEX_TYPE_H
#define COMPLEX_TYPE_H
#include "metafile.h"
#include "QMap"
class complex_TYPE:public metafile
{
public:
    complex_TYPE();
    void operation(int i) override;
    void setparents(metafile *parents) override;
    void rename_iterate() override;
    void setvariablename(QString name) override;
    int getsize() override;
    QString getvariablename() override;
    metafile * deep_copy() override;
    QString self_name;
    int size=-1;
    QMap<int,metafile*> contents;
    QString variable_name;//所有文件使用selfname，这个不会在头文件里面内建，因为会造成无法赋值的情况

};

#endif // COMPLEX_TYPE_H
