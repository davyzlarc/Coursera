//Дан набор строк.Найдите количество уникальных строк в этом наборе.
//
//Формат ввода
//Сначала вводится количество строк N, затем — сами N строк, разделённые символом перевода строки.
//Все строки состоят лишь из латинских букв, цифр и символов подчёркивания.
//
//Формат вывода
//Выведите единственное целое число — количество уникальных строк в данном наборе.
//
//Пример:
//Ввод
//6
//first
//second
//first
//third
//second
//second
//
//Вывод
//3

#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
	set<string> strings;
	int n;
	cin >> n;

	string s;
	getline(std::cin, s);
	for (auto i = 0; i < n; i++)
	{
		getline(std::cin,s);
		strings.insert(s);
	}

	cout << strings.size();
	return 0;
}