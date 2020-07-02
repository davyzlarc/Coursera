//Дано два целых числа A и B в диапазоне от 0 до 1 000 000 включительно.Напишите программу, которая вычисляет целую часть частного от деления A на B.
//Если B = 0, выведите "Impossible".
//
//stdin	stdout
//10 2	5
//3 5	0
//11 0	Impossible

#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0;
	cin >> a >> b;

	if (b != 0)
		cout << a / b;
	else
		cout << "Impossible";

	return 0;
}