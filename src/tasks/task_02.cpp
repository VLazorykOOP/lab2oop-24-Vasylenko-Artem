#include <iostream>
#include <fstream>

#include "taskManager.h"
#include "console.h"
#include "encryption.h"

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
	string inputFile = "public/binary/binaryInput.txt";
	string outputFile = "public/binary/binaryOutput.dat";

	unsigned char array[ROWS][COLS];

	readInputFile(array, "public/binary/binaryInput.txt");
	printArray(array);

	newLine();

	unsigned short decodeArray[ROWS * COLS];

	decode(decodeArray, array);

	ofstream binaryOutput(outputFile, ios::out | ios::binary);
	binaryOutput.write((char *)decodeArray, sizeof(unsigned short) * 64);
	binaryOutput.close();

	unsigned short encodeArray[ROWS * COLS];

	ifstream binaryInput(outputFile, ios::in | ios::binary);
	binaryInput.read((char *)encodeArray, sizeof(unsigned short) * 64);
	binaryInput.close();

	unsigned char outCharData[ROWS][COLS];

	encode(outCharData, encodeArray);

	newLine();
	printArray(outCharData);
}
