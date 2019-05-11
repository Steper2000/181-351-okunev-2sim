#pragma once

#include <QDialog>
#include "ui_add.h"
#include <QTcpSocket>
#include "classdb.h"
#include "crypto.h"
class add : public QDialog, public Ui::add
{
	Q_OBJECT

public:
	add(QWidget *parent = Q_NULLPTR);
	~add();

private: 
	Ui::add ui;
	QTcpSocket * saske;
	//DataBase base;
private slots:
	void on_pushButton_add_clicked();
	void on_pushButton_del_clicked();
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
		
		//base.transformStr2BD(mess);
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
