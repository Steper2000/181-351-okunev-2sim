#pragma once

#include <QDialog>
#include "ui_change.h"
//#include "classdb.h"

class change : public QDialog, public Ui::change //public DataBase
{
	Q_OBJECT

public:
	change(QWidget *parent = Q_NULLPTR);
	~change();
	
private: Ui::change ui;
private slots:
	void on_pushButton_change_clicked();
	void on_del_clicked();
};
