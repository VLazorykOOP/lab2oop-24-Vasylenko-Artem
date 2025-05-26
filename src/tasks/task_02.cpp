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
	string filepath = "public/binary/output";

	FileManager inputFile(filepath + ".txt");

	cout << "1 - Input data from console" << endl;
	cout << "2 - Clear file" << endl;
	cout << "3 - Input data from file" << endl;

	cout << "\nYour choice: ";

	int choice;
	cin >> choice;

	newLine();
	if (choice == 1)
	{
		cout << "Input data what you want to encrypt: ";
		string data;
		cin >> data;
		inputFile.writeToFile(data);
	}
	else if (choice == 2)
	{
		inputFile.clearFile();
	}

	clearConsole();

	FileManager outputFile(filepath + ".dat");

	unsigned char array[ROWS][COLS];
	unsigned short decodeArray[ROWS * COLS];
	unsigned short encodeArray[ROWS * COLS];
	unsigned char outCharData[ROWS][COLS];

	readInputFile(array, inputFile.filename);

	decode(decodeArray, array);

	outputFile.writeFile(decodeArray);
	outputFile.readFile(encodeArray);

	encode(outCharData, encodeArray);

	newLine();
	printArray(outCharData);
}
