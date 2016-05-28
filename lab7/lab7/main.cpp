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
		std::cout << "1. ������ ��� ������." << std::endl;
		std::cout << "2. ����� �����." << std::endl;
		std::cout << "0. �����." << std::endl;
		std::cin >> command;

		switch (command)
		{
		case 1:
			FillPrice(prices, priceLength);
			SortPrices(prices, priceLength);
			break;
		case 2:
			char searchName[255];
			std::cout << "������� �������� ������, ������� �� �����: ";
			std::cin >> searchName;
			PrintPrice(prices, priceLength, searchName);
			break;
		}
	}
}

// ��������� ������ ���
void FillPrice(Price* prices, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "���������� ������ �" << (i + 1) << std::endl;
		std::cout << "������� �������� ������: ";
		std::cin >> prices[i].name;
		std::cout << "������� �������� ��������: ";
		std::cin >> prices[i].shopName;
		std::cout << "������� ���� ������: ";
		std::cin >> prices[i].cost;
	}

	std::cout << std::endl;
}

// ��������� ���� �� �������� ������
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

// ������� �� ����� ��� ����
void PrintPrice(Price* prices, int length, char* searchName)
{
	for (int i = 0; i < length; i++)
	{
		if (CompareStrings(prices[i].name, searchName) == 0){
			std::cout << "�������� ������: " << prices[i].name
				<< ". �������� ��������: " << prices[i].shopName
				<< ". ���� ������: " << prices[i].cost << std::endl;
			return;
		}
	}

	std::cout << "����� ����� �� ������" << std::endl << std::endl;
}

// return 1 if string2 < string1
// return 0 if string2 = string1
// return -1 if string2 > string1
int CompareStrings(char* string1, char* string2)
{
	return strcmp(string1, string2);
}