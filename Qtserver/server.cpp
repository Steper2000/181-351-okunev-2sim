
#include "server.h"
#include <QDebug>
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
	if (server_status == 1)
	{
		//mtsoc->close();

		foreach(int i, SClient.keys()) {
			QTextStream os(SClient[i]);
			os.setAutoDetectUnicode(true);
			os << QDateTime::currentDateTime().toString() << "\n";
			SClient[i]->close();
			SClient.remove(i);
		}
		mtser->close();
		qDebug() << QString::fromUtf8("server stoped");
		server_status = 0;
	}
}


void server::slotNewConnection()
{
	if (server_status == 1)
	{
		/*
		mtsoc = mtser->nextPendingConnection();
		mtsoc->write("hello world");
			connect(mtsoc, &QTcpSocket::readyRead, this, &server::slotReadClient);
			connect(mtsoc, &QTcpSocket::disconnected, this, &server::slotClientDis);*/
		qDebug() << QString::fromUtf8("new connection");
		QTcpSocket* clientSocket =mtser->nextPendingConnection();
		int id = clientSocket->socketDescriptor();
		SClient[id] = clientSocket;
		connect(SClient[id],  SIGNAL(readyRead()), this, SLOT(slotReadClient()));
		connect(SClient[id], &QTcpSocket::disconnected, this, &server::slotClientDis); 
	}
}


void server::slotClientDis()
{
	QObject * object = QObject::sender();
	QTcpSocket * socket = static_cast<QTcpSocket *>(object);
	socket->close();
}

void server::slotReadClient()
{
	QObject * object = QObject::sender(); 
	QTcpSocket * socket = static_cast<QTcpSocket *>(object);
	//QTextStream os(socket);
	//os.setAutoDetectUnicode(true);
	//os << "\hello! you conected ";
	//if (socket->bytesAvaible()>0)
	QByteArray arr = socket->readAll();
	
	std::string mess;
	mess = arr.toStdString();
	qDebug()<<QString::fromStdString(mess);
	
	int pos = mess.find(" ");
	std::string func = mess.substr(0, pos);
	mess.erase(0, pos + 1);
	
	if (func == "autorize") 
	{
		QString log;
		QString pass;
		pos = mess.find(" ");
		log = QString::fromStdString(mess.substr(0, pos));
		mess.erase(0, pos + 1);

		//mess.pop_back();
		//mess.pop_back();
		pass = QString::fromStdString(mess);
		//mess.erase(0, pos + 1);
		qDebug() << "hello" << autorize(log, pass);
		slotSendToCLient(autorize(log, pass));
	}
	
	if (func=="LPtable")
	{
		std::string a;
		LPbase f;
		f.download(a);
		slotSendToCLient(QString::fromStdString(a));
	}
	
	if (func == "changeLP")
	{
		QString db= QString::fromStdString(mess);
		QFile fout("log&pass.txt");
		fout.open(QIODevice::WriteOnly | QIODevice::Text);
		QTextStream writeStream(&fout);
		writeStream << db;
		fout.close();
		qDebug() << "DB log&pass was updated";
	}

	if (func == "Nolog")
	{
		std::string a;
		DataBase f;
		f.download(a);
		slotSendToCLient(QString::fromStdString(a));
	}

	if (func == "changeDB")
	{
		QString db = QString::fromStdString(mess);
		QFile fout("database.txt");
		fout.open(QIODevice::WriteOnly | QIODevice::Text);
		QTextStream writeStream(&fout);
		writeStream << db;
		fout.close();
		qDebug() << "DB database was updated";
	}
	/*QString qstr = socket->readAll();
	std::string str = qstr.toStdString();
	if (str == "autorize\r\n")
	{
		qstr = socket->readAll();
		std::string strl = qstr.toStdString();
		qstr = socket->readAll();
		std::string strp = qstr.toStdString();
	}*/
}

void server::slotSendToCLient(QString mess)
{
	QObject * object = QObject::sender();
	QTcpSocket * socket = static_cast<QTcpSocket *>(object);
	QByteArray arr;
	arr.append(mess);
	socket->write(arr);
}


/*
void server::slotServerRead()
{
	 /*array;
	while (mtsoc->bytesAvailable() > 0)
	{
		QByteArray array = mtsoc->readAll();
		char str = *array.data();
		str+=1;
		mtsoc->write(' '+ QByteArray::fromStdString((std::string)&str));
	}
	QTextStream os(mtsoc);
	os.setAutoDetectUnicode(true);
	os << "\nfffffffffffffff";
} */
