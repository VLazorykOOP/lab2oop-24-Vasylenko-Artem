#pragma once

#include <iostream>
#include <fstream>

#include "encryption.h"

using namespace std;

namespace fileManager
{
	void menu();
	void showMenu();
	void createFile();
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