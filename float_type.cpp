#include "float_type.h"

float_type::float_type(QObject *parent) : QObject(parent)
{

}
void float_type::operation(int i)
{
    if(i==1)//make
    {
        int current_row=m_writer->get_current_row();
        m_writer->writefile(m_writer->parsefilename,"offset=4;memcpy((void *)(ptData), (void *)&"+variable_name+", offset);ptData += offset;size+=offset;",current_row);
        return;
    }
    else
    {
        m_writer->writefile(m_writer->parsefilename,"offset=4;memcpy((void *)&"+variable_name+",(void *)(ptData),  offset);"+"ptData += offset;",0);
        return;
    }
}

void float_type::setparents(metafile *parents)
{
    parentmetafile=parents;
    //    reset_variablename();
}

void float_type::rename_iterate()
{
    //如果在最表层，则parent为ptopic
    setvariablename(parentmetafile->getvariablename()+"."+variable_name);

    qDebug()<<variable_name;
}

void float_type::setvariablename(QString name)
{
    variable_name=name;
}

int float_type::getsize()
{
    return 4;
}

QString float_type::getvariablename()
{
    return  variable_name;
}



metafile *float_type::deep_copy()
{
    float_type *type=new float_type;
    type->variable_name=this->variable_name;
    type->m_writer=m_writer;
    return  type;
}
