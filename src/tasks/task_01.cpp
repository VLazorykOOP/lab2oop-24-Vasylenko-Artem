#include <iostream>

#include "console.h"
#include "tasks.h"
#include "array.h"

// Задано одновимірний масив А розміру N.Знайти серед всіх від’ємних максимальний елемент масиву та його індекс.

using namespace std;

void task_01()
{
	int size = InputSizeArray();
	vector<int> array = inputElementsOfArray(size);
	vector<int> indexes = {};

	int maxNegative = findMaxNegativeElement(array);

	if (maxNegative == 0)
	{
		cout << "No negative elements in the array." << endl;
		return;
	}

	for (int i = 0; i < array.size(); i++)
		if (array[i] == maxNegative)
			indexes.push_back(i);

	int indexesSize = indexes.size();

	if (indexesSize == 1)
	{
		cout << "Maximum negative element: " << maxNegative << " at index " << indexes[0] << endl;
		return;
	}

	if (indexesSize > 1)
	{
		cout << "Maximum negative element: " << maxNegative << " at index [ ";
		for (int i = 0; i < indexesSize; i++)
			cout << indexes[i] << (indexesSize - 1 == i ? " " : ", ");
		cout << "]\n";
	}
}