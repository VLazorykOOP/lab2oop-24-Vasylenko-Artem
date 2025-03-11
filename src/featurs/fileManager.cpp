#include "fileManager.h"
#include <iostream>
#include <fstream>

using namespace std;

FileManager::FileManager(const string &path) : filePath(path) {}

void FileManager::createFile()
{
	ofstream file(filePath);
	if (file.is_open())
	{
		cout << "File created: " << filePath << endl;
		file.close();
	}
	else
	{
		cerr << "Failed to create file: " << filePath << endl;
	}
}

void FileManager::deleteFile()
{
	if (remove(filePath.c_str()) == 0)
		cout << "File deleted: " << filePath << endl;
	else
		cerr << "Failed to delete file: " << filePath << endl;
}

bool FileManager::checkFile()
{
	ifstream file(filePath);
	return file.good();
}

void FileManager::openFile()
{
	ifstream file(filePath);
	if (file.is_open())
	{
		cout << "File opened: " << filePath << endl;
		file.close();
	}
	else
	{
		cerr << "Failed to open file: " << filePath << endl;
	}
}

void FileManager::writeFile(string &content)
{
	ofstream file(filePath);
	if (file.is_open())
	{
		file << content;
		cout << "File written: " << filePath << endl;
		file.close();
	}
	else
	{
		cerr << "Failed to write to file: " << filePath << endl;
	}
}

void FileManager::readFile()
{
	ifstream file(filePath);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
			cout << line << endl;
		file.close();
	}
	else
	{
		cerr << "Failed to read file: " << filePath << endl;
	}
}
