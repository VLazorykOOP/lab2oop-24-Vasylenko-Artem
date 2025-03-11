#include <iostream>
#include <fstream>
#include <string>

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

void task_02()
{
	const int rows = 8, cols = 8;
	char array[rows][cols] = {};

	ifstream binaryInput("public/binaryInput.txt", std::ios::binary);

	if (binaryInput.fail())
	{
		cout << "Error opening file";
		return;
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols + 1; j++)
		{
			char ch = binaryInput.get();

			if (j == cols && ch != '\n')
				continue;

			if (ch == '\n')
			{
				while (j < cols)
					array[i][j++] = '_';
				break;
			}

			if (!binaryInput.fail())
				array[i][j] = ch;
			else
				array[i][j] = '_';
		}

	binaryInput.close();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << array[i][j];
		cout << endl;
	}

	ofstream binaryOutput("public/binaryOutput.dat");
	binaryOutput.close();
}