#include <iostream>
#include <fstream>

#include "encryption.h"
#include "console.h"

using namespace std;

void showMenu()
{
	cout << "File manager" << endl;
	cout << "1. Create file" << endl;
	cout << "3. Delete file" << endl;
	cout << "4. Open file" << endl;
	cout << "5. Close file" << endl;
	cout << "6. Write to file" << endl;
	cout << "7. Read from file" << endl;
	cout << "8. Append to file" << endl;
	cout << "9. Clear file" << endl;
	cout << "10. Read file" << endl;
	cout << "11. Write file" << endl;
}

class FileManager
{
private:
	string filename;

public:
	FileManager(string filename) : filename(filename) {}

	void menu();

	void createFile();
	void checkFile(string option);
	void deleteFile();
	void openFile();
	void closeFile();
	void writeToFile(string data);
	string readFromFile();
	void appendToFile(string data);
	void clearFile();
	void readFile(unsigned short arr[ROWS * COLS]);
	void writeFile(unsigned short arr[ROWS * COLS]);
};

void showMenu()
{
	cout << "File manager" << endl;
	cout << "1. Create file" << endl;
	cout << "3. Delete file" << endl;
	cout << "4. Open file" << endl;
	cout << "5. Close file" << endl;
	cout << "6. Write to file" << endl;
	cout << "7. Read from file" << endl;
	cout << "8. Append to file" << endl;
	cout << "9. Clear file" << endl;
	cout << "10. Read file" << endl;
	cout << "11. Write file" << endl;
}

void FileManager::menu()
{
	clearConsole();
	char ch;
	vector<char> validChoices = {'1', '2', '3', '4', 'q'};

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
		cout << "Task" << ch << " selected\n";
		newLine();

		switch (ch)
		{
		case '1':
			// task_01();
			break;
		case '2':
			// task_02();
			break;
		case '3':
			// task_03();
			break;
		case '4':
			// task_04();
			break;
		case 'q':
			cout << "Goodbye!\n\n";
			return;
		}

		pauseConsole();
	}
}

void FileManager::createFile()
{
	ofstream file(filename, ios::out | ios::binary);
	file.close();
}

void FileManager::checkFile(string option)
{
	if (option == "ifstream")
	{
		ifstream file(filename, ios::out | ios::binary);

		if (!file.is_open())
		{
			createFile();
			cout << "File created" << endl;
		}
		file.close();
	}
	else if (option == "ofstream")
	{
		ofstream file(filename, ios::out | ios::binary);

		if (!file.is_open())
		{
			createFile();
			cout << "File created" << endl;
		}
		file.close();
	}
	else if (option == "fstream")
	{
		fstream file(filename, ios::out | ios::binary);

		if (!file.is_open())
		{
			createFile();
			cout << "File created" << endl;
		}
		file.close();
	}
}

void FileManager::deleteFile()
{
	remove(filename.c_str());
}

void FileManager::openFile()
{
	ifstream file(filename, ios::out | ios::binary);
	file.close();
}

void FileManager::closeFile()
{
	ifstream file(filename, ios::out | ios::binary);
	file.close();
}

void FileManager::writeToFile(string data)
{
	ofstream file(filename, ios::out | ios::binary);
	file << data;
	file.close();
}

string FileManager::readFromFile()
{
	ifstream file(filename, ios::out | ios::binary);
	string data;
	file >> data;
	file.close();
	return data;
}

void FileManager::appendToFile(string data)
{
	ofstream file(filename, ios::out | ios::binary);
	file << data;
	file.close();
}

void FileManager::clearFile()
{
	ofstream file(filename, ios::out | ios::binary);
	file.close();
}

void FileManager::readFile(unsigned short arr[ROWS * COLS])
{
	ifstream file(filename, ios::out | ios::binary);
	file.read((char *)arr, sizeof(unsigned short) * 64);
	file.close();
}

void FileManager::writeFile(unsigned short arr[ROWS * COLS])
{
	ofstream file(filename, ios::out | ios::binary);
	file.write((char *)arr, sizeof(unsigned short) * 64);
	file.close();
}