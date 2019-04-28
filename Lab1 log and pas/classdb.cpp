#include "classdb.h"
#include <fstream>
#include <string>
#include <cctype>   // для функции isdigit
#include <cstdlib>  // для функции atoi
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>
bool DataBase::add_data(datas tempData)//чётко
{
	//download(sdb);
	if (checkPred(tempData.pred) && checkOtr(tempData.otr) && checkDate(tempData.date) && checkNal(tempData.nal) &&checkSum(tempData.sum) ) 
	{
		db.push_back(tempData);
		//transformStr2BD(sdb);
		//sdb +="\n"+ tempData.pred+"\t" + tempData.otr+"\t"  + tempData.date+ "\t"  + tempData.nal+"\t" + tempData.sum;
		return true;
	}
	else 
		return false;
}

bool DataBase::download(std::string & res) //работает чётко
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Test");

	if (!db.open())
	{
		qDebug() << db.lastError().text();
		return false;
	}
	else
		qDebug() << "LP base opened";

	QSqlQuery query(db);
	query.exec("SELECT * FROM 'nologi' ");

	QString sendmes;

	while (query.next())
	{
		sendmes += query.value(0).toString() + "\t" + query.value(1).toString() + "\t" + query.value(2).toString()  + "\t" + query.value(3).toString() + "\t" + query.value(4).toString()+ "\n";
	}

	res = sendmes.toStdString();

	return true;
	/*
	QFile fin("database.txt");
	fin.open(QIODevice::ReadOnly | QIODevice::Text);
	if (!fin.isOpen()) 
	{ return false; }
	res = fin.readAll();
	fin.close();
	return true;
	*/
}

void DataBase::transformStr2BD(std::string sdb)// чётко
{
	int i = 0;
	datas td;
	std::string line;//взять первую запись из файла
	while (true) {
		while (sdb[i] != '\t') {
			line += sdb[i];
			i++;
		}
		td.pred = line;
		line.clear();
		i++;
		
		
		while (sdb[i] != '\t') {
			line += sdb[i];
			i++;
		}
		//if (checkOtr(line))
		td.otr = line;
		line.clear();
		i++;
		while (sdb[i] != '\t') {
			line += sdb[i];
			i++;
		}
		td.date = line;
		line.clear();
		i++;
		
		
		while (sdb[i] != '\t') {
			line += sdb[i];
			i++;
		}
		td.nal = line;
		line.clear();
		i++;
		
		
		while (sdb[i] != '\n') {
			line += sdb[i];
			i++;
			if (i >= sdb.size())
				break;
		}
		td.sum = line;
		line.clear();
		i++;
		add_data(td);
		if (i >= sdb.size())
			break;
	}
	//tempData = parsing(line);
	
	//othercompany	food	13.05.2006	dan	1000
}

bool DataBase::del_data(int id)//белиссимо
{
	if (id == -1 || id >= db.size())//////опасное место.........................................................................................................................
	return false;
	db.erase(db.begin() + id);
	return true;
}

int DataBase::find(std::string data2find)//ищет
{
	int i = 1;
	while (i < db.size())
	{
		if ((db[i].pred == data2find) || (db[i].otr == data2find) || (db[i].date == data2find) || (db[i].nal == data2find) || (db[i].sum == data2find))
			return i;

		i++;

	}
	return -1;//....................................................и тут тоже
}

int DataBase::find(std::string data2find, int e)//ищет
{
	int i = e+1;
	while (i < db.size()) 
	{
		if ((db[i].pred == data2find) || (db[i].otr == data2find) || (db[i].date == data2find) || (db[i].nal == data2find) || (db[i].sum == data2find))
			return i;
	
			i++;
			
	}
	return -1;//..........................................................
}

bool DataBase::write2file()//блестяще
{
	
	QFile fout("database.txt");
	fout.open(QIODevice::WriteOnly | QIODevice::Text);
	if (!fout.isOpen())
	{
		return false;
	}
	QTextStream writeStream(&fout);
	int i = 0;
	sdb.clear();
	while (i<db.size())
	{
	sdb += db[i].pred + "\t" + db[i].otr + "\t" + db[i].date + "\t" + db[i].nal + "\t" + db[i].sum + "\n";
	i++;
	}
	QString str= str.fromStdString(sdb);
	writeStream << str;
	fout.close();
	return true;
}

QString autorize(QString login, QString password)
{

	if (login == "" || password == "") {
		return "error";
	}

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("C:/181-351-okunev/181-351-Okunev-2sim/Qtserver/Test");
	
	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "LP base opened";
	//qDebug() << db.tables();

	QSqlQuery query(db);
	query.prepare("SELECT access FROM 'User' where login = :login  and password = :password ");
	query.bindValue(":login", login);
	query.bindValue(":password", password);
	query.exec();


	
	if (!query.isActive())
	{
		//ошибка
		qDebug() << query.lastError().text();
	}
	
	/*
	query.exec("CREATE TABLE nologi("
		"company VARCHAR (20) NOT NULL, "
		"industry VARCHAR (20) NOT NULL,"
		"date VARCHAR (20) NOT NULL,"
		"tax VARCHAR(20) NOT NULL,"
		"sum INT(10) NOT NULL)"
				);
	*/
	/*
	query.prepare("INSERT INTO nologi(company, industry, date, tax, sum) VALUES(:company, :industry, :date, :tax, :sum)");
	query.bindValue(":company", "hate sql");
	query.bindValue(":industry", "rap");
	query.bindValue(":date", "11.11.1111");
	query.bindValue(":tax", "w");
	query.bindValue(":sum", "1005");
	query.exec();//выполнить
	
	if (!query.isActive())
	{
		//ошибка
		qDebug() << query.lastError().text();
	}
	
	query.exec("SELECT * FROM nologi");

	// вывести на экран
	QSqlRecord rec = query.record();
	const int loginIndex = rec.indexOf("company"); //номер "столбца"
	const int passwordIndex = rec.indexOf("industry");
	const int accessIndex = rec.indexOf("date");
	const int aaccessIndex = rec.indexOf("tax");
	const int aaaccessIndex = rec.indexOf("sum");
	
	while (query.next())
	{
		qDebug() << query.value(loginIndex) << "\t" << query.value(passwordIndex) << "\t" << query.value(accessIndex) << "\t" << query.value(aaccessIndex) << "\t" << query.value(aaaccessIndex);
	}
	*/
	//QSqlRecord rec = query.record();
	//const int accessIndex = rec.indexOf("access");
	
	QString a;	
		
	if (query.next())
	{
		a = query.value(0).toString();
		db.close();
			
	if (a == 'a')
		return "admin";
	if (a == 'm')
		return "manager";
	if (a == 'u')
		return "user";
	}
	
	db.close();
	return "error";
	//*/
	
	/* 
	if (login == "" || password == "") {
		return "error";
	}
	FILE *base;
	base = fopen("log&pass.txt", "r");
	//std::ifstream base;
	//base.open("database.txt");
	QString sl;
	QString sp;
	//char sd;
	char i = fgetc(base);
	while (true)
	{
		//base.getline(sl, 20, ' ');
		//base.getline(sp, 20, '\n');
		while (i != '\t')
		{
			sl = sl + i;
			if (i == '\n')
				sl.clear();
			i = fgetc(base);
			if (i == -1)
			{
				return "error";
				//break;
			}
		}

		i = fgetc(base);

		while (i != '\t')
		{
			sp = sp + i;
			i = fgetc(base);
		}

		i = fgetc(base);

		if (login == sl && password == sp)
		{
			if (i == 'a')
				return "admin";
			if (i == 'm')
				return "manager";
			if (i == 'u')
				return "user";
			//break;
		}

		sl.clear();
		sp.clear();
	}
	//base.close();
	fclose(base);
	
	/*
	if (login == "adm" && pass == "123")
		return "admin";
	else 
	{
		if (login == "man" && pass == "1234")
			return "manager";
		else
		{
			if (login == "user" && pass == "12")
			return "user";
			else return "error";
		}
	}*/
	
}

bool checkPred(std::string pred)
{
	for (int i = 0; i < pred.size(); i++)
	{
		if (isdigit(pred[i]))
			return false;
	}
	return true;
}

bool checkOtr(std::string otr)//чётенько again
{
	//FILE *ind; //("industry.txt");
	//ind= fopen("industry.txt", "r");
	std::ifstream ind;
	ind.open("industry.txt", std::ifstream::in);
	if (!ind.is_open())
		return false;
	std::string d;
	getline(ind, d);
	while (d != ".")
	{
		if (otr == d) 
		{
			ind.close();
			return true;
		}
		getline(ind, d);	
	
	}
	ind.close();
	return false;
}

bool checkDate(std::string date)
{
	if (date == "DATE")
return true;
	if (!isdigit(date[0]))
		return false;
	
	//if ()
	if (isdigit(date[1]))
	{
		int d=0;
		int m= 0;
		int y = 0;
		if ((date[2] == '.') && isdigit(date[3]) && isdigit(date[4]) && (date[5] == '.') && isdigit(date[6]) && isdigit(date[7]) && isdigit(date[8]) && isdigit(date[9]))
		{
			for (int i = 0; i < 2; i++) {
				d = d * 10 + date[i] - 0x30;
			}
			for (int i = 3; i < 5; i++) {
				m = m * 10 + date[i] - 0x30;// 
			}
			for (int i = 6; i < 10; i++) {
				y = y * 10 + date[i] - 0x30;// std::stoi(date) - 0x30;
			}
			if (m > 0 && m <= 12)
			{
				if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
				{
					if (d <= 31 && d > 0)
						return true;
				}
				else
				{
					if (m == 2)
					{
						if (d <= 29 && d > 0)
							return true;
					}
					else
					{
						if (d <= 30 && d > 0)
							return true;
					}
				}
			}
		}
	}
	else
	{
		if (date[1] == '.')
		{
			if (isdigit(date[2]) && isdigit(date[3]) && (date[4] == '.') && isdigit(date[5]) && isdigit(date[6]) && isdigit(date[7]) && isdigit(date[8]))
			{
				int d = 0;
				int m = 0;
				int y = 0;
				for (int i = 0; i < 1; i++) {
					d = d * 10 + date[i] - 0x30;
				}
				for (int i = 2; i < 4; i++) {
					m = m * 10 + date[i] - 0x30;// 
				}
				for (int i = 5; i < 9; i++) {
					y = y * 10 + date[i] - 0x30;// std::stoi(date) - 0x30;
				}
				if (m > 0 && m <= 12)
				{
					if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
					{
						if (d <= 31 && d > 0)
							return true;
					}
					else
					{
						if (m == 2)
						{
							if (d <= 29 && d > 0)
								return true;
						}
						else
						{
							if (d <= 30 && d > 0)
								return true;
						}
					}
				}
			}
				
		}
	}
		return false;
}

bool checkNal(std::string nal)
{
	std::ifstream ind;
	ind.open("tax.txt", std::ifstream::in);
	if (!ind.is_open())
		return false;
	std::string d;
	getline(ind, d);
	while (d != ".")
	{
		if (nal == d)
		{
			ind.close();
			return true;
		}
		getline(ind, d);

	}
	ind.close();
	return false;
}

bool checkSum(std::string sum)//work clear
{
	if (sum == "SUM") 
		return true;
	for (int i = 0; i < sum.size(); i++)
	{
		if (!isdigit(sum[i]))
			return false;
	}
	return true;
}

QString DataBase::retrans()
{
	int i = 0;
	sdb.clear();
	while (i < db.size())
	{
		sdb += db[i].pred + "\t" + db[i].otr + "\t" + db[i].date + "\t" + db[i].nal + "\t" + db[i].sum + "\n";
		i++;
	}
	QString str = str.fromStdString(sdb);
	return str;
}


void kek()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("C:/181-351-okunev/181-351-Okunev-2sim/Qtserver/Test");

	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "LP base opened";
	//qDebug() << db.tables();

	QSqlQuery query(db);	
		
		query.prepare("INSERT INTO nologi(company, industry, date, tax, sum) VALUES(:company, :industry, :date, :tax, :sum)");
		query.bindValue(":company", "Knigga");
		query.bindValue(":industry", "rap");
		query.bindValue(":date", "11.11.1111");
		query.bindValue(":tax", "water");
		query.bindValue(":sum", "1000");
		query.exec();//выполнить

		if (!query.isActive())
		{
			//ошибка
			qDebug() << query.lastError().text();
		}
	
		query.prepare("INSERT INTO nologi(company, industry, date, tax, sum) VALUES(:company, :industry, :date, :tax, :sum)");
		query.bindValue(":company", "Knigga");
		query.bindValue(":industry", "flex");
		query.bindValue(":date", "11.11.1111");
		query.bindValue(":tax", "water");
		query.bindValue(":sum", "1000");
		query.exec();//выполнить

		if (!query.isActive())
		{
			//ошибка
			qDebug() << query.lastError().text();
		}

		query.prepare("INSERT INTO nologi(company, industry, date, tax, sum) VALUES(:company, :industry, :date, :tax, :sum)");
		query.bindValue(":company", "Knigga");
		query.bindValue(":industry", "rap");
		query.bindValue(":date", "13.11.1111");
		query.bindValue(":tax", "life");
		query.bindValue(":sum", "1000");
		query.exec();//выполнить

		if (!query.isActive())
		{
			//ошибка
			qDebug() << query.lastError().text();
		}

		query.prepare("INSERT INTO nologi(company, industry, date, tax, sum) VALUES(:company, :industry, :date, :tax, :sum)");
		query.bindValue(":company", "Knigga");
		query.bindValue(":industry", "rock");
		query.bindValue(":date", "11.11.1111");
		query.bindValue(":tax", "life");
		query.bindValue(":sum", "1000");
		query.exec();//выполнить

		if (!query.isActive())
		{
			//ошибка
			qDebug() << query.lastError().text();
		}

		query.prepare("INSERT INTO nologi(company, industry, date, tax, sum) VALUES(:company, :industry, :date, :tax, :sum)");
		query.bindValue(":company", "Knigga");
		query.bindValue(":industry", "rap");
		query.bindValue(":date", "11.11.1111");
		query.bindValue(":tax", "life");
		query.bindValue(":sum", "1002");
		query.exec();//выполнить

		if (!query.isActive())
		{
			//ошибка
			qDebug() << query.lastError().text();
		}

		query.prepare("INSERT INTO nologi(company, industry, date, tax, sum) VALUES(:company, :industry, :date, :tax, :sum)");
		query.bindValue(":company", "Knigga");
		query.bindValue(":industry", "rap");
		query.bindValue(":date", "11.11.1111");
		query.bindValue(":tax", "life");
		query.bindValue(":sum", "1000");
		query.exec();//выполнить

		if (!query.isActive())
		{
			//ошибка
			qDebug() << query.lastError().text();
		}

		query.prepare("INSERT INTO nologi(company, industry, date, tax, sum) VALUES(:company, :industry, :date, :tax, :sum)");
		query.bindValue(":company", "GUNE");
		query.bindValue(":industry", "rap");
		query.bindValue(":date", "23.06.2003");
		query.bindValue(":tax", "w");
		query.bindValue(":sum", "1000");
		query.exec();//выполнить

		if (!query.isActive())
		{
			//ошибка
			qDebug() << query.lastError().text();
		}

		query.prepare("INSERT INTO nologi(company, industry, date, tax, sum) VALUES(:company, :industry, :date, :tax, :sum)");
		query.bindValue(":company", "Gas prom");
		query.bindValue(":industry", "steal");
		query.bindValue(":date", "9.03.2001");
		query.bindValue(":tax", "rich");
		query.bindValue(":sum", "500");
		query.exec();//выполнить

		if (!query.isActive())
		{
			//ошибка
			qDebug() << query.lastError().text();
		}

		query.prepare("INSERT INTO nologi(company, industry, date, tax, sum) VALUES(:company, :industry, :date, :tax, :sum)");
		query.bindValue(":company", "SDK");
		query.bindValue(":industry", "flex");
		query.bindValue(":date", "26.04.2019");
		query.bindValue(":tax", "nolog");
		query.bindValue(":sum", "1488");
		query.exec();//выполнить

		if (!query.isActive())
		{
			//ошибка
			qDebug() << query.lastError().text();
		}
}