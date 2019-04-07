#include "admenu.h"
#include "change.h"
#include "LPtatle.h"
admenu::admenu(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

admenu::~admenu()
{
}

void admenu::on_show_clicked()
{
	LPtatle a;
	a.setModal(true);
	a.exec();

}

void admenu::on_change_clicked()
{
	change c;
	c.setModal(true);
	c.exec();
}