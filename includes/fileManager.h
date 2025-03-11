#pragma once
#include <string>

using namespace std;

class FileManager
{
private:
	string filePath;

public:
	FileManager(const string &path);

	void createFile();
	void deleteFile();
	bool checkFile();
	void openFile();
	void writeFile(std::string &content);
	void readFile();
};