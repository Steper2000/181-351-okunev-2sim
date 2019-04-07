#include "LPtatle.h"

LPtatle::LPtatle(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	model = new QStandardItemModel;
	QStandardItem *item;

	//Заголовки столбцов
	QStringList horizontalHeader;
	horizontalHeader.append("Login");
	horizontalHeader.append("Password");
	horizontalHeader.append("Level");
	model->setHorizontalHeaderLabels(horizontalHeader);
	LPbase tabl;
	tabl.download();
	for (int i = 0; i < tabl.baza.size(); i++)
	{
		
		item = new QStandardItem(QString::fromStdString(tabl.baza[i].log));
		model->setItem(i , 0, item);

		item = new QStandardItem(QString::fromStdString(tabl.baza[i].pas));
		model->setItem(i , 1, item);

		item = new QStandardItem(QString::fromStdString(tabl.baza[i].lev));
		model->setItem(i , 2, item);
	}
	
	ui.tableView->setModel(model);
	ui.tableView->resizeRowsToContents();
	ui.tableView->resizeColumnsToContents();
}

LPtatle::~LPtatle()
{
}

void LPtatle::on_sort_clicked()
{
	model = new QStandardItemModel;
	QStandardItem *item;
	QStringList horizontalHeader;
	horizontalHeader.append("Login");
	horizontalHeader.append("Password");
	horizontalHeader.append("Level");
	model->setHorizontalHeaderLabels(horizontalHeader);
	LPbase tabl, tab;
	tabl.download();
	QString sor = ui.lineEdit->text();
	std::string so = sor.toStdString();
	int id;
	if (so != "")
	{
		id = tabl.find(so);
		//int i = 0;
		if (id == -1)
		{
			QMessageBox m;
			m.setText("Not in database");
			m.exec();
		}
		while (id != -1)
		{
			tab.add_data(tabl.baza[id]);
			id = tabl.find(so, id);
		}
	}
	
	for (int i = 0; i < tab.baza.size(); i++)
	{

		item = new QStandardItem(QString::fromStdString(tab.baza[i].log));
		model->setItem(i, 0, item);

		item = new QStandardItem(QString::fromStdString(tab.baza[i].pas));
		model->setItem(i, 1, item);

		item = new QStandardItem(QString::fromStdString(tab.baza[i].lev));
		model->setItem(i, 2, item);
	}

	ui.tableView->setModel(model);
	ui.tableView->resizeRowsToContents();
	ui.tableView->resizeColumnsToContents();

}


