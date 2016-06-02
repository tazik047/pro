#include<fstream>

struct Price
{
	char name[15];
	char shopName[15];
	float cost;
};

// заполняет массив цен
void FillPrice(Price* prices, int length, std::ifstream &in);

// сортирует цены по названию товара
void SortPrices(Price* prices, int length);

// выводим на экран информацию о товаре
void PrintPrice(Price* prices, int length, char* searchName, std::ostream &out);

// return 1 if string2 < string1
// return 0 if string2 = string1
// return -1 if string2 > string1
int CompareStrings(char* string1, char* string2);

void PrepareString(char* str, std::ostream &out);

void PrepareInt(int number, std::ostream &out);