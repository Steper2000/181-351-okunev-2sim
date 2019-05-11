#include "add.h"
#include <QMessageBox>
// надо там же где и таблица
//
add::add(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	saske = new QTcpSocket(this);
	saske->connectToHost("127.0.0.1", 33333);
	connect(saske, SIGNAL(connected()), SLOT(slot_connected()));
	connect(saske, SIGNAL(readyRead()), SLOT(slot_ready_read()));
	//slot_send_to_server("Nolog");
}

add::~add()
{
}

void add::on_pushButton_del_clicked()//сомнительное, но чётко работающее удаление
{
	datas da;
	//DataBase db;
	QString a = ui.ld1->text();
	if (a!="")
	{
		if (a == "0") 
		{
			QMessageBox m;
			m.setText("Nothing wasn't added for delete");
			m.exec();
		}
		else 
		{
			int id = a.toInt();
			//db.download();
		//	base.del_data(id);
			//db.write2file();
		//	slot_send_to_server("changeDB " + base.retrans());
			QMessageBox m;
			m.setText("Data deleted from server");
			m.exec();
		}
	}
	else
	{
		a = ui.ld2->text();
		if (a != "") {
			//db.download();
			//base.del_data(base.find(a.toStdString()));
			//db.write2file();
			slot_send_to_server("deleteDB " + a);
				QMessageBox m;
				m.setText("Data deleted from server");
				m.exec();
			
		}
		else{
			QMessageBox m;
			m.setText("Nothing wasn't added for delete");
			m.exec();
		}
	}
}

void add::on_pushButton_add_clicked() //добавляет чётко
{
	datas da;
	QString a= ui.lc->text();
	da.pred = a.toStdString();
	QString b = ui.li->text();
	da.otr = b.toStdString();
	QString c = ui.ld->text();
	da.date = c.toStdString();
	QString d = ui.ln->text();
	da.nal = d.toStdString();
	QString e = ui.ls->text();
	da.sum = e.toStdString();
	//DataBase db;
	//db.download();
	//db.add_data(da);
	if (checkPred(da.pred) && checkOtr(da.otr) && checkDate(da.date) && checkNal(da.nal) && checkSum(da.sum))
	{
		//base.write2file();
		
		slot_send_to_server("addDB "+ a + '\t' + b + '\t' + c + '\t' + d + '\t' + e);
		QMessageBox m;
		m.setText("Data sent on the server");
		m.exec();
	}
	else{ QMessageBox m;
		m.setText("Data don't add! Wrong Industry or Sum or Date or Tax!");
		m.exec(); }
}
