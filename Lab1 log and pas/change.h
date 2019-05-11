#pragma once

#include <QDialog>
#include "ui_change.h"
#include "LPbase.h"
#include <QTcpSocket>
#include "crypto.h"

class change : public QDialog, public Ui::change //public DataBase
{
	Q_OBJECT

public:
	change(QWidget *parent = Q_NULLPTR);
	~change();
	
private:
	Ui::change ui;
	QTcpSocket * saske;
	//LPbase base;
private slots:
	void on_pushButton_change_clicked();
	void on_del_clicked();
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
	//	base.trans(mess);
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
