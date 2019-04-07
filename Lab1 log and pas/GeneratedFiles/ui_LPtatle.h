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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LPtatle
{
public:
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QRadioButton *ra;
    QRadioButton *rm;
    QRadioButton *ru;
    QPushButton *sort;

    void setupUi(QDialog *LPtatle)
    {
        if (LPtatle->objectName().isEmpty())
            LPtatle->setObjectName(QString::fromUtf8("LPtatle"));
        LPtatle->resize(574, 468);
        verticalLayout_2 = new QVBoxLayout(LPtatle);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(LPtatle);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(LPtatle);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(LPtatle);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        ra = new QRadioButton(LPtatle);
        ra->setObjectName(QString::fromUtf8("ra"));

        verticalLayout->addWidget(ra);

        rm = new QRadioButton(LPtatle);
        rm->setObjectName(QString::fromUtf8("rm"));

        verticalLayout->addWidget(rm);

        ru = new QRadioButton(LPtatle);
        ru->setObjectName(QString::fromUtf8("ru"));

        verticalLayout->addWidget(ru);


        horizontalLayout_2->addLayout(verticalLayout);

        sort = new QPushButton(LPtatle);
        sort->setObjectName(QString::fromUtf8("sort"));

        horizontalLayout_2->addWidget(sort);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(LPtatle);

        QMetaObject::connectSlotsByName(LPtatle);
    } // setupUi

    void retranslateUi(QDialog *LPtatle)
    {
        LPtatle->setWindowTitle(QApplication::translate("LPtatle", "LPtatle", nullptr));
        label->setText(QApplication::translate("LPtatle", "Login", nullptr));
        ra->setText(QApplication::translate("LPtatle", "Admin", nullptr));
        rm->setText(QApplication::translate("LPtatle", "Manager", nullptr));
        ru->setText(QApplication::translate("LPtatle", "User", nullptr));
        sort->setText(QApplication::translate("LPtatle", "Sort", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LPtatle: public Ui_LPtatle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LPTATLE_H
