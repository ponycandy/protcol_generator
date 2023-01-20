#include "tulple_type.h"
#include "struct_database.h"
Tulple_type::Tulple_type(QObject *parent) : QObject(parent)
{

}

void Tulple_type::operation(int i)
{
    getsize();
    if(i==1)
    {
        int current_row=m_writer->get_current_row();

        QString conshi;
        QString s = QString::number(self_size);
        conshi="offset="+s+";" + "memcpy((void *)(ptData), (void *)&"+variable_name+", offset);ptData += offset;size+=offset;";
        m_writer->writefile("",conshi,current_row);
        return;
    }
    else
    {
        QString conshi;
        QString s = QString::number(self_size);
        conshi="offset="+s+";" + "memcpy((void *)&"+variable_name+",(void *)(ptData),  offset);"+"ptData += offset;";
        m_writer->writefile("",conshi,0);
        return;

    }
}

void Tulple_type::rename_iterate()
{
    setvariablename(parentmetafile->getvariablename()+"."+variable_name);

    qDebug()<<variable_name;
}

QString Tulple_type::getvariablename()
{
    return  variable_name;
}

metafile *Tulple_type::deep_copy()
{

    Tulple_type *target=new Tulple_type;
    target->count=count;
    target->self_size=self_size;//这一部分不和其它耦合，也就是说纯文本手改
    target->variable_name=variable_name;
    target->m_writer=m_writer;
    target->m_base=m_base;
    return target;
}

void Tulple_type::setparents(metafile *parents)
{
    parentmetafile=parents;
}

void Tulple_type::setvariablename(QString name)
{
    variable_name=name;
}

int Tulple_type::getsize()
{
    if(self_size<0)
    {
        metafile *temperory=m_base->create_metafile(tupletype,"whatever");
        self_size=temperory->getsize()*count;
        return self_size;
    }
    return self_size;
}
