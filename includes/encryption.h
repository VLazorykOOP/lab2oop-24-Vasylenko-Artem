#pragma once

#include <iostream>
#include <string>

const int ROWS = 8, COLS = 8;

void readInputFile(unsigned char charData[ROWS][COLS], std::string filename);
void printArray(unsigned char charData[ROWS][COLS]);
int calcParity(int value, int bitCount);
std::string charToBinary(unsigned int ch, int bitCount);
void decode(unsigned short binData[ROWS * COLS], unsigned char charData[ROWS][COLS]);
void encode(unsigned char charData[ROWS][COLS], unsigned short binData[ROWS * COLS]);
