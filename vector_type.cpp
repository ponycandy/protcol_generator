#include "vector_type.h"
#include <struct_database.h>

vector_type::vector_type(QObject *parent) : QObject(parent)
{

}

void vector_type::operation(int i)
{
    if(i==1)
    {
        int current_row=m_writer->get_current_row();

        QString conshi;
        metafile *temperory=m_base->create_metafile(containedtype,"whatever");
        int sizef=temperory->getsize();
        QString s = QString::number(sizef);
        conshi="offset="+s+";";

        m_writer->writefile("",conshi,current_row);

        m_writer->writefile("","for(int i=0;i<"+countname+";i++)",current_row);
        //这部分请手动调节，不接受自动化
        //这部分输入太过于抽象了
        m_writer->writefile("","{",0);

        QString conshj;
        conshj="memcpy((void *)(ptData), (void *)&"+variable_name+"[i], offset);";
        m_writer->writefile("",conshj,0);
        m_writer->writefile("","ptData += offset;",0);
        m_writer->writefile("","size+=offset;",0);
        m_writer->writefile("","}",0);

        return;
    }
    else
    {
        QString conshi;
        metafile *temperory=m_base->create_metafile(containedtype,"whatever");
        int sizef=temperory->getsize();
        QString s = QString::number(sizef);
        conshi="offset="+s+";";

        m_writer->writefile("",conshi,0);

        m_writer->writefile("","for(int i=0;i<"+countname+";i++)",0);
        m_writer->writefile("","{",0);
        m_writer->writefile("",containedtype+" single_object;",0);

        QString conshj;
        conshj="memcpy((void *)&single_object,(void *)(ptData),  sizeof ("+containedtype+"));";
        m_writer->writefile("",conshj,0);
        m_writer->writefile("","ptData += offset;",0);
        m_writer->writefile("","size+=offset;",0);
        m_writer->writefile("",variable_name+".append(single_object);",0);
        m_writer->writefile("","}",0);
        return;
    }
}

void vector_type::rename_iterate()
{
    setvariablename(parentmetafile->getvariablename()+"."+variable_name);

    qDebug()<<variable_name;
}

QString vector_type::getvariablename()
{
    return variable_name;

}

metafile *vector_type::deep_copy()
{
    vector_type *target=new vector_type;
    target->containedtype=containedtype;
    target->countname=countname;//这一部分不和其它耦合，也就是说纯文本手改
    target->variable_name=variable_name;
    target->m_writer=m_writer;
    target->meta_struct_listss=meta_struct_listss;
    return target;
}

void vector_type::setparents(metafile *parents)
{
    parentmetafile=parents;
}

void vector_type::setvariablename(QString name)
{
    variable_name=name;
}

int vector_type::getsize()
{
    return 0;
}
