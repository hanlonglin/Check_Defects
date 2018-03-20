#include "SystemDefects.h"



SystemDefects::SystemDefects()
{
}


SystemDefects::~SystemDefects()
{
}


int SystemDefects::execCmd(char *cmd, char * result)
{
	char buffer[128];
	FILE * pipe = _popen(cmd, "r");
	if (!pipe)
		return 0;
	while (!feof(pipe))
	{
		if (fgets(buffer, 128, pipe))
		{
			strcat(result, buffer);
		}
	}
	_pclose(pipe);
	return 1;
}


int SystemDefects::getInstalledDefects(QList<QString> &list)
{
	//QList<QString> list;
	char result[1024 * 8] = "";
	char *cmd = "wmic qfe get hotfixid";
	if (1 == execCmd(cmd, result))
	{
		QString resultStr = QString::fromLocal8Bit(result);
		if (resultStr.contains("KB"))
		{
			resultStr = resultStr.mid(resultStr.indexOf("HotFixID") + 8);
			QStringList defectList = resultStr.split("\r\n");
			for (QString s : defectList)
			{
				if (s.contains("KB"))
					list.append(s.trimmed());  //这里必须去掉空格
			}
			return 1;
		}
	}
	else {
		cout << "获取已安装补丁命令执行失败！" << endl;
		return 0;
	}
	//cout << "defectList.size():" << list.size() << endl;
	return 0;
}

