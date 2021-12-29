#pragma once
#include <windows.h>
#include <iostream>

class ConsoleOutputData
{
public:
	std::string getDataType();
	void updateDataContent(std::string content);
	ConsoleOutputData(std::string dataType);
private:
	void setConsolePos(int x, int y);
	void getConsolePos(int* x, int* y);
	std::string m_dataName;//输出的是什么数据,例如血量、招式名称等
	std::string m_dataContent;//存放核心数据
	COORD m_consolePos;//记录输出位置
	int m_countOfPrintedWord;
};

