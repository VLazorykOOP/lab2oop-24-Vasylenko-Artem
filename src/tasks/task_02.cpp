#include <iostream>
#include <fstream>
#include <bitset>

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
	FileManager binaryInput("public/binaryInput.txt");

	const int rows = 8,
			  cols = 8;
	char array[rows][cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols + 1; j++)
		{
			char ch = binaryInput.inFile.get();

			if (j == cols && ch != '\n')
				continue;

			if (ch == '\n')
			{
				while (j < cols)
					array[i][j++] = '+';
				break;
			}

			!binaryInput.inFile.fail() ? array[i][j] = ch : array[i][j] = '+';
		}

	binaryInput.closeFile();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << array[i][j];
		cout << endl;
	}

	unsigned short binData[64];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			int firstSet, secondSet;
			for (int k = 0; k < 4; k++)
			{
				if (((array[i][j] >> 4) >> k) & 1)
					firstSet++;

				if ((i >> k) & 1)
					firstSet++;

				if ((array[i][j] >> k) & 1)
					secondSet++;

				if ((j >> k) & 1)
					secondSet++;
			}

			binData[(i + 1) * (j + 1)] = i;
			binData[(i + 1) * (j + 1)] <<= 4;
			binData[(i + 1) * (j + 1)] |= (array[i][j] >> 4);
			binData[(i + 1) * (j + 1)] <<= 1;
			binData[(i + 1) * (j + 1)] |= (firstSet & 1);
			binData[(i + 1) * (j + 1)] <<= 4;
			binData[(i + 1) * (j + 1)] |= (array[i][j] & 15);
			binData[(i + 1) * (j + 1)] <<= 3;
			binData[(i + 1) * (j + 1)] |= j;
			binData[(i + 1) * (j + 1)] <<= 1;
			binData[(i + 1) * (j + 1)] |= (secondSet & 1);
		}

	ofstream binaryOutput("public/binaryOutput.dat", ios::out | ios::binary);
	binaryOutput.write((char *)binData, sizeof(unsigned short) * 64);
	binaryOutput.close();

	FILE *f = fopen("public/binaryOutput.dat", "r");
	fread(binData, sizeof(char), 128, f);
	fclose(f);

	for (int i = 0; i < 64; i++)
	{
		cout << bitset<16>(binData[i]) << endl;
	}
}