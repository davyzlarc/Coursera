//Напишите функцию, которая:
//называется IsPalindrom
//возвращает bool
//принимает параметр типа string и возвращает, является ли переданная строка палиндромом
//
//Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево.Пустая строка является палиндромом.
//
//Аргумент функции	Результат
//madam				true
//gentleman			false
//X					true

#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string a)
{
	if (a.length() == 0 || a.length() == 1)
		return true;
	else
		for (int i = 0; i <= a.length() / 2 - 1; i++)
			if (a[i] != a[a.length() - 1 - i]) return false;
	return true;
}
int main()
{
	string a;
	getline(std::cin, a);
	cout << boolalpha;
	cout << IsPalindrom(a) << endl;
	return 0;
}