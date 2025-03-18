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

void showMenu()
{
	cout << "File manager" << endl;
	cout << "0. Open file" << endl;
	cout << "1. Create file" << endl;
	cout << "2. Delete file" << endl;
	cout << "3. Write to file" << endl;
	cout << "4. Read from file" << endl;
	cout << "5. Append to file" << endl;
	cout << "6. Clear file" << endl;
	cout << "q. Quit" << endl;
}

string path = "./public/binary/";
string filename;
string filepath;

string getFilename()
{
	string filename;
	cout << "Enter file name: ";
	cin >> filename;
	return filename;
}

void creatFile()
{
	filename = getFilename();

	filepath = path + filename + ".txt";
	filepath = path + filename + ".txt";
	FileManager fileTxt(filepath);

	fileTxt.checkFile();

	filepath = path + filename + ".dat";
	FileManager fileBin(filepath);
	fileBin.checkFile();
}

void deleteFile()
{
	FileManager file(filepath);
	file.deleteFile();
}

void task_02()
{
	string filepath = "public/binary/";
	string filename;

	clearConsole();
	char ch;

	vector<char> validChoices = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'q'};

	while (true)
	{
		showMenu();
		cin >> ch;
		bool selected = checkChoiceInput(ch, validChoices);

		if (!selected)
		{
			clearConsole();
			cout << "Invalid choice. Please try again.\n";
			pauseConsole();
			continue;
		}

		clearConsole();
		newLine();

		switch (ch)
		{
		case '1':
			creatFile();
			break;
		case '2':
			deleteFile();
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;

		default:
			break;
		}

		if (ch == 'q')
			break;
	}

	// cout << "Enter file name: ";
	// cin >> filename;

	// filepath += filename;

	// FileManager inputFile(filepath + ".txt");
	// FileManager outputFile(filepath + ".dat");

	// inputFile.checkFile();
	// outputFile.checkFile();

	// unsigned char array[ROWS][COLS];
	// unsigned short decodeArray[ROWS * COLS];
	// unsigned short encodeArray[ROWS * COLS];
	// unsigned char outCharData[ROWS][COLS];

	// readInputFile(array, inputFile.filename);
	// printArray(array);

	// newLine();

	// decode(decodeArray, array);

	// outputFile.writeFile(decodeArray);
	// outputFile.readFile(encodeArray);

	// encode(outCharData, encodeArray);

	// newLine();
	// printArray(outCharData);
}
