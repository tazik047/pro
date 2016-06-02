#include <iostream>
#ifndef function
#define function
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define getMaxIndex(mas, length, index) { index = 0; for(int i =0; i<length; i++) { if(mas[i]>mas[index]) index = i; } }
#define getMinIndex(mas, length, index) { index = 0; for(int i =0; i<length; i++) { if(mas[i]<mas[index]) index = i; } }
#define input(length, mas) { for(int i = 0; i< length; i++) std::cin>>mas[i];}
#define print(mas, length)  { for (int i=0;i<length;i++) std::cout<<mas[i]<<" "; } 
#define setNumber(mas, start, end, number){ for(int i = start + 1; i < end; i++) mas[i] = number;}
#endif