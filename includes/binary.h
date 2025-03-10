#pragma once

#include <iostream>
#include <cmath>

using namespace std;

namespace binary
{
	int addition(int num1, int num2);
	int subtraction(int num1, int num2);
	int multyply(int num1, int num2);
	int division(int num1, int num2);
}

int binary::addition(int num1, int num2)
{
	return num1 + num2;
}

int binary::subtraction(int num1, int num2)
{
	return num1 - num2;
}

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

int binary::division(int num1, int num2)
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

	num1 = abs(num1);
	num2 = abs(num2);

	while (num1 >= num2)
	{
		num1 = subtraction(num1, num2);
		result = addition(result, 1);
	}

	if (isNegative)
		result = -result;

	return result;
}