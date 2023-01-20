#ifndef INT_TYPE_H
#define INT_TYPE_H

#include <QObject>
#include <metafile.h>
#include <writer_manage.h>
class Int_TYPE : public QObject,public metafile
{
    Q_OBJECT
public:
    explicit Int_TYPE(QObject *parent = nullptr);
    void operation(int i) override;
    void setparents(metafile *parents) override;
    void rename_iterate() override;
    void setvariablename(QString name) override;
    int getsize() override;
    QString getvariablename() override;
    metafile *deep_copy() override;
    QString paste_content_parse;
    QString paste_content_parse_1;
    QString paste_content_parse_2;
    QString paste_content_parse_3;
    QString variable_name;//所有文件使用selfname，这个不会在头文件里面内建，因为会造成无法赋值的情况

signals:

};

#endif // INT_TYPE_H
