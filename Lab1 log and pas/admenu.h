#pragma once

#include <QDialog>
#include "ui_admenu.h"

class admenu : public QDialog
{
	Q_OBJECT

public:
	admenu(QWidget *parent = Q_NULLPTR);
	~admenu();

private:
	Ui::admenu ui;
private slots:
	void on_show_clicked();
	void on_change_clicked();
};
