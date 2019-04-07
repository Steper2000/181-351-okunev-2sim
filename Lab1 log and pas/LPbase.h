#pragma once
//#include "classdb.h"
#include <string>
#include <vector>
#include < QFile>
#include <QTextStream> 
struct lopal
{
	std::string log;
	std::string pas;
	std::string lev;
};

class LPbase //:public DataBase
{
private: std::string s;
public:
	std::vector <lopal> baza;
	LPbase();
	~LPbase();
	bool download(std::string & s);
	void download()//загружаем данные из файла в vector
	{
		std::string strFromFile;
		download(strFromFile);
		trans(strFromFile);
	}
	void trans(std::string e);
	bool add_data(lopal l);
	bool del_data(int id);//удалить запись с заданным id

	int find(std::string data2find);
	int find(std::string data2find, int e);//найти id
	bool write2file();

};

