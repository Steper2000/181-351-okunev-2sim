#include "classdb.h"
#include <fstream>
#include <string>
#include <cctype>   // ��� ������� isdigit
//#include <cstdlib>  // ��� ������� atoi
bool DataBase::add_data(datas tempData)//�����
{
	//download(sdb);
	if (checkPred(tempData.pred) && checkOtr(tempData.otr) && checkDate(tempData.date) &&checkSum(tempData.sum)) 
	{
		db.push_back(tempData);
		//transformStr2BD(sdb);
		//sdb +="\n"+ tempData.pred+"\t" + tempData.otr+"\t"  + tempData.date+ "\t"  + tempData.nal+"\t" + tempData.sum;
		return true;
	}
	else 
		return false;
}

bool DataBase::download(std::string & res) //�������� �����
{
	QFile fin("database.txt");
	fin.open(QIODevice::ReadOnly | QIODevice::Text);
	if (!fin.isOpen()) 
	{ return false; }
	res = fin.readAll();
	fin.close();
	return true;
}

void DataBase::transformStr2BD(std::string sdb)// �����
{
	int i = 0;
	datas td;
	std::string line;//����� ������ ������ �� �����
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

bool DataBase::del_data(int id)//���������
{
	if(id==0)
	return false;
	db.erase(db.begin() + id);
	return true;
}

int DataBase::find(std::string data2find)//����
{
	int i = 1;
	while (i < db.size()) 
	{
		if ((db[i].pred == data2find) || (db[i].otr == data2find) || (db[i].date == data2find) || (db[i].nal == data2find) || (db[i].sum == data2find))
			return i;
	
			i++;
			
	}
	return 0;
}

bool DataBase::write2file()//��������
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

bool checkPred(std::string pred)
{
	for (int i = 0; i < pred.size(); i++)
	{
		if (isdigit(pred[i]))
			return false;
	}
	return true;
}

bool checkOtr(std::string otr)//�������� again
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
	if (isdigit(date[1]))
	{
		if (isdigit(date[3]) && isdigit(date[4]) && (date[5] == '.') && isdigit(date[6]) && isdigit(date[7]) && isdigit(date[8]) && isdigit(date[9]))
			return true;
	}
	else
	{
		if (date[1] == '.')
		{
			if (isdigit(date[2]) && isdigit(date[3]) && (date[4] == '.') && isdigit(date[5]) && isdigit(date[6]) && isdigit(date[7]) && isdigit(date[8]))
				return true;
		}
	}
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
