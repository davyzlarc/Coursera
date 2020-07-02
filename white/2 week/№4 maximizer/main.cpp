//Напишите функцию UpdateIfGreater, которая принимает два целочисленных аргумента : first и second.
//Если first оказался больше second, Ваша функция должна записывать в second значение параметра first.
//При этом указанная функция не должна ничего возвращать, а изменение параметра second должно быть видно на вызывающей стороне.
//
//Пример
//int a = 4;
//int b = 2;
//UpdateIfGreater(a, b); /*(b должно стать равно 4)*/

#include <iostream>
using namespace std;

void UpdateIfGreater(int first, int& second)
{
	if (first > second)
		second = first;
}

int main()
{
	return 0;	
}