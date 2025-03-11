#pragma once
#include <string>
#include <fstream>

using namespace std;

class FileManager
{
private:
	string filePath;

public:
	ifstream inFile;
	ofstream outFile;

	FileManager(const string &path);

	void createFile();
	void deleteFile();
	void openFile();
	void closeFile();
};