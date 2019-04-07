/********************************************************************************
** Form generated from reading UI file 'change.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_H
#define UI_CHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_change
{
public:
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Nlogin;
    QLineEdit *line_Nlogin;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Npassword;
    QLineEdit *line_Npassword;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lev;
    QLineEdit *line_level;
    QPushButton *pushButton_change;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *del_id;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *del_d;
    QPushButton *del;

    void setupUi(QDialog *change)
    {
        if (change->objectName().isEmpty())
            change->setObjectName(QString::fromUtf8("change"));
        change->resize(620, 317);
        horizontalLayout_8 = new QHBoxLayout(change);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        groupBox_2 = new QGroupBox(change);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_Nlogin = new QLabel(groupBox_2);
        label_Nlogin->setObjectName(QString::fromUtf8("label_Nlogin"));

        horizontalLayout->addWidget(label_Nlogin);

        line_Nlogin = new QLineEdit(groupBox_2);
        line_Nlogin->setObjectName(QString::fromUtf8("line_Nlogin"));

        horizontalLayout->addWidget(line_Nlogin);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_Npassword = new QLabel(groupBox_2);
        label_Npassword->setObjectName(QString::fromUtf8("label_Npassword"));

        horizontalLayout_2->addWidget(label_Npassword);

        line_Npassword = new QLineEdit(groupBox_2);
        line_Npassword->setObjectName(QString::fromUtf8("line_Npassword"));

        horizontalLayout_2->addWidget(line_Npassword);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lev = new QLabel(groupBox_2);
        lev->setObjectName(QString::fromUtf8("lev"));

        horizontalLayout_3->addWidget(lev);

        line_level = new QLineEdit(groupBox_2);
        line_level->setObjectName(QString::fromUtf8("line_level"));

        horizontalLayout_3->addWidget(line_level);


        verticalLayout_2->addLayout(horizontalLayout_3);

        pushButton_change = new QPushButton(groupBox_2);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));
        QFont font;
        font.setPointSize(16);
        pushButton_change->setFont(font);
        pushButton_change->setAutoFillBackground(false);

        verticalLayout_2->addWidget(pushButton_change);


        horizontalLayout_7->addLayout(verticalLayout_2);


        horizontalLayout_8->addWidget(groupBox_2);

        groupBox = new QGroupBox(change);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_6 = new QHBoxLayout(groupBox);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        del_id = new QLineEdit(groupBox);
        del_id->setObjectName(QString::fromUtf8("del_id"));

        horizontalLayout_5->addWidget(del_id);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        del_d = new QLineEdit(groupBox);
        del_d->setObjectName(QString::fromUtf8("del_d"));

        horizontalLayout_4->addWidget(del_d);


        verticalLayout->addLayout(horizontalLayout_4);

        del = new QPushButton(groupBox);
        del->setObjectName(QString::fromUtf8("del"));

        verticalLayout->addWidget(del);


        horizontalLayout_6->addLayout(verticalLayout);


        horizontalLayout_8->addWidget(groupBox);


        retranslateUi(change);

        QMetaObject::connectSlotsByName(change);
    } // setupUi

    void retranslateUi(QDialog *change)
    {
        change->setWindowTitle(QApplication::translate("change", "change", nullptr));
        groupBox_2->setTitle(QApplication::translate("change", "Add new user", nullptr));
        label_Nlogin->setText(QApplication::translate("change", "login", nullptr));
        label_Npassword->setText(QApplication::translate("change", "password", nullptr));
        lev->setText(QApplication::translate("change", "level", nullptr));
        pushButton_change->setText(QApplication::translate("change", "Add", nullptr));
        groupBox->setTitle(QApplication::translate("change", "Delete user", nullptr));
        label_2->setText(QApplication::translate("change", "Row with \342\204\226:", nullptr));
        label->setText(QApplication::translate("change", "First row containing:", nullptr));
        del->setText(QApplication::translate("change", "delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class change: public Ui_change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_H
