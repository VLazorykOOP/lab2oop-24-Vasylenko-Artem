#include <iostream>

#include "console.h"
#include "taskManager.h"
#include "binaryOperation.h"

// Задано цілі числа a, b, c та d. Обчислити вираз без використання операцій множення та ділення(замінивши на їх операцій зсувів).

// (127 * a + 32 * c)/4096 - d * 1200 + b * 131

using namespace std;
using namespace binary;

void task_01()
{
	int a, b, c, d;

	cout << "Enter values for a, b, c, d: ";
	cin >> a >> b >> c >> d;

	newLine();
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	pauseConsole();

	newLine();
	cout << "(127 * a + 32 * c)/4096 - d * 1200 + b * 131" << endl;
	cout << "(127 * " << a << " + 32 * " << c << ")/4096 - " << d << " * 1200 + " << b << " * 131" << endl;
	pauseConsole();

	newLine();
	cout << "1." << endl;
	newLine();
	cout << "Binary: " << endl;
	cout << segmentation(addition(multiply(127, a), multiply(32, c)), 4096) - multiply(d, 1200) + multiply(b, 131) << endl;
	newLine();
	cout << "Decimal: " << endl;
	cout << (127 * a + 32 * c) / 4096 - d * 1200 + b * 131 << endl;
	pauseConsole();
}