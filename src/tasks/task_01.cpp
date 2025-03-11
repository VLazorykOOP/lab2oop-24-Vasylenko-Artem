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

	int result = addition(divide(multyply(127, a), multyply(32, c)), 4096);
	cout << "Result: " << result << endl;
	cout << "Result: " << (127 * a + 32 * c) / 4096 << endl;
	result = subtraction(result, multyply(d, 1200));
	result = addition(result, multyply(b, 131));

	newLine();

	cout << "Result: " << result << endl;

	result = (127 * a + 32 * c) / 4096 - d * 1200 + b * 131;

	cout << "Result: " << result << endl;
}

// void toBinary(int num)
// {
// 	if (num == 0)
// 	{
// 		std::cout << 0;
// 		return;
// 	}
// 	std::string binary = "";
// 	while (num > 0)
// 	{
// 		binary = std::to_string(num % 2) + binary; // Добавляем остаток в начало строки
// 		num /= 2;
// 	}

// 	std::cout << binary;
// }