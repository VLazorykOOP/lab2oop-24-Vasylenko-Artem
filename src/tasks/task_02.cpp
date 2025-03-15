#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

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

void outputArray(const vector<vector<char>> &array)
{
	for (const auto &row : array)
	{
		for (char ch : row)
			cout << ch;
		cout << endl;
	}
}

int calculateParity(int value, int bitCount)
{
	int count = 0;
	for (int k = 0; k < bitCount; k++)
		if ((value >> k) & 1)
			count++;

	return count & 1;
}

using namespace std;

void task_02()
{
	FileManager binaryInput("public/binaryInput.txt");

	const int rows = 8,
			  cols = 8;

	vector<vector<char>> array(rows, vector<char>(cols));

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

	outputArray(array);

	unsigned short binData[64];

	int count = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			int firstSet = calculateParity((array[i][j] >> 4), 4) + calculateParity(i, 4);
			int secondSet = calculateParity(array[i][j], 4) + calculateParity(j, 4);

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

	vector<vector<char>> outCharData(rows, vector<char>(cols));
	int countBin = 0;

	for (int i = 0; i < 64; i++)
	{
		int colsBin = 0, rowsBin = 0;
		char symbolBin = 0;

		rowsBin = binData[i] >> 13;
		colsBin = (binData[i] >> 1) & 7;

		symbolBin = binData[i] >> 9 & 15;
		symbolBin <<= 4;
		symbolBin |= (binData[i] >> 4) & 15;

		int firstSet = calculateParity((symbolBin >> 4), 4) + calculateParity(rowsBin, 4);
		int secondSet = calculateParity(symbolBin, 4) + calculateParity(colsBin, 4);

		if (((binData[i] >> 8) & 1) == (firstSet & 1) && ((binData[i]) & 1) == (secondSet & 1))
		{
			cout << i << " - " << bitset<16>(binData[i]) << " - Integirity passed: " << symbolBin << endl;
			outCharData[rowsBin][colsBin] = symbolBin;
		}
		else
		{
			cout << i << " - " << bitset<16>(binData[i]) << " - Integirity failed: " << symbolBin << endl;
		}
	}

	outputArray(outCharData);
}