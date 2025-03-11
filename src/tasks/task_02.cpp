#include <iostream>
#include <fstream>

#include <vector>

#include "tasks.h"
#include "console.h"

// Задано 8 рядків тексту. У рядку до 8 символів. Доповнити пробілами рядки до 8 символів.
// Шифрувати тексти таким чином, щоб кожний символ тексту записувався у два байти.Два байти мають таку структуру:

// у бітах 0 - 2 знаходиться номер рядка символу(3 біти),
// у бітах 3 - 6 молодша частина ASCII - коду символу(4 біти),
// 7 біт – біт парності перших двох полів(1 біт)
// у бітах 8 - 11 старша частина ASCII - коду символу(4 біти),
// у бітах 12 - 14 позиція символу в рядку(3 біти),
// 15 біт - біт парності попередніх двох полів(1 біт).

using namespace std;

// void showMenuTask()
// {
// 	cout << "Your choice:";
// 	cout << "\n1 - Read file input.txt";
// 	cout << "\n2 - Input your data";
// 	newLine();
// 	cout << "\nq - Quit";
// 	newLine();
// 	cout << "\nYour choice: ";
// }

// void chooseTask()
// {
// 	clearConsole();
// 	char ch;
// 	vector<char> validChoices = {'1', '2', '3', '4', 'q'};

// 	while (true)
// 	{
// 		showMenuTask();
// 		cin >> ch;
// 		bool selected = checkChoiceInput(ch, validChoices);

// 		if (!selected)
// 		{
// 			clearConsole();
// 			cout << "Invalid choice. Please try again.\n";
// 			pauseConsole();
// 			continue;
// 		}

// 		clearConsole();
// 		cout << "Task" << ch << " selected\n";
// 		newLine();

// 		switch (ch)
// 		{
// 		case '1':
// 			task_01();
// 			break;
// 		case '2':
// 			task_02();
// 			break;
// 		case 'q':
// 			return;
// 		}

// 		pauseConsole();
// 	}
// }

void task_02()
{
	char text[8][8];

	ofstream binaryOutput("public/binaryOutput.dat", ios::out | ios::binary);

	if (binaryOutput.fail())
	{
		cout << "Error opening file";
		return;
	}

	ofstream binaryInput("public/binaryInput.txt");

	if (binaryInput.is_open())
	{
		binaryInput << "test123";
		binaryInput.close();
	}

	cout << "test";
}