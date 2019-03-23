#include "server.h"
//Qtsp server конспект
server::server(QObject *parent)
	: QObject(parent)
{
	mtser = new QTcpServer(this);
	connect(mtser, &QTcpServer::newConnection, this, &server::slotNewConnection);
	if(!mtser->listen(QHostAddress::Any, 33333)&&server_status==0)
	{
		qDebug() << "server is not started";
	}
	else {
		server_status = 1;
		qDebug() << "server is started";
	}
}

server::~server()
{
	server_status = 0;
}


void server::slotNewConnection()
{
	if (server_status == 1)
	{
		mtsoc = mtser->nextPendingConnection();
		mtsoc->write("hello world");
			connect(mtsoc, &QTcpSocket::readyRead, this, &server::slotServerRead);
			connect(mtsoc, &QTcpSocket::disconnected, this, &server::slotClientDis);
	}
}

void server::slotClientDis()
{
	if (server_status == 1)
	{
		mtsoc->close();
		mtser->close();
		qDebug() << QString::fromUtf8("Сервер oстановлен");
			server_status = 0;
	}
}

void server::slotServerRead()
{
	 /*array;
	while (mtsoc->bytesAvailable() > 0)
	{
		QByteArray array = mtsoc->readAll();
		char str = *array.data();
		str+=1;
		mtsoc->write(' '+ QByteArray::fromStdString((std::string)&str));
	}*/
	QTextStream os(mtsoc);
	os.setAutoDetectUnicode(true);
	os << "fffffffffffffff";
}
