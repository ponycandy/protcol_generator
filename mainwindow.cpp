#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtDebug"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<"type name"<<"variable name";
    ui->tableWidget->setHorizontalHeaderLabels(header);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString struct_name=ui->lineEdit->text();
    int availabe_row=ui->tableWidget->rowCount();
//    ui->tableWidget->insertRow(availabe_row);
    qDebug()<<availabe_row;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString variable_name=ui->lineEdit_2->text();
    QString type_name=ui->lineEdit_4->text();
    int availabe_row=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(availabe_row);
    ui->tableWidget->setItem(availabe_row,0,new QTableWidgetItem(type_name));
    ui->tableWidget->setItem(availabe_row,1,new QTableWidgetItem(variable_name));

}

void MainWindow::on_pushButton_3_clicked()
{
    //    QString variable_name=ui->lineEdit_2->text();


}

void MainWindow::on_pushButton_4_clicked()
{
    int curow = ui->tableWidget->currentRow();
    QString asd=ui->tableWidget->item(curow,0)->text();
    qDebug()<<curow;
    ui->tableWidget->removeRow(curow);
}
