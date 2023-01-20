#ifndef STRUCT_EDITOR_H
#define STRUCT_EDITOR_H

#include <QWidget>
#include "structmetatype.h"

namespace Ui {
class struct_editor;
}

class struct_editor : public QWidget
{
    Q_OBJECT

public:
    explicit struct_editor(QWidget *parent = nullptr);
    ~struct_editor();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

signals:
    void sig_new_struct_created(struct_description structnew);
    void sig_new_struct_finished();
    void sig_start_gen(QString target);

private:
    Ui::struct_editor *ui;
};

#endif // STRUCT_EDITOR_H
