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

	int count = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			int firstSet = 0, secondSet = 0;
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

			// у бітах 0 - 2 знаходиться номер рядка символу(3 біти),
			binData[count] = i;

			// у бітах 3 - 6 молодша частина ASCII - коду символу(4 біти),
			binData[count] <<= 4;
			binData[count] |= (array[i][j] >> 4);

			// 7 біт – біт парності перших двох полів(1 біт)
			binData[count] <<= 1;
			binData[count] |= (firstSet & 1);

			// у бітах 8 - 11 старша частина ASCII - коду символу(4 біти),
			binData[count] <<= 4;
			binData[count] |= (array[i][j] & 15);

			// у бітах 12 - 14 позиція символу в рядку(3 біти),
			binData[count] <<= 3;
			binData[count] |= j;

			// 15 біт - біт парності попередніх двох полів(1 біт).
			binData[count] <<= 1;
			binData[count] |= (secondSet & 1);

			++count;
		}

	newLine();

	ofstream binaryOutput("public/binaryOutput.dat", ios::out | ios::binary);
	binaryOutput.write((char *)binData, sizeof(unsigned short) * 64);
	binaryOutput.close();

	FILE *f = fopen("public/binaryOutput.dat", "r");
	fread(binData, sizeof(char), 128, f);
	fclose(f);

	for (int i = 0; i < 64; i++)
	{
		if (i % 8 == 0)
			cout << endl;
		cout << bitset<16>(binData[i]) << endl;
	}

	char outCharData[rows][cols];
	int countBin = 0;

	for (int i = 0; i < 64; i++)
	{
		int firstSet = 0, secondSet = 0;
		int colsBin = 0, rowsBin = 0;
		char symbolBin = 0;

		rowsBin = binData[i] >> 13;
		colsBin = (binData[i] >> 1) & 7;

		symbolBin = binData[i] >> 9 & 15;
		symbolBin <<= 4;
		symbolBin |= (binData[i] >> 4) & 15;

		for (int k = 0; k < 4; k++)
		{
			if (((symbolBin >> 4) >> k) & 1)
				firstSet++;

			if ((rowsBin >> k) & 1)
				firstSet++;

			if ((symbolBin >> k) & 1)
				secondSet++;

			if ((colsBin >> k) & 1)
				secondSet++;
		}

		if (((binData[i] >> 8) & 1) == (firstSet & 1) && ((binData[i]) & 1) == (secondSet & 1))
		{
			cout << i << " - " << bitset<16>(binData[i]) << " - Integirity passed: " << symbolBin << endl;
			outCharData[rowsBin][colsBin] = symbolBin;
		}
		else
		{
			cout << "Error\n";
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << outCharData[i][j];
		}
		cout << endl;
	}
}