#include <QtCore/QCoreApplication>
#include <qdir.h>
#include "SystemDefects.h"
#include "DbUtil.h"
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	//���õ�ǰĿ¼Ϊexe����Ŀ¼
	QDir::setCurrent(QCoreApplication::applicationDirPath());

	cout << "���ڼ��ϵͳ����......"<< endl;
	SystemDefects sysDefects;
	DbUtil dbUtil;

	QList<QString> InstalledList;
	QList<QString> dbList;
	QList<QString> unInstalledList;

	//��ȡ�����Ѱ�װ�Ĳ���
	int ret = sysDefects.getInstalledDefects(InstalledList);
	if (!ret)
		goto end;
	//��ȡ���ݿⱣ��Ĳ���
	ret = dbUtil.searchNames(dbList);
	if (!ret)
		goto end;
	//�ȶԣ��ó�ȱ�ٵĲ���
	for (QString s:dbList)
	{
		if (!InstalledList.contains(s))
		{
			unInstalledList.append(s);
		}
	}
	if (unInstalledList.size() == 0)
		return 0;
	cout << "��⵽δ��װ��ϵͳ����������" << unInstalledList.size() << endl;
	cout << "//***************************" << endl;
	for (QString s:unInstalledList)
	{
		cout <<"  "<< s.toStdString().c_str() << endl;
	}
	cout << "//***************************" << endl;
end:
	{
		cout << "������" << endl;
		system("pause");
	}
	return a.exec();
}
