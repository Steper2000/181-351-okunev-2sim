#include "LPbase.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>
//#include "Lab1logandpas.h"
/*
LPbase::LPbase()
{
}

LPbase::~LPbase()
{
}
*/
bool LPbase::add_data(lopal l)
{
	if (l.lev != "a")
	{
		if (l.lev != "m")
		{
			if (l.lev != "u")
				return false;
		}
	}
	baza.push_back(l);
	return true;
}

bool LPbase::download(std::string & s)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Test");

	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "LP base opened";

	QSqlQuery query(db);
	query.exec("SELECT * FROM 'User' ");
	
	QString sendmes;

	while (query.next())
	{
		 sendmes+=query.value(0).toString + "\t" << query.value(1) << "\t" << query.value(2);
	}
	/*
	QFile fin("log&pass.txt");
	fin.open(QIODevice::ReadOnly | QIODevice::Text);
	if (!fin.isOpen())
	{
		return false;
	}
	s = fin.readAll();
	fin.close();
	return true;
	*/
}

void LPbase::trans(std::string e)
{
	int i = 0;
	lopal td;
	std::string line;//взять первую запись из файла
	while (true) {
		while (e[i] != '\t') {
			line += e[i];
			i++;
		}
		td.log = line;
		line.clear();
		i++;


		while (e[i] != '\t') {
			line += e[i];
			i++;
		}
		//if (checkOtr(line))
		td.pas = line;
		line.clear();
		i++;
		while (e[i] != '\n') {
			line += e[i];
			i++;
			if (i >= e.size())
				break;
		}
		td.lev = line;
		line.clear();
		i++;
		add_data(td);
		if (i >= e.size())
			break;
	}
}

bool LPbase::del_data(int id)
{
	if (id == -1)
		return false;
	baza.erase(baza.begin() + id);
	return true;
}

int LPbase::find(std::string data2find)
{
	int i = 0;
	while (i < baza.size())
	{
		if ((baza[i].log == data2find) )//|| (baza[i].pas == data2find)|| (baza[i].lev == data2find))
			return i;

		i++;

	}
	return -1;
}

int LPbase::find(std::string data2find, int e)
{
	int i = e+1;
	while (i < baza.size())
	{
		if ((baza[i].log == data2find)) //|| (baza[i].pas == data2find) || (baza[i].lev == data2find))
			return i;

		i++;

	}
	return -1;
}

bool LPbase::write2file()//блестяще
{

	QFile fout("log&pass.txt");
	fout.open(QIODevice::WriteOnly | QIODevice::Text);
	if (!fout.isOpen())
	{
		return false;
	}
	QTextStream writeStream(&fout);
	int i = 0;
	s.clear();
	while (i < baza.size())
	{
		s += baza[i].log + "\t" + baza[i].pas + "\t" + baza[i].lev + "\n";
		i++;
	}
	QString str = str.fromStdString(s);
	writeStream << str;
	fout.close();
	return true;
}

QString LPbase::retrans()
{
	int i = 0;
	while (i < baza.size())
	{
		s += baza[i].log + "\t" + baza[i].pas + "\t" + baza[i].lev + "\n";
		i++;
	}
	QString str = str.fromStdString(s);
	return str;
}



