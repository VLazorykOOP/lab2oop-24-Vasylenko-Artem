#include <iostream>

#include "tasks.h"
#include "array.h"

// Знайти мінімальне значення серед елементів, менших заданого числа max, і розташованих до першого елемента, більшого заданого числа min.

// [3, 8, 2, 10, 5, 7, 1, 6]
//   	  ^
// min = 8, max = 4

using namespace std;

void task_02()
{
	int min, max;
	int size = InputSizeArray();
	vector<int> array = inputElementsOfArray(size);

	cout << "Enter the value of min: ";
	cin >> min;
	cout << "Enter the value of max: ";
	cin >> max;

	int minElement = array[0];
	bool isFindElement = false;

	for (int i = 0; i < size; i++)
	{
		if (array[i] > min)
			break;
		if (array[i] < max && array[i] <= minElement)
		{
			isFindElement = true;
			minElement = array[i];
		}
	}

	if (isFindElement)
		cout << "Minimum element: " << minElement << endl;
	else
		cout << "No elements in the array that meet the conditions." << endl;
}