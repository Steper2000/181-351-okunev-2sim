#pragma once
//#include "qstandarditemmodel.h"
#include "QStandardItemModel"
#include <QDialog>
#include "ui_showDB.h"
#include "classdb.h"
#include <QMessageBox>
#include <QTcpSocket>
#include "crypto.h"
class showDB : public QDialog, public Ui::showDB//, public classdb
{
	Q_OBJECT

public:
	showDB(QWidget *parent = Q_NULLPTR);
	~showDB();

private:
	Ui::showDB ui;
	QStandardItemModel *model;
	QTcpSocket *saske;
	DataBase eshkere;
private slots:
	void on_sort_clicked();
	void on_delsor_clicked();
	void slot_connected()
	{

	}

	void slot_ready_read()
	{
		QByteArray arr, arr2;
		std::string mess;

		while (saske->bytesAvailable() > 0)
		{
			arr = saske->readAll();
		}

		crypto c;
		arr2 = c.decrypt(arr);
		mess = arr2.toStdString();

		eshkere.transformStr2BD(mess);

		model = new QStandardItemModel;
		QStandardItem *item;

		//Заголовки столбцов
		QStringList horizontalHeader;
		horizontalHeader.append("Company");
		horizontalHeader.append("Industry");
		horizontalHeader.append("Date");
		horizontalHeader.append("Tax");
		horizontalHeader.append("Sum");

		//Заголовки строк
		//QStringList verticalHeader;
		//verticalHeader.append("Ряд 1");
		//verticalHeader.append("Ряд 2");

		model->setHorizontalHeaderLabels(horizontalHeader);
		//model->setVerticalHeaderLabels(verticalHeader);

		//DataBase eshkere;
		//eshkere.download();

		for (int i = 0; i < eshkere.db.size(); i++)
		{
			//for(int j=0; j<5; j++){}
			item = new QStandardItem(QString::fromStdString(eshkere.db[i].pred));
			model->setItem(i , 0, item);

			item = new QStandardItem(QString::fromStdString(eshkere.db[i].otr));
			model->setItem(i , 1, item);

			item = new QStandardItem(QString::fromStdString(eshkere.db[i].date));
			model->setItem(i , 2, item);

			item = new QStandardItem(QString::fromStdString(eshkere.db[i].nal));
			model->setItem(i , 3, item);

			item = new QStandardItem(QString::fromStdString(eshkere.db[i].sum));
			model->setItem(i , 4, item);
		}


		ui.tableView->setModel(model);
		ui.tableView->resizeRowsToContents();
		ui.tableView->resizeColumnsToContents();

	}

	void slot_send_to_server(QString mess)
	{
		QByteArray arr, arr2;
		arr.append(mess);
		crypto c;
		arr2 = c.encrypt(arr);
		saske->write(arr2);
	}

	void slot_disconected()
	{

	}
};
