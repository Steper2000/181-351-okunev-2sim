#pragma once
#include <string>
#include <vector>
#include < QFile>
#include <QTextStream> // ���������� ����� QTextStream
//#include < QIODevice>


struct datas {
	std::string pred;
	std::string otr;
	std::string date;
	std::string nal;
	std::string sum;
};

bool checkPred(std::string pred);//������������ ������� - ������ �����; ���� ������� �� ���, ������ �� ����������.
bool checkOtr(std::string otr);
bool checkDate(std::string date);//��� ������ Date
bool checkNal(std::string nal);
bool checkSum(std::string sum);

class DataBase {

public:
	std::vector<datas> db; //* ��� ����
	DataBase() {};//�����������
	//DataBase(std::string* tempDB); //����������� �� ������: �.�. �� ������, � ������� �������� ��, ��������� ��
	~DataBase() {};//����������
	bool add_data(datas tempData);// �������� ������ ������ � ��
	bool download(std::string & res);//��������� ������ �� ����� � ������
	//bool close();// �������� �����
    //bool open(std::string filename);//��������� ����
	//data parsing(std::string line);
	
	void transformStr2BD(std::string sdb);// ����������� ������ � ��
	
	void download()//��������� ������ �� ����� � vector
	{
		std::string strFromFile;
		download(strFromFile);
		transformStr2BD(strFromFile);
	}

	bool del_data(int id);//������� ������ � �������� id

	int find(std::string data2find);
	int find(std::string data2find, int e);//����� id
//	template<typename T>
//std::vector<data> find(int criterior, T data2find);//����� ������ � �������� id

//	bool change(std::string id, data tempData)
//	{
//		//db[id] = tempData;
//	}

	bool write2file();

private:
	std::string sdb;
	//std::vector<datas> db; //* ��� ����
	//QFile fin("database.txt");

};



