#include <iostream>
#include <locale>
#include <fstream>
#include "price.h"


int main()
{
	setlocale(LC_ALL, "rus");
	const int priceLength = 8;
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	Price prices[priceLength];
	FillPrice(prices, priceLength,in);
	SortPrices(prices, priceLength);

	char searchName[15];
	in >> searchName;

	PrintPrice(prices, priceLength, searchName, out);
	PrintPrice(prices, priceLength, searchName, std::cout);

	in.close();
	out.close();
}

// заполняет массив цен
void FillPrice(Price* prices, int length, std::ifstream &in)
{
	for (int i = 0; i < length; i++)
	{
		in >> prices[i].name;
		in >> prices[i].shopName;
		in >> prices[i].cost;
	}
}

// сортирует цены по названию товара
void SortPrices(Price* prices, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 1; j < length; j++)
		{
			if (CompareStrings(prices[j - 1].name, prices[j].name) > 0)
			{
				Price temp = prices[j - 1];
				prices[j - 1] = prices[j];
				prices[j] = temp;
			}
		}
	}
}

void PrintPrice(Price* prices, int length, char* searchName, std::ostream &out)
{
	for (int i = 0; i < length; i++)
	{
		if (CompareStrings(prices[i].name, searchName) == 0) {
			PrepareString(prices[i].name, out);
			PrepareString(prices[i].shopName, out);
			PrepareInt(prices[i].cost, out);
			return;
		}
	}
	PrepareString("Товар не найден\n", out);
}

// return 1 if string2 < string1
// return 0 if string2 = string1
// return -1 if string2 > string1
int CompareStrings(char* string1, char* string2)
{
	return strcmp(string1, string2);
}

void PrepareString(char* str, std::ostream &out) 
{
	out << str;
	for (int i = strlen(str); i <= 15; i++)
	{
		out << '.';
	}
}

void PrepareInt(int number, std::ostream &out) 
{
	char buffer[8];
	_itoa_s(number, buffer, 10);
	
	for (int i = 0; i < 8- strlen(buffer); i++)
	{
		out << '.';
	}

	out << buffer;
}