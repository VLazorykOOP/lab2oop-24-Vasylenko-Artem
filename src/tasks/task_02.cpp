#include <iostream>
#include <fstream>

#include "taskManager.h"
#include "console.h"
#include "encryption.h"
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
	string inputFile = "public/binary/binaryInput.txt";
	string outputFile = "public/binary/binaryOutput.dat";

	FileManager file(inputFile);
	// file.checkFile("fstream");

	// file.checkFile("ifstream");
	// file.checkFile("ofstream");

	ifstream binaryInput(inputFile, ios::out | ios::binary);

	unsigned char array[ROWS][COLS];
	unsigned short decodeArray[ROWS * COLS];
	unsigned short encodeArray[ROWS * COLS];
	unsigned char outCharData[ROWS][COLS];

	readInputFile(array, "public/binary/binaryInput.txt");
	printArray(array);

	newLine();

	decode(decodeArray, array);

	file.writeFile(decodeArray);
	file.readFile(encodeArray);

	encode(outCharData, encodeArray);

	newLine();
	printArray(outCharData);
}
