#pragma once

#include <iostream>
#include <fstream>

#include "encryption.h"

using namespace std;

class FileManager
{
public:
	string filename;
	FileManager(string filename) : filename(filename)
	{
		createFile();
	}

	void createFile();
	void checkFile();
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
