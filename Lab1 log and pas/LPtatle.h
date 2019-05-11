#pragma once

#include <QDialog>
#include "ui_LPtatle.h"
#include "QStandardItemModel"
#include "LPbase.h"
#include <QMessageBox>
#include <QTcpSocket>
#include "crypto.h"

class LPtatle : public QDialog
{
	Q_OBJECT

public:
	LPtatle(QWidget *parent = Q_NULLPTR);
	~LPtatle();

private:
	Ui::LPtatle ui;
	QStandardItemModel *model;
	QTcpSocket *saske;
	LPbase tabl;
private slots:
	void on_sort_clicked();
	
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

		tabl.trans(mess);

		ui.setupUi(this);
		model = new QStandardItemModel;
		QStandardItem *item;

		//Заголовки столбцов
		QStringList horizontalHeader;
		horizontalHeader.append("Login");
		horizontalHeader.append("Password");
		horizontalHeader.append("Level");
		model->setHorizontalHeaderLabels(horizontalHeader);
		
		//tabl.download();
		for (int i = 0; i < tabl.baza.size(); i++)
		{

			item = new QStandardItem(QString::fromStdString(tabl.baza[i].log));
			model->setItem(i, 0, item);

			item = new QStandardItem(QString::fromStdString(tabl.baza[i].pas));
			model->setItem(i, 1, item);

			item = new QStandardItem(QString::fromStdString(tabl.baza[i].lev));
			model->setItem(i, 2, item);
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
	//void on_delsor_clicked();
};
