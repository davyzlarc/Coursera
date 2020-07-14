//Слова называются анаграммами друг друга, если одно из них можно получить перестановкой букв в другом.Например, слово «eat» можно получить перестановкой 
//букв слова «tea», поэтому эти слова являются анаграммами друг друга.Даны пары слов, проверьте для каждой из них, являются ли слова этой пары анаграммами друг друга.
//
//Указание:
//Один из способов проверки того, являются ли слова анаграммами друг друга, заключается в следующем.Для каждого слова с помощью словаря подсчитаем,
//сколько раз в нём встречается каждая буква.Если для обоих слов эти словари равны(а это проверяется с помощью обычного оператора == ), то слова являются
//анаграммами друг друга, в противном случае не являются.
//При этом построение такого словаря по слову удобно вынести в отдельную функцию BuildCharCounters.
//
//Формат ввода
//Сначала дано число пар слов N, затем в N строках содержатся пары слов, которые необходимо проверить.Гарантируется, что все слова состоят лишь из строчных латинских букв.
//
//Формат вывода
//Выведите N строк : для каждой введённой пары слов YES, если эти слова являются анаграммами, и NO в противном случае.
//
//Пример:
//Ввод
//3
//eat tea
//find search
//master stream
//Вывод
//YES
//NO
//YES


#include <iostream>
#include<vector>
#include<map>
using namespace std;

bool check(const string& first, const string& second)
{
	map<char, int>a, b;
	size_t i_max = second.size() - 1, i_min = first.size() - 1;
	if (first.size() > second.size())
	{
		i_max = first.size() - 1;
		i_min = second.size() - 1;
	}

	for (auto i = 0; i <= i_max; i++)
	{
		if (i <= i_min)
			a[first[i]]++;
		if (i <= i_max)
			b[second[i]]++;
	}

	if (a == b)
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;
	vector<string>result(0);

	for (auto i = 1; i <= n; i++)
	{
		string first, second;
		cin >> first;
		cin >> second;

		if (check(first, second))
			result.push_back("YES");
		else
			result.push_back("NO");
	}

	for (const auto& item : result)
		cout << item << endl;
	return 0;
}