#include "change.h"
#include <QFile>
#include <string>
#include <fstream>
//#include "classdb.h"
//#include "Lab1logandpas.h"
change::change(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

change::~change()
{
}
/*
struct data {
	std::string a;
	std::string b;
	std::string c;
};
bool checkA(std::string a); //�������� ������
bool checkB(std::string b);
bool checkC(std::string c);

class DataBase
{
private:	std::vector<data>* db;
			FILE* fin
public: 
	DataBase();//�����������
	DataBase(std::string* tempDB);// ���������� �� ������ � ������� �������� ��, ��������� ��
		~DataBase();
		bool add_data(data tempData);//�������� ������ ������ � ��
		bool open(std::string filename);//��������� ����
		bool download(std::string& res);//��������� �� ����� ������
		bool close();//�������� �����
		bool download()//��������� ������ �� ����� � ������
		{
			std::string strFromFile;
			open(a.txt);
			download(strFromFile);
			close();
			trans(strFromFile);
		}
		bool parsing(std::string line);
		bool trans(std::string e)//����������� ������ � �� 
		{
			std::string line;// ����� ������ ������ �� �����
			//line=...
			data tempData;
			tempData=parsing(line);
			add_data(tempData);
		}
		bool del_data(std::string id); //������� ������ � �������� id
		template<typename T>
			std::vector<data> find(int crinterior, T data2find);//����� ������
			bool change(std::string id, data tempData)
			{
				db[id] = tempData;
		}
			bool write();
}*/
/*
	//FILE *b;
	//b=fopen("database.txt", "w");
	QFile b("database.txt");
	b.open(QIODevice::Append | QIODevice::Text);
	if (b.isOpen()) { int x;
	x = 1; }
	QString blogpass = ui.line_blogin->text() + " " + ui.line_bpass->text();
	//char blp[52] = ui.line_blogin->text() + " " + ui.line_bpass->text();
		QString nlog = ui.line_Nlogin->text();
		QString npass = ui.line_Npassword->text();
	*/	
void change::on_pushButton_change_clicked()
{
	
		
}