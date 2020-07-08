//В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел.Первым числом идёт само число N. 
//Далее следуют ещё N чисел, обозначим их за массив A.Между собой числа разделены пробелом.
//
//Отсортируйте массив А по модулю и выведите его в стандартный поток.
//
//Ограничения:
//0 <= N <= 1000
//- 1000000 <= A[i] <= 1000000
//
//Примеры:
//stdin			stdout
//2 - 4 3		3 - 4
//3 1 - 3 2		1 2 - 3
//
//Подсказка:
//функция sort дополнительно принимает третий аргумент. Изучите его подробнее по ссылке.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<int>VECTOR(N);
	for (auto& item : VECTOR)
		cin >> item;
	
	sort(VECTOR.begin(), VECTOR.end(), [](int a, int b) {return (abs(a) < abs(b));});

	for (const auto& item : VECTOR)
		cout << item << " ";

	return 0;
}