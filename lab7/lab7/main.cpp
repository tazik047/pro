#include <iostream>
#include <locale>
#include "price.h"

int main()
{
	setlocale(LC_ALL, "rus");
	const int priceLength = 8;
	Price prices[priceLength];
	int command = -1;
	while (command != 0)
	{
		std::cout << "1. Ввести все товары." << std::endl;
		std::cout << "2. Найти товар." << std::endl;
		std::cout << "0. Выйти." << std::endl;
		std::cin >> command;

		switch (command)
		{
		case 1:
			FillPrice(prices, priceLength);
			SortPrices(prices, priceLength);
			break;
		case 2:
			char searchName[255];
			std::cout << "Введите название товара, который вы ищете: ";
			std::cin >> searchName;
			PrintPrice(prices, priceLength, searchName);
			break;
		}
	}
}

// заполняет массив цен
void FillPrice(Price* prices, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "Заполнение товара №" << (i + 1) << std::endl;
		std::cout << "Введите название товара: ";
		std::cin >> prices[i].name;
		std::cout << "Введите название магазина: ";
		std::cin >> prices[i].shopName;
		std::cout << "Введите цену товара: ";
		std::cin >> prices[i].cost;
	}

	std::cout << std::endl;
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

// выводим на экран все цены
void PrintPrice(Price* prices, int length, char* searchName)
{
	for (int i = 0; i < length; i++)
	{
		if (CompareStrings(prices[i].name, searchName) == 0){
			std::cout << "Название товара: " << prices[i].name
				<< ". Название магазина: " << prices[i].shopName
				<< ". Цена товара: " << prices[i].cost << std::endl;
			return;
		}
	}

	std::cout << "Такой товар не найден" << std::endl << std::endl;
}

// return 1 if string2 < string1
// return 0 if string2 = string1
// return -1 if string2 > string1
int CompareStrings(char* string1, char* string2)
{
	return strcmp(string1, string2);
}