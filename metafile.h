#ifndef METAFILE_H
#define METAFILE_H
#include "QString"
#include "writer_manage.h"
#include "QtDebug"
class metafile
{
public:
    virtual ~metafile(){}
    virtual void  operation(int i) = 0;
    virtual void rename_iterate()=0;
    virtual QString getvariablename()=0;
    virtual metafile* deep_copy()=0;
    virtual void setparents(metafile* parents)=0;
    virtual void setvariablename(QString name)=0;
    virtual int getsize()=0;
    metafile *parentmetafile;
    writer_manage* m_writer;
};
#endif // METAFILE_H
