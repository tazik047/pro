struct Price
{
	char name[255];
	char shopName[255];
	float cost;
};

// заполняет массив цен
void FillPrice(Price* prices, int length);

// сортирует цены по названию товара
void SortPrices(Price* prices, int length);

// выводим на экран информацию о товаре
void PrintPrice(Price* prices, int length, char* searchName);

// return 1 if string2 < string1
// return 0 if string2 = string1
// return -1 if string2 > string1
int CompareStrings(char* string1, char* string2);