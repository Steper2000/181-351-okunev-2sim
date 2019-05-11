#pragma once

#include <QString>
#include <qbytearray.h>
#include <string>
#include <TinyAES.h>


class crypto 
{
public:
	crypto();
	~crypto();

	QByteArray encrypt(QByteArray message);
	QByteArray decrypt(QByteArray message);
	QByteArray password = "d4af1bc61f60a73064e4f599da1fb378";
	
	//unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	//unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	
	
};

