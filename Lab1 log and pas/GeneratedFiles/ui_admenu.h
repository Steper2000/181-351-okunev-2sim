/********************************************************************************
** Form generated from reading UI file 'admenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMENU_H
#define UI_ADMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_admenu
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QPushButton *show;
    QPushButton *change;

    void setupUi(QDialog *admenu)
    {
        if (admenu->objectName().isEmpty())
            admenu->setObjectName(QString::fromUtf8("admenu"));
        admenu->resize(519, 208);
        verticalLayout = new QVBoxLayout(admenu);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(admenu);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        show = new QPushButton(admenu);
        show->setObjectName(QString::fromUtf8("show"));

        verticalLayout->addWidget(show);

        change = new QPushButton(admenu);
        change->setObjectName(QString::fromUtf8("change"));

        verticalLayout->addWidget(change);


        retranslateUi(admenu);

        QMetaObject::connectSlotsByName(admenu);
    } // setupUi

    void retranslateUi(QDialog *admenu)
    {
        admenu->setWindowTitle(QApplication::translate("admenu", "admenu", nullptr));
        textBrowser->setHtml(QApplication::translate("admenu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Hello admin! What do you want to do?</span></p></body></html>", nullptr));
        show->setText(QApplication::translate("admenu", "Show log and pss table", nullptr));
        change->setText(QApplication::translate("admenu", "Change my login and password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admenu: public Ui_admenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMENU_H
