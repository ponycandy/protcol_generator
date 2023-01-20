#ifndef CHAR_TYPE_H
#define CHAR_TYPE_H

#include <QObject>
#include <metafile.h>

class char_type : public QObject,public metafile
{
    Q_OBJECT
public:
    explicit char_type(QObject *parent = nullptr);
    void operation(int i) override;
    void setparents(metafile *parents) override;
    void rename_iterate() override;
    void setvariablename(QString name) override;
    int getsize() override;
    QString getvariablename() override;
    metafile *deep_copy() override;

    QString variable_name;
signals:

};

#endif // CHAR_TYPE_H
