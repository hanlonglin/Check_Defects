#pragma once

#include <QObject>
#include <iostream>
using namespace std;

class SystemDefect : public QObject
{
	Q_OBJECT

public:
	SystemDefect(QObject *parent);
	
	~SystemDefect();

	//cmd��ȡ
	int execCmd(char* cmd, char* result);

	QList<QString> getSysDefects();
};
