/********************************************************************************
** Form generated from reading UI file 'LPtatle.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LPTATLE_H
#define UI_LPTATLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_LPtatle
{
public:
    QTableView *tableView;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *sort;
    QCheckBox *adm;
    QCheckBox *man;
    QCheckBox *us;

    void setupUi(QDialog *LPtatle)
    {
        if (LPtatle->objectName().isEmpty())
            LPtatle->setObjectName(QString::fromUtf8("LPtatle"));
        LPtatle->resize(566, 494);
        tableView = new QTableView(LPtatle);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 381, 301));
        label = new QLabel(LPtatle);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 320, 55, 16));
        lineEdit = new QLineEdit(LPtatle);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 320, 113, 22));
        sort = new QPushButton(LPtatle);
        sort->setObjectName(QString::fromUtf8("sort"));
        sort->setGeometry(QRect(210, 360, 93, 28));
        adm = new QCheckBox(LPtatle);
        adm->setObjectName(QString::fromUtf8("adm"));
        adm->setGeometry(QRect(100, 350, 81, 20));
        man = new QCheckBox(LPtatle);
        man->setObjectName(QString::fromUtf8("man"));
        man->setGeometry(QRect(100, 370, 81, 20));
        us = new QCheckBox(LPtatle);
        us->setObjectName(QString::fromUtf8("us"));
        us->setGeometry(QRect(100, 390, 81, 20));

        retranslateUi(LPtatle);

        QMetaObject::connectSlotsByName(LPtatle);
    } // setupUi

    void retranslateUi(QDialog *LPtatle)
    {
        LPtatle->setWindowTitle(QApplication::translate("LPtatle", "LPtatle", nullptr));
        label->setText(QApplication::translate("LPtatle", "Login", nullptr));
        sort->setText(QApplication::translate("LPtatle", "Sort", nullptr));
        adm->setText(QApplication::translate("LPtatle", "admin", nullptr));
        man->setText(QApplication::translate("LPtatle", "manager", nullptr));
        us->setText(QApplication::translate("LPtatle", "user", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LPtatle: public Ui_LPtatle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LPTATLE_H
