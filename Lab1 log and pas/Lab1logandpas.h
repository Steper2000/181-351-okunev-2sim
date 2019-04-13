#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab1logandpas.h"
#include <QTcpSocket>
class Lab1logandpas : public QMainWindow
{
	Q_OBJECT

public:
	Lab1logandpas(QWidget *parent = Q_NULLPTR);

private:
	Ui::Lab1logandpasClass ui;
	QTcpSocket *saske;

private slots:
	void on_pushButton_autorise_clicked();
	void on_Ftest_clicked();
	void slot_connected();
	void slot_ready_read();
	void slot_send_to_server(QString mess);
	void slot_disconected();
};
