#include "struct_database.h"
#include "typelist.h"
#include "QtDebug"
#include "f_manager.h"
struct_database::struct_database(QObject *parent) : QObject(parent)
{
    parsefilename="D:/Qt/prj_dir/Serilization_Protcols/debug/parse.txt";
    makefilename="D:/Qt/prj_dir/Serilization_Protcols/debug/make.txt";
    headerfilename="D:/Qt/prj_dir/Serilization_Protcols/debug/header.txt";
    m_writer=new writer_manage;
    m_writer->parsefilename=parsefilename;
    m_writer->makefilename=makefilename;
    m_writer->headerfilename=headerfilename;
}

QMap<int, struct_description> struct_database::gettypelist()
{
    return  structlist;
}

metafile *struct_database::create_metafile(QString type, QString name)
{
    if(type=="char" || type=="Char")
    {
        char_type *target=new char_type;
        target->variable_name=name;
        return target;
    }
    if(type=="int" || type=="Int")
    {
        Int_TYPE *target=new Int_TYPE;
        target->variable_name=name;
        return target;
    }
    if(type=="short" || type=="Short")
    {
        short_type *target=new short_type;
        target->variable_name=name;
        return target;
    }
    if(type=="float" || type=="Float")
    {
        float_type *target=new float_type;
        target->variable_name=name;
        return target;
    }
    if(type.contains("Qvector<",Qt::CaseSensitive)) //注意，这是唯一的合法写法，请不要在内部的包含变量中出现这个字段！！
    {
        //禁用双容器，也就是qvector嵌套，问题就没有了...吧？
        //这样，复制的时候，就可以单纯的计算长度了，对吧？
        vector_type *target=new vector_type;
        QString containtype=f_get_text_between("<",">",type);
        target->containedtype=containtype;
        QString counter=f_get_text_between(">","",type);
        target->countname=counter;//这一部分不和其它耦合，也就是说纯文本手改
        target->m_writer=m_writer;
//        QString reslut=
        target->variable_name=name;
        target->meta_struct_listss=meta_struct_listss;//qvector绝对不会用来承载普通类型！！普通类型用数组！！
        target->m_base=this;
        return target;
    }
    if(type.contains("[",Qt::CaseSensitive)) //任意数组,总是假定数组内部不再添加数组
    {
        Tulple_type *target=new Tulple_type;
        QString number=f_get_text_between("[","]",type);
        QString containedtype=f_get_text_between("","[",type);
        target->tupletype=containedtype;
        target->count=number.toInt();

        target->m_writer=m_writer;
        target->variable_name=name;
        target->m_base=this;//qvector绝对不会用来承载普通类型！！普通类型用数组！！
        return target;
    }
    else//上述类型未命中，统一为复合类型
    {
        metafile *target0=meta_struct_listss.value(type);//metafile没有variable变量，必须进行recast!!
//        complex_TYPE *target1=dynamic_cast<complex_TYPE*>(target0);
        metafile *target=target0->deep_copy();
        target->setvariablename(name);
        return target;
    }
}

void struct_database::slot_on_generated(QString targetname)
{
    m_writer->current_writing_file=m_writer->makefilename;
    m_writer->write_start_make(targetname);
    meta_struct_listss.value(targetname)->rename_iterate();
    meta_struct_listss.value(targetname)->operation(1);//1 mean make function 0 mean parse function
    m_writer->write_end();

    m_writer->writingcontxt.clear();
    m_writer->current_writing_file=m_writer->parsefilename;
    m_writer->write_start_parse(targetname);
    meta_struct_listss.value(targetname)->operation(0);//1 mean make function 0 mean parse function
    m_writer->write_end_1();

}

void struct_database::slot_on_new_added(struct_description structnew)
{
    structlist_nameindex.insert(structnew.tytpename,structnew);
    current_item_num_total++;
    structlist.insert(current_item_num_total,structnew);

    QMap<int, name_pair*>::const_iterator iter = structnew.structpair.cbegin();

    complex_TYPE *newstruct=new complex_TYPE;

    newstruct->self_name=structnew.tytpename;

    int order=1;
    while (iter != structnew.structpair.cend())
    {
        metafile *new_meta=create_metafile(iter.value()->type,iter.value()->name);
        new_meta->m_writer=m_writer;new_meta->setparents(newstruct);

        newstruct->contents.insert(order,new_meta);
        order++;
        ++iter;
    }
    meta_struct_listss.insert(structnew.tytpename,newstruct);

}
