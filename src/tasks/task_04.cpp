#include <iostream>

#include "console.h"
#include "taskManager.h"
#include "encryption.h"
#include "bitset"

// Закодувати вхідну послідовність байтів a[i], i = 0, ..., n - 1 за правилом: a[i] = a[i] (+) (255 - (i mod 256)), i = 0, ..., n - 1.

using namespace std;

void task_04()
{
	unsigned int size;
	cout << "Enter size of array: ";
	cin >> size;
	unsigned char a[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << " element: ";
		cin >> a[i];
	}

	for (int i = 0; i < size; i++)
	{
		a[i] = a[i] ^ (255 - (i % 256));
		cout << i + 1 << " " << charToBinary(a[i], 8) << " \n";
		cout << i + 1 << " " << charToBinary(a[i], sizeof(a[i]) * 8) << " \n";

		cout << endl;
	}
}