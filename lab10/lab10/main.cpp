#include <iostream>
#include "functions.h"

int main()
{
	const int length = 10;
	int mas[length];

	input(length, mas);

	int maxIndex, minIndex;

	getMaxIndex(mas, length, maxIndex);
	getMinIndex(mas, length, minIndex);

	setNumber(mas, min(maxIndex, minIndex), max(maxIndex, minIndex), NULL);

	print(mas, length);

	system("pause");

	return 0;
}