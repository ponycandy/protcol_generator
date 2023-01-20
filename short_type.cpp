#include "short_type.h"

short_type::short_type(QObject *parent) : QObject(parent)
{

}

void short_type::operation(int i)
{
    if(i==1)//make
    {
        m_writer->writefile("0","offset=2;memcpy((void *)(ptData), (void *)&"+variable_name+", offset);ptData += offset;size+=offset;",1);
        return;
    }
    else
    {
        m_writer->writefile(m_writer->parsefilename,"offset=2;memcpy((void *)&"+variable_name+",(void *)(ptData),  offset);"+"ptData += offset;",0);
        return;
        return;
    }
}

void short_type::rename_iterate()
{
    setvariablename(parentmetafile->getvariablename()+"."+variable_name);

    qDebug()<<variable_name;
}

QString short_type::getvariablename()
{
    return  variable_name;
}

metafile *short_type::deep_copy()
{
    short_type *type=new short_type;
    type->variable_name=this->variable_name;
    type->m_writer=m_writer;
    return  type;
}

void short_type::setparents(metafile *parents)
{
    parentmetafile=parents;
}

void short_type::setvariablename(QString name)
{
    variable_name=name;
}

int short_type::getsize()
{
    return 2;
}
