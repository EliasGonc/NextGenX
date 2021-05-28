#include "consolecursor.h"

COORD consoleCursorPosition = { };

COORD getConsoleCursorPosition() {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi = { };
	GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
	return csbi.dwCursorPosition;
}

void mySetConsoleCursorPosition() {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, consoleCursorPosition);
}

