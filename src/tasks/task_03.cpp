#include <iostream>

#include "taskManager.h"
#include "encryption.h"
#include "fileManager.h"
#include "console.h"

// Реалізувати завдання 2 з використанням структур з бітовими полями та об’єднаннями.
using namespace std;

typedef struct crypto
{
	union cryptoSymbol
	{
		struct
		{
			unsigned int secondSet : 1;
			unsigned int col : 3;
			unsigned int seniorSymbol : 4;
			unsigned int firstSet : 1;
			unsigned int juniorSymbol : 4;
			unsigned int row : 3;
		};
		unsigned int symbol;

	} cryptoSymbol;

	char binaryToChar() { return ((cryptoSymbol.juniorSymbol << 4) | (cryptoSymbol.seniorSymbol)); }
} crypto;

void decode2(unsigned short binData[ROWS * COLS], unsigned char charData[ROWS][COLS])
{
	int count = 0;
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
		{
			char ch = charData[i][j];

			int firstSet = (calcParity((ch >> 4), 4) + calcParity(i, 4)) & 1;
			int secondSet = (calcParity(ch, 4) + calcParity(j, 4)) & 1;

			crypto encodedSymbol;

			encodedSymbol.cryptoSymbol.row = i;				   // у бітах 0 - 2 знаходиться номер рядка символу(3 біти),
			encodedSymbol.cryptoSymbol.juniorSymbol = ch >> 4; // у бітах 3 - 6 молодша частина ASCII - коду символу(4 біти),
			encodedSymbol.cryptoSymbol.firstSet = firstSet;	   // 7 біт – біт парності перших двох полів(1 біт)
			encodedSymbol.cryptoSymbol.seniorSymbol = ch;	   // у бітах 8 - 11 старша частина ASCII - коду символу(4 біти),
			encodedSymbol.cryptoSymbol.col = j;				   // у бітах 12 - 14 позиція символу в рядку(3 біти),
			encodedSymbol.cryptoSymbol.secondSet = secondSet;  // 15 біт - біт парності попередніх двох полів(1 біт).

			binData[count++] = encodedSymbol.cryptoSymbol.symbol;
		}
}

void encode2(unsigned char charData[ROWS][COLS], unsigned short binData[ROWS * COLS])
{
	int count = 0;

	for (int i = 0; i < 64; i++)
	{
		crypto temp;
		temp.cryptoSymbol.symbol = binData[i];

		int rows = temp.cryptoSymbol.row;
		int cols = temp.cryptoSymbol.col;

		char symbol = temp.binaryToChar();

		int firstSetTemp = temp.cryptoSymbol.firstSet;
		int secondSetTemp = temp.cryptoSymbol.secondSet;

		int firstSet = (calcParity((symbol >> 4), 4) + calcParity(rows, 4)) & 1;
		int secondSet = (calcParity(symbol, 4) + calcParity(cols, 4)) & 1;

		string binary = charToBinary(temp.cryptoSymbol.symbol, 16);

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

void task_03()
{
	string filepath = "public/binary/output";

	FileManager inputFile(filepath + ".txt");
	FileManager outputFile(filepath + ".dat");

	inputFile.checkFile();
	outputFile.checkFile();

	unsigned char array[ROWS][COLS];
	unsigned short decodeArray[ROWS * COLS];
	unsigned short encodeArray[ROWS * COLS];
	unsigned char outCharData[ROWS][COLS];

	readInputFile(array, inputFile.filename);
	printArray(array);

	newLine();

	decode2(decodeArray, array);

	outputFile.writeFile(decodeArray);
	outputFile.readFile(encodeArray);

	encode2(outCharData, encodeArray);

	newLine();
	printArray(outCharData);
}
