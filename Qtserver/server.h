#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

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
	void slotNewConnection();//����
	void slotClientDis();//�����
	//void slotServerRead();// ������
	void slotReadClient();
	void slotSendToCLient(QString mess);

private:
	QTcpServer * mtser;
	//QTcpSocket * mtsoc;
	int server_status;
	QMap<int,QTcpSocket *> SClient;
};
