#include "encryption.h"
#include <iostream>

#include <fstream>

using namespace std;

void readInputFile(unsigned char charData[ROWS][COLS], string filename)
{
	ifstream binaryInput(filename, ios::out | ios::binary);

	if (!binaryInput.is_open())
	{
		cerr << "No such file: " << filename << endl;
		return;
	}

	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
		{
			unsigned char ch;

			do
			{
				ch = binaryInput.get();
			} while (ch == '\n' && !binaryInput.eof() && COLS - 1 != j);

			charData[i][j] = !binaryInput.fail() ? ch : ' ';
		}

	binaryInput.close();
}

void printArray(unsigned char charData[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (char ch : charData[i])
			cout << ch;
		cout << endl;
	}
}

int calcParity(int value, int bitCount)
{
	int count = 0;
	for (int k = 0; k < bitCount; k++)
		if ((value >> k) & 1)
			count++;

	return count & 1;
}

string charToBinary(unsigned int ch, int bitCount)
{
	string binary;

	for (int i = bitCount - 1; i >= 0; i--)
		binary += (ch & (1 << i)) ? '1' : '0';

	return binary;
}

void decode(unsigned short binData[ROWS * COLS], unsigned char charData[ROWS][COLS])
{
	int count = 0;
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
		{
			char ch = charData[i][j];

			int firstSet = (calcParity((ch >> 4), 4) + calcParity(i, 4)) & 1;
			int secondSet = (calcParity(ch, 4) + calcParity(j, 4)) & 1;

			unsigned short encoded = (i & 7);	  // у бітах 0 - 2 знаходиться номер рядка символу(3 біти),
			encoded = (encoded << 4) | (ch >> 4); // у бітах 3 - 6 молодша частина ASCII - коду символу(4 біти),
			encoded = (encoded << 1) | firstSet;  // 7 біт – біт парності перших двох полів(1 біт)
			encoded = (encoded << 4) | (ch & 15); // у бітах 8 - 11 старша частина ASCII - коду символу(4 біти),
			encoded = (encoded << 3) | j;		  // у бітах 12 - 14 позиція символу в рядку(3 біти),
			encoded = (encoded << 1) | secondSet; // 15 біт - біт парності попередніх двох полів(1 біт).

			binData[count++] = encoded;
		}
}

void encode(unsigned char charData[ROWS][COLS], unsigned short binData[ROWS * COLS])
{
	int count = 0;

	for (int i = 0; i < 64; i++)
	{
		unsigned short temp = binData[i];

		int rows = temp >> 13;
		int cols = (temp >> 1) & 7;

		char symbol = (((temp >> 9) & 15) << 4) | ((temp >> 4) & 15);

		int firstSetTemp = (temp >> 8) & 1;
		int secondSetTemp = temp & 1;

		int firstSet = (calcParity((symbol >> 4), 4) + calcParity(rows, 4)) & 1;
		int secondSet = (calcParity(symbol, 4) + calcParity(cols, 4)) & 1;

		string binary = charToBinary(temp, 16);

		if ((firstSetTemp == firstSet) && (secondSetTemp == secondSet))
		{
			cout << i + 1 << " - " << binary << " - Integirity passed: " << symbol << endl;
			charData[rows][cols] = symbol;
		}
		else
		{
			cout << i + 1 << " - " << binary << " - Integirity failed: " << symbol << endl;
		}
	}
}