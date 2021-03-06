
#include "server.h"
#include <QDebug>
//Qtsp server ��������
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
	
	QByteArray arr, arr2;
	arr = socket->readAll();
	crypto c;
	arr2 = c.decrypt(arr);

	
	
	std::string mess;
	mess = arr2.toStdString();
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
	
	if (func == "add")
	{
		
		pos = mess.find(" ");
		QString log = QString::fromStdString(mess.substr(0, pos));
		mess.erase(0, pos + 1);

		pos = mess.find(" ");
		QString pas = QString::fromStdString(mess.substr(0, pos));
		mess.erase(0, pos + 1);

		QString ac= QString::fromStdString(mess);
		
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("Test");

		if (!db.open())
			qDebug() << db.lastError().text();
		else
			qDebug() << "LP base opened";

		QSqlQuery query(db);
		query.prepare("INSERT INTO User(login, password, access) VALUES(:login, :password, :access)");
		query.bindValue(":login", log);
		query.bindValue(":password", pas);
		query.bindValue(":access", ac);
		query.exec();//���������

		/*
		QString db= QString::fromStdString(mess);
		QFile fout("log&pass.txt");
		fout.open(QIODevice::WriteOnly | QIODevice::Text);
		QTextStream writeStream(&fout);
		writeStream << db;
		fout.close();
		*/
		qDebug() << "DB log&pass was updated";
		db.close();
	}

	if (func == "delete")
	{

		QString log = QString::fromStdString(mess);

		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("Test");

		if (!db.open())
			qDebug() << db.lastError().text();
		else
			qDebug() << "LP base opened";

		QSqlQuery query(db);
		query.prepare("DELETE FROM User WHERE login = :login");
		query.bindValue(":login", log);
		//query.bindValue(":password", pas);
		//query.bindValue(":access", ac);
		query.exec();//���������
		if (!query.isActive())
		{
			//������
			qDebug() << query.lastError().text();
		}

		qDebug() << "user " <<log <<" deleted";
	}

	if (func == "Nolog")
	{
		std::string a;
		DataBase f;
		f.download(a);
		slotSendToCLient(QString::fromStdString(a));
	}

	if (func == "addDB")
	{
		pos = mess.find("\t");
		QString a = QString::fromStdString(mess.substr(0, pos));
		mess.erase(0, pos + 1);

		pos = mess.find("\t");
		QString b = QString::fromStdString(mess.substr(0, pos));
		mess.erase(0, pos + 1);

		pos = mess.find("\t");
		QString c = QString::fromStdString(mess.substr(0, pos));
		mess.erase(0, pos + 1);

		pos = mess.find("\t");
		QString d = QString::fromStdString(mess.substr(0, pos));
		mess.erase(0, pos + 1);

		QString e = QString::fromStdString(mess);
		
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("C:/181-351-okunev/181-351-Okunev-2sim/Qtserver/Test");

		if (!db.open())
			qDebug() << db.lastError().text();
		else
			qDebug() << "LP base opened";
		

		QSqlQuery query(db);

		query.prepare("INSERT INTO nologi(company, industry, date, tax, sum) VALUES(:company, :industry, :date, :tax, :sum)");
		query.bindValue(":company", a);
		query.bindValue(":industry", b);
		query.bindValue(":date",c);
		query.bindValue(":tax", d);
		query.bindValue(":sum", e);
		query.exec();//���������

		if (!query.isActive())
		{
			//������
			qDebug() << query.lastError().text();
		}
		/*
		QString db = QString::fromStdString(mess);
		QFile fout("database.txt");
		fout.open(QIODevice::WriteOnly | QIODevice::Text);
		QTextStream writeStream(&fout);
		writeStream << db;
		fout.close();
		*/
		qDebug() << "DB database was updated";
		db.close();
	}
	
	if (func == "deleteDB")
	{

		QString log = QString::fromStdString(mess);

		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("Test");

		if (!db.open())
			qDebug() << db.lastError().text();
		else
			qDebug() << "LP base opened";

		QSqlQuery query(db);
		query.prepare("DELETE FROM nologi WHERE company = :login");
		query.bindValue(":login", log);
		
		query.exec();//���������
		if (!query.isActive())
		{
			//������
			qDebug() << query.lastError().text();
		}

		qDebug() << "DATA deleted";
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
	QByteArray arr, arr2;
	arr.append(mess);
	
	crypto c;
	arr2 = c.encrypt(arr);
	
	socket->write(arr2);
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
