#pragma once
#include <qstring.h>
#include <qsettings.h>
#include <iostream>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqlerror.h>


#define IP_SECTION "Server"
#define IP3        "IP3"

#define CONFIG_PATH  "config.ini"
#define DBNAME     "extension"
#define PORT        7001
#define USER       "sa"
#define PASSWORD   "Headsense@2018"

using namespace std;
class DbUtil
{
public:
	DbUtil();
	~DbUtil();

	/*
	 *��ȡ���ݿ��еĲ����б�
	 *list��������������б�
	 *���أ��ɹ�1 ʧ��0
	 */
	int searchNames(QList<QString>& list);

private:

	QString readIP();
	bool connectDB();
	bool closeDB();
	//����
	QSqlDatabase dbConn;
	QSqlQuery sQuery;
};

