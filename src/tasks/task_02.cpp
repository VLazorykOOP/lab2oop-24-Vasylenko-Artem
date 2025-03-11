#include <iostream>
#include <fstream>

#include "taskManager.h"
#include "console.h"
#include "fileManager.h"

// Задано 8 рядків тексту. У рядку до 8 символів. Доповнити пробілами рядки до 8 символів.
// Шифрувати тексти таким чином, щоб кожний символ тексту записувався у два байти.Два байти мають таку структуру:

// у бітах 0 - 2 знаходиться номер рядка символу(3 біти),
// у бітах 3 - 6 молодша частина ASCII - коду символу(4 біти),
// 7 біт – біт парності перших двох полів(1 біт)
// у бітах 8 - 11 старша частина ASCII - коду символу(4 біти),
// у бітах 12 - 14 позиція символу в рядку(3 біти),
// 15 біт - біт парності попередніх двох полів(1 біт).

using namespace std;

void task_02()
{
	FileManager testFile("public/binaryInput.txt");
	testFile.openFile();

	const int rows = 8, cols = 8;
	char array[rows][cols] = {};

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols + 1; j++)
		{
			char ch = testFile.inFile.get();

			if (j == cols && ch != '\n')
				break;

			if (ch == '\n')
			{
				while (j < cols)
					array[i][j++] = '+';
				break;
			}

			!testFile.inFile.fail() ? array[i][j] = ch : array[i][j] = '+';
		}

	testFile.closeFile();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << array[i][j];
		cout << endl;
	}
}