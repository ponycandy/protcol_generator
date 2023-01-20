#include "complex_type.h"
#include "QtDebug"
complex_TYPE::complex_TYPE()
{

}

void complex_TYPE::operation(int i)
{
    if(i==1)
    {
        QMap<int, metafile*>::const_iterator iter =contents.cbegin();
        while (iter != contents.cend())
        {
            iter.value()->operation(i);//不允许operation用来换名字，必须有一个单独的通道
            ++iter;
        }
    }
    else
    {
        QMap<int, metafile*>::const_iterator iter =contents.cbegin();
        while (iter != contents.cend())
        {
            iter.value()->operation(0);//不允许operation用来换名字，必须有一个单独的通道
            ++iter;
        }
    }
}


void complex_TYPE::setparents(metafile *parents)
{
    parentmetafile=parents;

}

void complex_TYPE::rename_iterate()
{
    if(variable_name=="")
    {
        setvariablename("ptopic");
    }
    else
    {
        setvariablename(parentmetafile->getvariablename()+"."+variable_name);
    }
    qDebug()<<variable_name;
    QMap<int, metafile*>::const_iterator iter =contents.cbegin();
    int order=1;
    while (iter != contents.cend())
    {
        iter.value()->rename_iterate();
        ++iter;
    }
}

void complex_TYPE::setvariablename(QString name)
{
    variable_name=name;
}

int complex_TYPE::getsize()
{
    if(size<0)//代表初次计算
    {
        size=0;
        QMap<int, metafile*>::const_iterator iter =contents.cbegin();
        while (iter != contents.cend())
        {
            size+=iter.value()->getsize();
            ++iter;
        }
        return size;
    }
    else
    {
        return size;
    }
}

QString complex_TYPE::getvariablename()
{
    return variable_name;
}





metafile *complex_TYPE::deep_copy()
{
    complex_TYPE *newtype=new complex_TYPE;
    newtype->self_name=self_name;
    newtype->variable_name=variable_name;//不要在interface里面保留和使用变量，会出现无法预测的行为
    newtype->m_writer=m_writer;
    QMap<int,metafile*> newcontents;
    QMap<int, metafile*>::const_iterator iter =contents.cbegin();
    int order=1;
    while (iter != contents.cend())
    {
        metafile* files=iter.value()->deep_copy();//可能重命名要来一下...
        files->setparents(newtype);
        newcontents.insert(order,files);
        order++;
        ++iter;
    }
    newtype->contents=newcontents;

    return newtype;


}
