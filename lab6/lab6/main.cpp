#include <iostream>
#include <cmath>

double f1(double x)
{
	return 6 * x*x + tan(x);
}

// �������� ������� x �� ������
double f2(double &x)
{
	return 6 * x*x + tan(x);
}

// �������� ������ �� �� ���������� �
// *� - ��������� ��������, ������� ��������� �� ���������� ������ ������
double f3(double *x)
{
	return 6 * (*x) * (*x) + tan(*x);
}

int main()
{
	double x1 = 2.6, x2 = 8.7, x3 = 0.1;
	double y;

	y = f1(x1)*f1(x2)*f1(x3) / (f1(x1) + f1(x2) + f1(x3));
	std::cout << "y1 = " << y << std::endl;

	y = f2(x1)*f2(x2)*f2(x3) / (f2(x1) + f2(x2) + f2(x3));
	std::cout << "y2 = " << y << std::endl;

	// &x - ��������� ������ ������ ����������
	y = f3(&x1)*f3(&x2)*f3(&x3) / (f3(&x1) + f3(&x2) + f3(&x3));
	std::cout << "y3 = " << y << std::endl;

	system("pause");
}