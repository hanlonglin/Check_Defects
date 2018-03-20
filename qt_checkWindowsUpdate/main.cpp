#include <QtCore/QCoreApplication>
#include <qdir.h>
#include "SystemDefects.h"
#include "DbUtil.h"
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	//设置当前目录为exe所在目录
	QDir::setCurrent(QCoreApplication::applicationDirPath());

	cout << "正在检测系统补丁......"<< endl;
	SystemDefects sysDefects;
	DbUtil dbUtil;

	QList<QString> InstalledList;
	QList<QString> dbList;
	QList<QString> unInstalledList;

	//获取本机已安装的补丁
	int ret = sysDefects.getInstalledDefects(InstalledList);
	if (!ret)
		goto end;
	//获取数据库保存的补丁
	ret = dbUtil.searchNames(dbList);
	if (!ret)
		goto end;
	//比对，得出缺少的补丁
	for (QString s:dbList)
	{
		if (!InstalledList.contains(s))
		{
			unInstalledList.append(s);
		}
	}
	if (unInstalledList.size() == 0)
		return 0;
	cout << "检测到未安装的系统补丁数量：" << unInstalledList.size() << endl;
	cout << "//***************************" << endl;
	for (QString s:unInstalledList)
	{
		cout <<"  "<< s.toStdString().c_str() << endl;
	}
	cout << "//***************************" << endl;
end:
	{
		cout << "检测完成" << endl;
		system("pause");
	}
	return a.exec();
}
