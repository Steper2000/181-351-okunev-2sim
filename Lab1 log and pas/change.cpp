#include "change.h"
#include <QFile>
#include <string>
#include <fstream>

#include <QMessageBox>

//#include "classdb.h"
//#include "Lab1logandpas.h"
change::change(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	saske = new QTcpSocket(this);
	saske->connectToHost("127.0.0.1", 33333);
	connect(saske, SIGNAL(connected()), SLOT(slot_connected()));
	connect(saske, SIGNAL(readyRead()), SLOT(slot_ready_read()));
	slot_send_to_server("LPtable");
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

void change::on_del_clicked()
{
	lopal da;
//	LPbase db;
	QString a = ui.del_id->text();
	if (a != "")
	{
		int id = a.toInt();
		//base.download();
		if (id <1 || id>base.baza.size())
		{
			QMessageBox m;
			m.setText("Wrong number of the row");
			m.exec();
		}
		else
		{
			
			base.del_data(id-1);
			//base.write2file();
			slot_send_to_server("changeLP "+base.retrans());
			QMessageBox m;
			m.setText("User deleted on server");
			m.exec();
		}
	}
	else
	{
		a = ui.del_d->text();
		if (a != "") {
			//base.download();
			if (base.del_data(base.find(a.toStdString())))
			{
				//db.write2file();
				slot_send_to_server("changeLP " + base.retrans());
				QMessageBox m;
				m.setText("User deleted");
				m.exec();
			}
			else {
				QMessageBox m;
				m.setText("Nothing wasn't added for delete");
				m.exec();
			}

		}
		else {
			QMessageBox m;
			m.setText("Nothing wasn't added for delete");
			m.exec();
		}
	}
}

void change::on_pushButton_change_clicked()
{
	lopal lol;
	QString a = ui.line_Nlogin->text();
	lol.log = a.toStdString();
	QString b = ui.line_Npassword->text();
	lol.pas = b.toStdString();
	QString c = ui.line_level->text();
	lol.lev = c.toStdString();
	//LPbase lpb;
	//base.download();
	if (base.add_data(lol))
	{
		//base.write2file();
		slot_send_to_server("changeLP "+base.retrans());
		QMessageBox m;
		m.setText("User data sent on the server");
		m.exec();
	}
	else {
		QMessageBox m;
		m.setText("User don't add! Wrong level");
		m.exec();
	}
		
}