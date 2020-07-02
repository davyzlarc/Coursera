//Напишите функцию, которая:
//называется Factorial
//возвращает int
//принимает int и возвращает факториал своего аргумента.Гарантируется, что аргумент функции по модулю не превышает 10. Для отрицательных аргументов функция должна возвращать 1.
//
//Аргумент функции	Результат
//1					1
//- 2				1
//4					24

#include <iostream>
using namespace std;

int Factorial(int a)
{
	if (a <= 0)
	{
		return 1;
	}
	else
		return a * Factorial(a - 1);
}
int main() {
	int a;
	cin >> a;
	a = Factorial(a);
	cout << a;
	return 0;
}