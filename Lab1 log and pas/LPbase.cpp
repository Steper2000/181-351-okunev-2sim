#include "LPbase.h"


LPbase::LPbase()
{
}

LPbase::~LPbase()
{
}

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
	QFile fin("log&pass.txt");
	fin.open(QIODevice::ReadOnly | QIODevice::Text);
	if (!fin.isOpen())
	{
		return false;
	}
	s = fin.readAll();
	fin.close();
	return true;
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



