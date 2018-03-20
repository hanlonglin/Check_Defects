#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <qlist.h>
#include "DbUtil.h"

using namespace std;

class SystemDefects
{
public:
	SystemDefects();
	~SystemDefects();

	/*执行获取已安装的补丁
	*list 补丁列表
	*返回 成功1 失败0
	*/
	int getInstalledDefects(QList<QString>& list);

private:

	/*执行cmd
	*cmd:命令行
	*result 输出结果
	*返回 成功1 失败0
	*/
	int execCmd(char* cmd, char* result);

	DbUtil dbutil;
};

