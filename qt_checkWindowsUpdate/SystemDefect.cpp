#include "SystemDefect.h"

SystemDefect::SystemDefect(QObject *parent)
	: QObject(parent)
{
}


SystemDefect::~SystemDefect()
{
}

int SystemDefect::execCmd(char *cmd, char * result)
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


QList<QString> SystemDefect::getSysDefects()
{
	QList<QString> defectList;
	char result[1024 * 4] = "";
	char *cmd = "wmic qfe get hotfixid";
	if (1 == execCmd(cmd, result))
	{
		QString resultStr = QString::fromLocal8Bit(result);
		resultStr = resultStr.mid(resultStr.indexOf("HotFixID") + 8);
		cout << "resultStr:" << resultStr.toStdString().c_str() << endl;
		QStringList defectList=resultStr.split("\n");
		for (QString s:defectList)
		{
			if (s.contains("KB"))
				defectList.push_back(s);
		}
	}
	return defectList;
}