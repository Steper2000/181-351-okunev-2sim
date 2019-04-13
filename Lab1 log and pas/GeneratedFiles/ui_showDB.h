/********************************************************************************
** Form generated from reading UI file 'showDB.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWDB_H
#define UI_SHOWDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_showDB
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *sort;
    QPushButton *delsor;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_5;

    void setupUi(QDialog *showDB)
    {
        if (showDB->objectName().isEmpty())
            showDB->setObjectName(QString::fromUtf8("showDB"));
        showDB->resize(399, 539);
        gridLayout = new QGridLayout(showDB);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(showDB);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(showDB);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        lineEdit = new QLineEdit(showDB);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        sort = new QPushButton(showDB);
        sort->setObjectName(QString::fromUtf8("sort"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sort->sizePolicy().hasHeightForWidth());
        sort->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(sort);

        delsor = new QPushButton(showDB);
        delsor->setObjectName(QString::fromUtf8("delsor"));

        verticalLayout->addWidget(delsor);


        gridLayout->addLayout(verticalLayout, 1, 1, 3, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(showDB);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        lineEdit_2 = new QLineEdit(showDB);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(showDB);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        lineEdit_3 = new QLineEdit(showDB);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_5->addWidget(lineEdit_3);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(showDB);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_4 = new QLineEdit(showDB);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_2->addWidget(lineEdit_4);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(showDB);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_5 = new QLineEdit(showDB);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout->addWidget(lineEdit_5);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);


        retranslateUi(showDB);

        QMetaObject::connectSlotsByName(showDB);
    } // setupUi

    void retranslateUi(QDialog *showDB)
    {
        showDB->setWindowTitle(QApplication::translate("showDB", "showDB", nullptr));
        label_5->setText(QApplication::translate("showDB", "Company", nullptr));
        sort->setText(QApplication::translate("showDB", "Sort", nullptr));
        delsor->setText(QApplication::translate("showDB", "Delete Sort", nullptr));
        label->setText(QApplication::translate("showDB", "Industry", nullptr));
        label_2->setText(QApplication::translate("showDB", "Date", nullptr));
        label_3->setText(QApplication::translate("showDB", "Tax", nullptr));
        label_4->setText(QApplication::translate("showDB", "Sum", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showDB: public Ui_showDB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWDB_H
