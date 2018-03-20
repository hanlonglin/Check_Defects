#include "DbUtil.h"



DbUtil::DbUtil()
{
}


DbUtil::~DbUtil()
{
}

QString DbUtil::readIP()
{
	QSettings *setting = new QSettings(CONFIG_PATH, QSettings::IniFormat);
	setting->setIniCodec("GBK");
	QString ip = setting->value(QString(IP_SECTION).append("/").append(IP3)).toString();
	delete setting;
	//cout << "�õ�ip:" << ip.toStdString().c_str() << endl;
	return ip;
}

bool DbUtil::connectDB()
{
	QString ip = readIP();
	if (ip == "")
	{
		cout << "δ�ҵ�config.ini�ļ���IP3Ϊ��!" << endl;
		return false;
	}
	dbConn = QSqlDatabase::addDatabase("QODBC",DBNAME);
	dbConn.setDatabaseName(QString("DRIVER={SQL SERVER};"
		"SERVER=%1,%2;"
		"DATABASE=%3;"
		"UID=%4;"
		"PWD=%5;").arg(ip).arg(PORT)
		.arg(DBNAME)
		.arg(USER)
		.arg(PASSWORD));


	if (!dbConn.open())
	{
		cout << "���ݿ�����ʧ�ܣ�ip:"<<ip.toStdString().c_str() << dbConn.lastError().text().toLocal8Bit().data() << endl;;
		return false;
	}
	return true;
}
bool DbUtil::closeDB()
{
	//if(sQuery.isActive())
	sQuery.clear();
	if (dbConn.isOpen())
		dbConn.close();
	return true;
}
int DbUtil::searchNames(QList<QString>& list)
{
	//�������ݿ�
	if (!connectDB())
	{
		return 0;
	}
	//��ʼ��ѯ
	sQuery = (QSqlQuery)dbConn;
	bool ret=sQuery.exec("select name from pack");
	if (!ret)
	{
		cout << "ִ��sql���ʧ�ܣ�" << sQuery.lastError().text().toLocal8Bit().data() << endl;
		return 0;
	}
	while (sQuery.next())
	{
		QString name = sQuery.value("name").toString();
		list.append(name);
	}
	closeDB();
	if (list.size() == 0)
	{
		cout << "��ѯ�����ݿ��в����б�Ϊ�գ�" << endl;
		return 0;
	}
	return 1;
}