#pragma once

#include <QDialog>
#include "ui_LPtatle.h"
#include "QStandardItemModel"
#include "LPbase.h"
#include <QMessageBox>

class LPtatle : public QDialog
{
	Q_OBJECT

public:
	LPtatle(QWidget *parent = Q_NULLPTR);
	~LPtatle();

private:
	Ui::LPtatle ui;
	QStandardItemModel *model;
private slots:
	void on_sort_clicked();
	//void on_delsor_clicked();
};
