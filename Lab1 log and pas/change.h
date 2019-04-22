#pragma once

#include <QDialog>
#include "ui_change.h"
#include "LPbase.h"
#include <QTcpSocket>
//#include "classdb.h"

class change : public QDialog, public Ui::change //public DataBase
{
	Q_OBJECT

public:
	change(QWidget *parent = Q_NULLPTR);
	~change();
	
private:
	Ui::change ui;
	QTcpSocket * saske;
	LPbase base;
private slots:
	void on_pushButton_change_clicked();
	void on_del_clicked();
	void slot_connected()
	{

	}

	void slot_ready_read()
	{
		QByteArray arr;
		std::string mess;

		while (saske->bytesAvailable() > 0)
		{
			arr = saske->readAll();
			mess = arr.toStdString();
		}
		
		base.trans(mess);
	}

	void slot_send_to_server(QString mess)
	{
		QByteArray arr;
		arr.append(mess);
		saske->write(arr);
	}

	void slot_disconected()
	{

	}
};
