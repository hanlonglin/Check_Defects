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
	 *获取数据库中的补丁列表
	 *list传入参数，补丁列表
	 *返回：成功1 失败0
	 */
	int searchNames(QList<QString>& list);

private:

	QString readIP();
	bool connectDB();
	bool closeDB();
	//属性
	QSqlDatabase dbConn;
	QSqlQuery sQuery;
};

