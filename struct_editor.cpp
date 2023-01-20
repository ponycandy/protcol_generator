#include "struct_editor.h"
#include "ui_struct_editor.h"
#include "QtDebug"
struct_editor::struct_editor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::struct_editor)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<"type name"<<"variable name";
    ui->tableWidget->setHorizontalHeaderLabels(header);
}

struct_editor::~struct_editor()
{
    delete ui;
}

void struct_editor::on_pushButton_2_clicked()
{
    QString variable_name=ui->lineEdit_2->text();
    QString type_name=ui->lineEdit_3->text();
    int availabe_row=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(availabe_row);
    ui->tableWidget->setItem(availabe_row,0,new QTableWidgetItem(type_name));
    ui->tableWidget->setItem(availabe_row,1,new QTableWidgetItem(variable_name));
}

void struct_editor::on_pushButton_3_clicked()
{
    int curow = ui->tableWidget->currentRow();
    QString asd=ui->tableWidget->item(curow,0)->text();
    qDebug()<<curow;
    ui->tableWidget->removeRow(curow);
}

void struct_editor::on_pushButton_clicked()
{
    QString structname=ui->lineEdit->text();
    struct_description struct_new;
    struct_new.tytpename=structname;
    for(int row=0; row<ui->tableWidget->rowCount(); row++)
    {

            QTableWidgetItem* type_name = ui->tableWidget->item(row,0);
            QTableWidgetItem* variable_name = ui->tableWidget->item(row,1);
            name_pair *a_pair=new name_pair;
            a_pair->name=variable_name->text();a_pair->type=type_name->text();
            struct_new.structpair.insert(row+1,a_pair);
            struct_new.structpair_nameindex.insert(a_pair->name,a_pair->type);

    }

    emit sig_new_struct_created(struct_new);

//    QString type_name=ui->lineEdit_3->text();
//    int availabe_row=ui->tableWidget->rowCount();
//    ui->tableWidget->insertRow(availabe_row);
//    ui->tableWidget->setItem(availabe_row,0,new QTableWidgetItem(type_name));
//    ui->tableWidget->setItem(availabe_row,1,new QTableWidgetItem(variable_name));
}

void struct_editor::on_pushButton_4_clicked()
{

}

void struct_editor::on_pushButton_5_clicked()
{
    QString targetname=ui->lineEdit_4->text();

    emit sig_start_gen(targetname);


}
