#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "classdb.h"
#include "LPbase.h"
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>

/*
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
*/
class server : public QObject
{
	Q_OBJECT

public:
	server(QObject *parent=nullptr);
	~server();
public slots:
	void slotNewConnection();//вход
	void slotClientDis();//выход
	//void slotServerRead();// чтение
	void slotReadClient();
	void slotSendToCLient(QString mess);

private:
	QTcpServer * mtser;
	//QTcpSocket * mtsoc;
	int server_status;
	QMap<int,QTcpSocket *> SClient;
	//QSqlDatabase db;
	//QSqlQuery query(db);
};
