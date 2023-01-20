#include "int_type.h"
Int_TYPE::Int_TYPE(QObject *parent) : QObject(parent)
{
    paste_content_parse_1="memcpy((void *)&PTtopic.";
    paste_content_parse_3=",(void *)(ptData),  4);offset =4;ptData += offset;";
}

void Int_TYPE::operation(int i)
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

void Int_TYPE::setparents(metafile *parents)
{
    parentmetafile=parents;
    //    reset_variablename();
}

void Int_TYPE::rename_iterate()
{
    //如果在最表层，则parent为ptopic
    setvariablename(parentmetafile->getvariablename()+"."+variable_name);

    qDebug()<<variable_name;
}

void Int_TYPE::setvariablename(QString name)
{
    variable_name=name;
}

int Int_TYPE::getsize()
{
    return 4;
}

QString Int_TYPE::getvariablename()
{
    return  variable_name;
}



metafile *Int_TYPE::deep_copy()
{
    Int_TYPE *type=new Int_TYPE;
    type->variable_name=this->variable_name; type->variable_name.append("$");type->variable_name.remove("$");
    type->m_writer=m_writer;
    return  type;
}
