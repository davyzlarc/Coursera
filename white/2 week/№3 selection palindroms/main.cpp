//Напишите функцию, которая:
//называется PalindromFilter
//возвращает vector<string>
//принимает vector<string> words и int minLength и возвращает все строки из вектора words, которые являются палиндромами и имеют длину не меньше minLength
//
//Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.
//
//words				minLength	результат
//abacaba, aba		5			abacaba
//abacaba, aba		2			abacaba, aba
//weew, bro, code	4			weew
//
//На проверку пришлите файл с реализацией функции PalindromFilter.Ваш файл может содержать и другие функции, если они вам необходимы.
//В этой задаче ваша программа не обязана что - то считывать из stdin и записывать в stdout — тестирующая система будет вызывать вашу функцию PalindromFilter напрямую

#include <iostream>
#include <string>
#include <vector>
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

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> a;
	for (auto i : words)
		if (i.length() >= minLength)
			if (IsPalindrom(i)) a.push_back(i);
	return a;
}

int main()
{
	return 0;
}