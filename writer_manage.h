#ifndef WRITER_MANAGE_H
#define WRITER_MANAGE_H

#include <QObject>

class writer_manage : public QObject
{
    Q_OBJECT
public:
    explicit writer_manage(QObject *parent = nullptr);
    int get_current_row();
    void set_current_row(int row);
    void write_start_parse(QString target);
    void write_start_make(QString target);

    void write_end();
    void write_end_1();

    void writefile(QString txtfilename,QString content,int line);
    void setcurrent_writing_file(QString filename);
    QString getfilename();
    QString writingcontxt;
    QString parsefilename;
    QString makefilename;
    QString headerfilename;
    QString current_writing_file;
signals:

};

#endif // WRITER_MANAGE_H
