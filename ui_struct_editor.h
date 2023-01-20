/********************************************************************************
** Form generated from reading UI file 'struct_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRUCT_EDITOR_H
#define UI_STRUCT_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_struct_editor
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QPushButton *pushButton_5;
    QWidget *tab_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;
    QPushButton *pushButton_4;

    void setupUi(QWidget *struct_editor)
    {
        if (struct_editor->objectName().isEmpty())
            struct_editor->setObjectName(QStringLiteral("struct_editor"));
        struct_editor->resize(761, 596);
        gridLayout = new QGridLayout(struct_editor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(struct_editor);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(220, 190, 113, 20));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 190, 171, 21));
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 190, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 80, 113, 20));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 80, 111, 21));
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 120, 113, 20));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 140, 111, 21));
        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(120, 150, 113, 20));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 120, 81, 20));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 150, 81, 20));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 54, 12));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(470, 140, 75, 23));
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 200, 601, 301));
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(370, 140, 75, 23));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(struct_editor);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(struct_editor);
    } // setupUi

    void retranslateUi(QWidget *struct_editor)
    {
        struct_editor->setWindowTitle(QApplication::translate("struct_editor", "Form", Q_NULLPTR));
        label_4->setText(QApplication::translate("struct_editor", "enter the target struct", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("struct_editor", "check", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("struct_editor", "protocols", Q_NULLPTR));
        pushButton->setText(QApplication::translate("struct_editor", "add new struct", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("struct_editor", "add new member", Q_NULLPTR));
        label->setText(QApplication::translate("struct_editor", "variable name", Q_NULLPTR));
        label_2->setText(QApplication::translate("struct_editor", "type name", Q_NULLPTR));
        label_3->setText(QApplication::translate("struct_editor", "struct", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("struct_editor", "delete", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("struct_editor", "finished", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("struct_editor", "struct_gen", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class struct_editor: public Ui_struct_editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRUCT_EDITOR_H
