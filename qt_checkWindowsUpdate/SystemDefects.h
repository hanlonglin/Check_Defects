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

	/*ִ�л�ȡ�Ѱ�װ�Ĳ���
	*list �����б�
	*���� �ɹ�1 ʧ��0
	*/
	int getInstalledDefects(QList<QString>& list);

private:

	/*ִ��cmd
	*cmd:������
	*result ������
	*���� �ɹ�1 ʧ��0
	*/
	int execCmd(char* cmd, char* result);

	DbUtil dbutil;
};

