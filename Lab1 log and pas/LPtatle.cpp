#include "LPtatle.h"

LPtatle::LPtatle(QWidget *parent)
	: QDialog(parent)
{
	
	saske = new QTcpSocket(this);
	saske->connectToHost("127.0.0.1", 33333);
	connect(saske, SIGNAL(connected()), SLOT(slot_connected()));
	connect(saske, SIGNAL(readyRead()), SLOT(slot_ready_read()));
	slot_send_to_server("LPtable");



/*
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
	*/
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
//LPbase tabl, tab;
	//tabl.download();
	LPbase tab;
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
	if(ui.ra->isChecked())
	{
		int j=0;
		if(so!="")
		{
			while ( j < tab.baza.size())
			{
				if (tab.baza[j].lev != "a")
					tab.del_data(j);
				else j++;
			}
		}
		else
		{
			for (int i = 0; i < tabl.baza.size(); i++)
			{
				if (tabl.baza[i].lev == "a")
					tab.add_data(tabl.baza[i]);
			}
		}
	}
	if (ui.rm->isChecked())
	{
		int j = 0;
		if (so != "")
		{
			while (j < tab.baza.size())
			{
				if (tab.baza[j].lev != "m")
					tab.del_data(j);
				else j++;
			}
		}
		else
		{
			for (int i = 0; i < tabl.baza.size(); i++)
			{
				if (tabl.baza[i].lev == "m")
					tab.add_data(tabl.baza[i]);
			}
		}
	}
	if (ui.ru->isChecked())
	{
		int j = 0;
		if (so != "")
		{
			while (j < tab.baza.size())
			{
				if (tab.baza[j].lev != "u")
					tab.del_data(j);
				else j++;
			}
		}
		else
		{
			for (int i = 0; i < tabl.baza.size(); i++)
			{
				if (tabl.baza[i].lev == "u")
					tab.add_data(tabl.baza[i]);
			}
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


