#pragma once

#include <iostream>

namespace binary
{
	int addition(int num1, int num2) { return num1 + num2; };
	int subtraction(int num1, int num2) { return num1 - num2; };
	int multyply(int num1, int num2);
	int divide(int num1, int num2);
}

using namespace std;

int binary::multyply(int num1, int num2)
{
	if (num1 == 0 || num2 == 0)
		return 0;

	int result = 0;
	bool isNegative = ((num1 < 0) ^ (num2 < 0));

	num1 = abs(num1);
	num2 = abs(num2);

	while (num2 != 0)
	{
		if (num2 & 1)
			result = addition(result, num1);

		num1 <<= 1;
		num2 >>= 1;
	}

	if (isNegative)
		result = -result;

	return result;
}

int binary::divide(int num1, int num2)
{
	if (num1 == 0)
		return 0;

	if (num2 == 0)
	{
		cout << "Division by zero is not allowed." << endl;
		return 0;
	}

	int result = 0;
	bool isNegative = ((num1 < 0) ^ (num2 < 0));

	int abs_num1 = abs(num1);
	int abs_num2 = abs(num2);

	while (abs_num1 >= abs_num2)
	{
		int temp = abs_num2;
		int mult = 1;

		while ((temp << 1) <= abs_num1)
		{
			temp <<= 1;
			mult <<= 1;
		}

		abs_num1 -= temp;
		result += mult;
	}

	if (isNegative)
		result = -result;

	return result;
}