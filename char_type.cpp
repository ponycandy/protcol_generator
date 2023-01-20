#include "char_type.h"

char_type::char_type(QObject *parent) : QObject(parent)
{

}
void char_type::operation(int i)
{
    if(i==1)//make
    {
        int current_row=m_writer->get_current_row();
        m_writer->writefile(m_writer->parsefilename,"offset=1;memcpy((void *)(ptData), (void *)&"+variable_name+", offset);ptData += offset;size+=offset;",current_row);
        return;
    }
    else
    {
        m_writer->writefile(m_writer->parsefilename,"offset=1;memcpy((void *)&"+variable_name+",(void *)(ptData),  offset);"+"ptData += offset;",0);
        return;
    }
}

void char_type::setparents(metafile *parents)
{
    parentmetafile=parents;
    //    reset_variablename();
}

void char_type::rename_iterate()
{
    //如果在最表层，则parent为ptopic
    setvariablename(parentmetafile->getvariablename()+"."+variable_name);

    qDebug()<<variable_name;
}

void char_type::setvariablename(QString name)
{
    variable_name=name;
}

int char_type::getsize()
{
    return 1;
}

QString char_type::getvariablename()
{
    return  variable_name;
}



metafile *char_type::deep_copy()
{
    char_type *type=new char_type;
    type->variable_name=this->variable_name;
    type->m_writer=m_writer;
    return  type;
}
