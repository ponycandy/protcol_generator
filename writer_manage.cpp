#include "writer_manage.h"
#include "f_manager.h"
writer_manage::writer_manage(QObject *parent) : QObject(parent)
{

}

int writer_manage::get_current_row()
{
    return 1;
}

void writer_manage::set_current_row(int row)
{

}

void writer_manage::write_start_parse(QString target)
{
    QString contens;
    contens= "void parsedata(const char *data, "+target+" &ptopic){";
    writefile(current_writing_file,contens,1);

    writefile(current_writing_file,"const char* ptData = data;",1);
    writefile(current_writing_file,"int offset;",1);
}

void writer_manage::write_start_make(QString target)
{
    QString contens;
    contens= "void makedata("+target+" ptopic, QByteArray &sending_data){";
    writefile(current_writing_file,contens,1);

    writefile(current_writing_file,"const char* ptData = pre_assigned_char",1);
    writefile(current_writing_file,"int offset,size;size=0;",1);

    //     const char* ptData = m_protcols_data;
}

void writer_manage::write_end()
{
    writefile(current_writing_file,"sending_data.setRawData(pre_assigned_char,size);",1);

    //     sending_data.setRawData(m_protcols_data,size);
    writefile(current_writing_file,"}",1);


    QFile file(current_writing_file);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream out(&file);
    file.close();
    file.open(QFile::WriteOnly | QFile::Text);



    out<<writingcontxt;
    file.close();

}

void writer_manage::write_end_1()
{
    writefile(current_writing_file,"}",1);


    QFile file(current_writing_file);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream out(&file);
    file.close();
    file.open(QFile::WriteOnly | QFile::Text);



    out<<writingcontxt;
    file.close();
}

void writer_manage::writefile(QString txtfilename, QString content, int line)
{
    writingcontxt.append(content);
    writingcontxt.append("\n");

}

void writer_manage::setcurrent_writing_file(QString filename)
{
    QFile file;
    file.setFileName(filename);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream out(&file);
    writingcontxt=out.readAll();
    writingcontxt.append("\n");

}

QString writer_manage::getfilename()
{
    return "1";

}
