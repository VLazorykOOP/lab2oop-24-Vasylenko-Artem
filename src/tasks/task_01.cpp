#include <iostream>

#include "console.h"
#include "tasks.h"
#include "binary.h"

// Задано цілі числа a, b, c та d. Обчислити вираз без використання операцій множення та ділення(замінивши на їх операцій зсувів).

// (127*a + 32*c)/4096 - d * 1200 + b * 131

using namespace std;
using namespace binary;

void task_01()
{
	int a, b, c, d;

	cout << "Enter values for a, b, c, d: ";
	cin >> a >> b >> c >> d;

	cout << segmentation(addition(multiply(127, a), multiply(32, c)), 4096) - multiply(d, 1200) + multiply(b, 131) << endl;
	cout << (127 * a + 32 * c) / 4096 - d * 1200 + b * 131 << endl;

	// int result = addition(segmentation(multiply(127, a), multiply(32, c)), 4096);
	// cout << "Result: " << result << endl;
	// cout << "Result: " << (127 * a + 32 * c) / 4096 << endl;
	// result = subtraction(result, multiply(d, 1200));
	// result = addition(result, multiply(b, 131));

	// newLine();

	// cout << "Result: " << result << endl;

	// result = (127 * a + 32 * c) / 4096 - d * 1200 + b * 131;

	// cout << "Result: " << result << endl;
}