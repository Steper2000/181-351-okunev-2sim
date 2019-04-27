#include <QtCore/QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>

void pushInLPBase(QSqlDatabase db, QString log, QString pas, QString ac)
{
	QSqlQuery query(db);
	query.prepare("INSERT INTO User(login, password, access) VALUES(:login, :password, :access)");
	query.bindValue(":login", log);
	query.bindValue(":password", pas);
	query.bindValue(":access", ac);
	query.exec();//выполнить
}



int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	//создаём базу данных типа SQLite
	//SQLite - встроенный драйвер в QT
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Test");
	//db.database("Test");
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
		"password VARCHAR (20) NOT NULL,"
		"access VARCHAR (20) NOT NULL)");
	//добавляем запись
	//query.prepare("INSERT INTO user(login, password) VALUES(\"admin\", \"123\")");
	/*
	Вставить запись в таблицу
	название таблицы: User
	поле login: "admin"	
	поле password: "123"

	INSERT INTO user (login, password) VALUES("admin", "123") 
	*/
	/*
	
	
	query.prepare("INSERT INTO User(login, password) VALUES(:login, :password)");
	query.bindValue(":login", "admin");
	query.bindValue(":password", "123");
	query.exec();//выполнить
	*/
	
	//*
	pushInLPBase(db, "Kirill", "sos", "m");
	pushInLPBase(db, "Danila", "nedaniil", "m");
	pushInLPBase(db, "Milena", "loh", "m");
	pushInLPBase(db, "Anton", "kuko", "m");
	pushInLPBase(db, "admin", "123", "a");
	pushInLPBase(db, "q", "q", "m");
	pushInLPBase(db, "a", "a", "a");
	pushInLPBase(db, "Moxem", "nachural", "m");
	pushInLPBase(db, "Kavo", "ban", "m");
	pushInLPBase(db, "user1", "1234", "u");
	pushInLPBase(db, "user2", "1234", "u");
	pushInLPBase(db, "user3", "1234", "u");
	pushInLPBase(db, "user4", "1234", "u");
	pushInLPBase(db, "user5", "1234", "u");
	pushInLPBase(db, "user6", "1234", "u");
	pushInLPBase(db, "user7", "1234", "u");
	pushInLPBase(db, "user8", "1234", "u");
	pushInLPBase(db, "user9", "1234", "u");
	//*/


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
	const int accessIndex = rec.indexOf("access");
	
	while (query.next())
	{
		qDebug() << query.value(loginIndex) << "\t" << query.value(passwordIndex)<<"\t"<< query.value(accessIndex);
	}

	// закрыть соединение
	//удалить таблицу
	//query.exec("DROP TABLE User");
	//закрываем базу данных
	db.close();

	return a.exec();
}
