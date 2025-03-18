#include <iostream>
#include <fstream>

#include "encryption.h"
#include "console.h"

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

void FileManager::createFile()
{
	ifstream check(filename, ios::out | ios::binary);

	if (check.is_open())
	{
		cout << "File already exists" << endl;
		check.close();
		return;
	}

	ofstream file(filename, ios::out | ios::binary);
	file.close();
}

void FileManager::checkFile()
{

	ifstream file(filename, ios::out | ios::binary);

	if (!file.is_open())
	{
		createFile();
		cout << "File created" << endl;
	}

	file.close();
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