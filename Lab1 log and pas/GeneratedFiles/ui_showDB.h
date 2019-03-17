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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showDB
{
public:
    QTableView *tableView;
    QPushButton *sort;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_5;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *lineEdit;

    void setupUi(QDialog *showDB)
    {
        if (showDB->objectName().isEmpty())
            showDB->setObjectName(QString::fromUtf8("showDB"));
        showDB->resize(936, 538);
        tableView = new QTableView(showDB);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(11, 11, 741, 331));
        sort = new QPushButton(showDB);
        sort->setObjectName(QString::fromUtf8("sort"));
        sort->setGeometry(QRect(480, 410, 93, 28));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sort->sizePolicy().hasHeightForWidth());
        sort->setSizePolicy(sizePolicy);
        widget = new QWidget(showDB);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 500, 311, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout->addWidget(lineEdit_5);

        widget1 = new QWidget(showDB);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(50, 470, 311, 26));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_4 = new QLineEdit(widget1);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_2->addWidget(lineEdit_4);

        widget2 = new QWidget(showDB);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(50, 400, 311, 41));
        horizontalLayout_4 = new QHBoxLayout(widget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        lineEdit_2 = new QLineEdit(widget2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);

        widget3 = new QWidget(showDB);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(50, 440, 311, 26));
        horizontalLayout_5 = new QHBoxLayout(widget3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        lineEdit_3 = new QLineEdit(widget3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_5->addWidget(lineEdit_3);

        widget4 = new QWidget(showDB);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(50, 360, 341, 31));
        horizontalLayout_3 = new QHBoxLayout(widget4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        lineEdit = new QLineEdit(widget4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);


        retranslateUi(showDB);

        QMetaObject::connectSlotsByName(showDB);
    } // setupUi

    void retranslateUi(QDialog *showDB)
    {
        showDB->setWindowTitle(QApplication::translate("showDB", "showDB", nullptr));
        sort->setText(QApplication::translate("showDB", "sort", nullptr));
        label_4->setText(QApplication::translate("showDB", "Sum", nullptr));
        label_3->setText(QApplication::translate("showDB", "Tax", nullptr));
        label->setText(QApplication::translate("showDB", "Industry", nullptr));
        label_2->setText(QApplication::translate("showDB", "Date", nullptr));
        label_5->setText(QApplication::translate("showDB", "Company", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showDB: public Ui_showDB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWDB_H
