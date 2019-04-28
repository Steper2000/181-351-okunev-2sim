#include <iostream>
#include "Lab1logandpas.h"
#include <QMessageBox>
#include "menu.h"
#include <string>
#include "classdb.h"
#include "showDB.h"
#include "admenu.h"
#include "LPbase.h"

//#include <fstream>

Lab1logandpas::Lab1logandpas(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	saske = new QTcpSocket(this);
	saske->connectToHost("127.0.0.1", 33333);
	connect(saske, SIGNAL(connected()), SLOT(slot_connected()));
	connect(saske, SIGNAL(readyRead()), SLOT(slot_ready_read()));

}

void Lab1logandpas::slot_connected()
{
	QMessageBox msgBox;
	msgBox.setText("Hello! You are on the server");
    msgBox.exec();
}

void Lab1logandpas::slot_ready_read()
{
	QByteArray arr;
	std::string mess;
	
	while (saske->bytesAvailable() > 0)
	{
		arr = saske->readAll();
		mess = arr.toStdString();
	}
	/*QMessageBox m;
	m.setText(QString::fromStdString(mess));
	m.exec();*/
	
	if (mess == "admin")
	{
		admenu m;
		m.setModal(true);
		m.exec();
		//msgBox.setText("Hello, admin " + login);
		//msgBox.exec();
	}
	else
	{
		//	std::string sl = login.toStdString(); //копирует логин
			//	std::string sll; // первые 7 символов логина
			//	sll.insert(0, sl, 0, 7);
			//	if (sll == "manager")
		if (mess == "manager")
		{
			menu m;
			m.setModal(true);
			m.exec();
			//msgBox.setText("Hello manager!");
		   // msgBox.exec();
		}
		else
		{
			if (mess == "user")
			{//msgBox.setText("Hello "+login+"!");
			//msgBox.exec();
				showDB m;
				m.setModal(true);
				m.exec();
			}
			else
			{
				QMessageBox msgBox;
				msgBox.setText("Wrong login or password");
				msgBox.setInformativeText("Again?");
				msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
				msgBox.setDefaultButton(QMessageBox::Save);
				msgBox.exec();
			}
		}
	}
}

void Lab1logandpas::slot_send_to_server(QString mess)
{
	QByteArray arr;
	arr.append(mess);
	saske->write(arr);
}

void Lab1logandpas::slot_disconected()
{

}

/*
int autorise(QString login, QString password)
{
	if (login == "" || password == "") {
		return 0;
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
				return 0;
				//break;
			}
		}
		
		i = fgetc(base);
		
		while (i != '\t')
		{
	     sp = sp + i;
	     i = fgetc(base);
		}
		
		i=fgetc(base);
	
        if (login == sl && password == sp)
		{
			if (i=='a')
			return 2;
			if (i == 'm')
				return 3;
			if (i == 'u')
				return 4;
			//break;
		}
		/*
		if (sl=="\n") 
		{
			return 0;
			break;
		}
		sl.clear();
		sp.clear();
	}
	//base.close();
	fclose(base);
}
*/

void Lab1logandpas::on_pushButton_autorise_clicked()
{
	QString login = ui.line_login->text();
	QString password = ui.line_password->text();
	QMessageBox msgBox;
	QString message;
	message = "autorize " + login + " " + password;
	slot_send_to_server(message);

	/*
	if (autorize(login, password) == "admin")
	{
		admenu m;
		m.setModal(true);
		m.exec();
		//msgBox.setText("Hello, admin " + login);
		//msgBox.exec();
	}
	else 
	{		
	//	std::string sl = login.toStdString(); //копирует логин
		//	std::string sll; // первые 7 символов логина
		//	sll.insert(0, sl, 0, 7);
		//	if (sll == "manager")
		if (autorize(login, password) == "manager")
		{
				menu m;
			m.setModal(true);
			m.exec();
			  //msgBox.setText("Hello manager!");
			 // msgBox.exec();
		}
	    else
		{
			if (autorize(login, password) == "user")
			{//msgBox.setText("Hello "+login+"!");
			//msgBox.exec();
				showDB m;
				m.setModal(true);
				m.exec();
			}
			else
	        {
				msgBox.setText("Wrong login or password");
				msgBox.setInformativeText("Again?");
				msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
				msgBox.setDefaultButton(QMessageBox::Save);
				msgBox.exec();
	        }
		}
	}
	
	
	/*int res = msgBox.exec();
	if (res == QMessageBox::Close)
	{
		close();
	}*/
	
}

void Lab1logandpas::on_Ftest_clicked()
{	
	//kek();
	//autorize("a", "a");
	/*
	lopal lol;
	//QString a = ui.line_Nlogin->text();
	lol.log = "w";//a.toStdString();
	//QString b = ui.line_Npassword->text();
	lol.pas = "w";//b.toStdString();
	//QString c = ui.line_level->text();
	lol.lev = "a";//c.toStdString();
	LPbase lpb;
	lpb.download();
	lpb.add_data(lol);
	int o =lpb.find("q");
	lpb.del_data(o);
	lpb.write2file();
	*/
	//checkDate("1.10.2000");
	//checkDate("10.10.2000");
	//checkDate("41.10.2000");
	//checkDate("1.50.2000");
	/*
	datas da;
	da.pred = "alax";
	da.date = "1.06.2001";
	da.nal = "dan";
	da.otr = "rap";
	da.sum = "1000";
	datas das;
	das.pred = "Jesus";
	das.date = "7.01.2000";
	das.nal = "indulg";
	das.otr = "god";
	das.sum = "2000";
	DataBase s;
	s.download();
	s.add_data(da);
	s.add_data(das);
	s.find("indulg");
	s.del_data(1);
	s.write2file();*/
}