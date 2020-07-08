//В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S.
//Между собой число и строки разделены пробелом.
//
//Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв, и выведите их в
//стандартный поток вывода.
//
//Ограничения:
//0 <= N <= 1000
//1 <= |S| <= 15
//Каждая строка S[i] может состоять из следующих символов : [0 - 9, a - z, A - Z]
//
//Примеры:
//stdin		stdout
//2 q A		A q
//3 a C b	a b C
//
//Подсказка:
//Обратите внимание на функцию tolower.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<string>VECTOR(N);
	for (auto& item : VECTOR)
		cin >> item;

	sort(VECTOR.begin(), VECTOR.end(), [VECTOR](string a, string b) {
		for (auto& ch : a)
			ch = tolower(ch);
		for (auto& ch : b)
			ch = tolower(ch);
		return (a < b);
		});

	for (const auto& item : VECTOR)
		cout << item << " ";

	return 0;
}