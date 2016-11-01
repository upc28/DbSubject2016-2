/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *Btn_load;
    QLabel *Lab_path;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Ledit_num;
    QLineEdit *Ledit_major;
    QLineEdit *Ledit_name;
    QLineEdit *Ledit_gender;
    QPushButton *Btn_insert;
    QPushButton *Btn_query;
    QPushButton *pushButton;
    QLabel *label_5;
    QLineEdit *Ledit_reward;
    QTableView *tableView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(539, 392);
        Btn_load = new QPushButton(Widget);
        Btn_load->setObjectName(QStringLiteral("Btn_load"));
        Btn_load->setGeometry(QRect(390, 20, 75, 25));
        Lab_path = new QLabel(Widget);
        Lab_path->setObjectName(QStringLiteral("Lab_path"));
        Lab_path->setGeometry(QRect(50, 20, 311, 25));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 50, 431, 181));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 28, 54, 20));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(225, 28, 54, 20));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 68, 54, 20));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(225, 68, 54, 20));
        label_4->setAlignment(Qt::AlignCenter);
        Ledit_num = new QLineEdit(groupBox);
        Ledit_num->setObjectName(QStringLiteral("Ledit_num"));
        Ledit_num->setGeometry(QRect(80, 25, 141, 25));
        Ledit_major = new QLineEdit(groupBox);
        Ledit_major->setObjectName(QStringLiteral("Ledit_major"));
        Ledit_major->setGeometry(QRect(80, 65, 141, 25));
        Ledit_name = new QLineEdit(groupBox);
        Ledit_name->setObjectName(QStringLiteral("Ledit_name"));
        Ledit_name->setGeometry(QRect(280, 25, 113, 25));
        Ledit_gender = new QLineEdit(groupBox);
        Ledit_gender->setObjectName(QStringLiteral("Ledit_gender"));
        Ledit_gender->setGeometry(QRect(280, 65, 113, 25));
        Btn_insert = new QPushButton(groupBox);
        Btn_insert->setObjectName(QStringLiteral("Btn_insert"));
        Btn_insert->setGeometry(QRect(190, 140, 75, 30));
        Btn_query = new QPushButton(groupBox);
        Btn_query->setObjectName(QStringLiteral("Btn_query"));
        Btn_query->setGeometry(QRect(290, 140, 75, 30));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 140, 75, 30));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 110, 54, 20));
        label_5->setAlignment(Qt::AlignCenter);
        Ledit_reward = new QLineEdit(groupBox);
        Ledit_reward->setObjectName(QStringLiteral("Ledit_reward"));
        Ledit_reward->setGeometry(QRect(80, 107, 311, 25));
        tableView = new QTableView(Widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 240, 431, 141));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        Btn_load->setText(QApplication::translate("Widget", "\350\257\273\345\217\226", 0));
        Lab_path->setText(QApplication::translate("Widget", "......................................................", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\345\212\237\350\203\275", 0));
        label->setText(QApplication::translate("Widget", "\345\255\246\345\217\267", 0));
        label_2->setText(QApplication::translate("Widget", "\345\247\223\345\220\215", 0));
        label_3->setText(QApplication::translate("Widget", "\344\270\223\344\270\232", 0));
        label_4->setText(QApplication::translate("Widget", "\346\200\247\345\210\253", 0));
        Btn_insert->setText(QApplication::translate("Widget", "\346\217\222\345\205\245", 0));
        Btn_query->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", 0));
        pushButton->setText(QApplication::translate("Widget", "\344\277\256\346\224\271", 0));
        label_5->setText(QApplication::translate("Widget", "\345\245\226\345\212\261", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
