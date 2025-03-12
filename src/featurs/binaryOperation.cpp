#include <iostream>
#include <cmath>
#include "binaryOperation.h"

using namespace std;

namespace binary
{
	int addition(const int &num1, const int &num2);		// const reference
	int subtraction(const int &num1, const int &num2);	// const reference
	int multiply(const int &num1, const int &num2);		// const reference
	int segmentation(const int &num1, const int &num2); // const reference
}

using namespace std;

int binary::addition(const int &num1, const int &num2) { return num1 + num2; }
int binary::subtraction(const int &num1, const int &num2) { return num1 - num2; }

int binary::multiply(const int &num1, const int &num2)
{
	if (num1 == 0 || num2 == 0)
		return 0;

	int result = 0;
	bool isNegative = ((num1 < 0) ^ (num2 < 0));

	int abs_num1 = abs(num1);
	int abs_num2 = abs(num2);

	while (abs_num2 != 0)
	{
		if (abs_num2 & 1)
			result = addition(result, abs_num1);

		abs_num1 <<= 1;
		abs_num2 >>= 1;
	}

	return !isNegative ? result : -result;
}

int binary::segmentation(const int &num1, const int &num2)
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

	return !isNegative ? result : -result;
}
