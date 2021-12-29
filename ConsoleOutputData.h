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
	std::string m_dataName;//�������ʲô����,����Ѫ������ʽ���Ƶ�
	std::string m_dataContent;//��ź�������
	COORD m_consolePos;//��¼���λ��
	int m_countOfPrintedWord;
};

