#include <iostream>

#include "console.h"

void clearConsole()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void pauseConsole()
{
	std::cout << "\nPress any key to continue...\n";
	getchar();
	getchar();
	clearConsole();
}

void newLine()
{
	std::cout << std::endl;
}
