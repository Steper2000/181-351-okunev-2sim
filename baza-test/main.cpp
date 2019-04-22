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
	
	//создаём базу данных типа SQLite
	//SQLite - встроенный драйвер в QT
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	//db.setDatabaseName("Test");
	db.database("Test");
	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "opa? ti kto????";
	//добавить запись путём SQL запроса 
	
	//создавать запрос к БД      
	/*
	создание таблицы
	название: User
	поля: login, password - хранятся значения типа char[20]
	*/
	QSqlQuery query(db);
	//создали таблицу
	query.exec("CREATE TABLE User("
		"login VARCHAR (20) NOT NULL, "
		"password VARCHAR (20) NOT NULL)");
	//добавляем запись
	//query.prepare("INSERT INTO user(login, password) VALUES(\"admin\", \"123\")");
	/*
	Вставить запись в таблицу
	название таблицы: User
	поле login: "admin"	
	поле password: "123"

	INSERT INTO user (login, password) VALUES("admin", "123") 
	*/
	query.prepare("INSERT INTO user(login, password) VALUES(:login, :password)");
	query.bindValue(":login", "admin");
	query.bindValue(":password", "123");
	query.exec();//выполнить
	
	
	/*
	
	Выбрать все записи БД 

	SELECT * FROM User 

	Выбрать все записи БД с условием

	SELECT * FROM User WHERE ......

	*/
	query.exec("SELECT * FROM User");

		// вывести на экран
	QSqlRecord rec = query.record();
	const int loginIndex = rec.indexOf("login"); //номер "столбца"
	const int passwordIndex = rec.indexOf("password");

	while (query.next())
	{
		qDebug() << query.value(loginIndex) << "\t" << query.value(passwordIndex);
	}

	// закрыть соединение
	//удалить таблицу
	query.exec("DROP TABLE User");
	//закрываем базу данных
	db.close();

	return a.exec();
}
