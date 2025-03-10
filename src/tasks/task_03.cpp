#include <iostream>

#include "tasks.h"
#include "array.h"

// Задано дійсні число г і масив А(п), n <= 200
// Розробити програму, яка підраховує скільки точок з координатами(а₁, а₂), (аз, , а₄), ..., (а2 - 1а2м) належать кругові радіуса - з центром на початку координат.

using namespace std;

bool belongsPointCircle(int x_point, int y_point, int x1, int y1, int r1)
{
	float x = pow((x1 - x_point), 2);
	float y = pow((y1 - y_point), 2);
	float r = pow(r1, 2);
	return (x + y) <= r;
}

void task_03()
{
	int count = 0;
	int radius;
	int size = InputSizeArray();
	vector<vector<int>> array;

	for (int i = 0; i < size; i++)
		array.push_back(inputElementsOfArray(2));

	cout << "Enter the radius of the circle: ";
	cin >> radius;

	for (int i = 0; i < size; i++)
	{
		int x = array[i][0];
		int y = array[i][1];
		if (belongsPointCircle(x, y, 0, 0, radius))
		{
			count++;
			cout << "Point " << i + 1 << ": (" << x << ", " << y << ") belongs to the circle." << endl;
		}
		else
		{
			cout << "Point " << i + 1 << ": (" << x << ", " << y << ") does not belong to the circle." << endl;
		}
	}

	cout << "\nNumber of points that belong to the circle: " << count << endl;
}