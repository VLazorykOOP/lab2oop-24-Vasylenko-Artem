#include "fileManager.h"
#include <iostream>
#include <fstream>

using namespace std;

FileManager::FileManager(const string &path) : filePath(path) { openFile(); }

void FileManager::createFile() { outFile.open(filePath, ios::out | ios::binary); }
void FileManager::deleteFile() { remove(filePath.c_str()); }

void FileManager::openFile()
{
	if (!inFile)
		createFile();
	inFile.open(filePath, ios::binary);
}

void FileManager::closeFile()
{
	if (outFile.is_open())
		outFile.close();

	if (inFile.is_open())
		inFile.close();
}