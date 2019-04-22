#include <QtCore/QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	//������ ���� ������ ���� SQLite
	//SQLite - ���������� ������� � QT
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	//db.setDatabaseName("Test");
	db.database("Test");
	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "opa? ti kto????";
	//�������� ������ ���� SQL ������� 
	
	//��������� ������ � ��      
	/*
	�������� �������
	��������: User
	����: login, password - �������� �������� ���� char[20]
	*/
	QSqlQuery query(db);
	//������� �������
	query.exec("CREATE TABLE User("
		"login VARCHAR (20) NOT NULL, "
		"password VARCHAR (20) NOT NULL)");
	//��������� ������
	//query.prepare("INSERT INTO user(login, password) VALUES(\"admin\", \"123\")");
	/*
	�������� ������ � �������
	�������� �������: User
	���� login: "admin"	
	���� password: "123"

	INSERT INTO user (login, password) VALUES("admin", "123") 
	*/
	query.prepare("INSERT INTO user(login, password) VALUES(:login, :password)");
	query.bindValue(":login", "admin");
	query.bindValue(":password", "123");
	query.exec();//���������
	
	
	/*
	
	������� ��� ������ �� 

	SELECT * FROM User 

	������� ��� ������ �� � ��������

	SELECT * FROM User WHERE ......

	*/
	query.exec("SELECT * FROM User");

		// ������� �� �����
	QSqlRecord rec = query.record();
	const int loginIndex = rec.indexOf("login"); //����� "�������"
	const int passwordIndex = rec.indexOf("password");

	while (query.next())
	{
		qDebug() << query.value(loginIndex) << "\t" << query.value(passwordIndex);
	}

	// ������� ����������
	//������� �������
	query.exec("DROP TABLE User");
	//��������� ���� ������
	db.close();

	return a.exec();
}
