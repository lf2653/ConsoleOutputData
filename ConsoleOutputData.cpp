#include "ConsoleOutputData.h"

ConsoleOutputData::ConsoleOutputData(std::string dataType) :m_dataName(dataType)
{
	HWND hConsole = GetConsoleWindow();
	if (hConsole == NULL)
		AllocConsole();
	int x, y;
	getConsolePos(&x, &y);
	m_consolePos.X = 0;
	m_consolePos.Y = y + 1;
	setConsolePos(0, y + 1);
	m_dataContent = "";
}

void ConsoleOutputData::updateDataContent(std::string content)
{
	if (content == m_dataContent)
		return;
	m_dataContent = content;
	setConsolePos(m_consolePos.X, m_consolePos.Y);
	std::string cleanScreen;
	for (int i = 0; i < m_countOfPrintedWord; i++)
		cleanScreen += " ";
	std::cout << cleanScreen.c_str() << std::endl;
	setConsolePos(m_consolePos.X, m_consolePos.Y);
	std::cout << m_dataName.c_str() << ":" << m_dataContent.c_str() << std::endl;
	m_countOfPrintedWord = m_dataName.size() + m_dataContent.size() + 1;
}

std::string ConsoleOutputData::getDataType()
{
	return m_dataName;
}

void ConsoleOutputData::setConsolePos(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleOutputData::getConsolePos(int* x, int* y)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	*x = info.dwCursorPosition.X;
	*y = info.dwCursorPosition.Y;
}