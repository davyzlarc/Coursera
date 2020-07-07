//Два слова называются синонимами друг друга, если они имеют похожие значения. Реализуйте следующие операции
//над словарём синонимов :
//ADD   -  word1 word2 — добавить в словарь пару синонимов(word1, word2).
//COUNT -  word — узнать количество синонимов слова word.
//CHECK -  word1 word2 — проверить, являются ли слова word1 и word2 синонимами. Слова word1 и word2 считаются синонимами,
//		   если среди запросов ADD был хотя бы один запрос ADD word1 word2 или ADD word2 word1.
//
//Замечание
//Для упрощения, будем считать, что синонимы не обладают транзитивностью, то есть, если A - синоним B, а B - синоним C,
//то из этого НЕ следует, что A - синоним C.
//
//Формат ввода
//Сначала вводится количество запросов Q, затем Q строк с описаниями запросов.Гарантируется, что в каждом запросе CHECK
//и ADD слова word1 и word2 различны.Все слова состоят лишь из латинских букв, цифр и символов подчёркивания.
//
//Формат вывода
//Для каждого запроса в соответствующей строке выведите ответ на него :
//В ответ на запрос COUNT word выведите единственное целое число — количество синонимов слова word.
//В ответ на запрос CHECK word1 word2 выведите строку YES, если word1 и word2 являются синонимами, и NO в противном случае.
//
//Пример:
//Ввод
//8
//ADD program code
//COUNT cipher
//ADD code cipher
//COUNT code
//COUNT program
//CHECK code program
//CHECK program cipher
//CHECK cpp java
//
//Вывод
//0
//2
//1
//YES
//NO
//NO

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

int ADD(map<string, set<string>>& SYNONYMS, const string& WORD1, const string& WORD2)
{
	SYNONYMS[WORD1].insert(WORD2);
	SYNONYMS[WORD2].insert(WORD1);
	return 0;
}

int COUNT(const map<string, set<string>>& SYNONYMS, const string& WORD)
{
	if (SYNONYMS.find(WORD) != SYNONYMS.cend())
		return int(SYNONYMS.at(WORD).size());

	return 0;
}

bool CHECK(const map<string, set<string>>& SYNONYMS, const string& WORD1, const string& WORD2)
{
	if (SYNONYMS.find(WORD1) != SYNONYMS.cend())
		if(SYNONYMS.at(WORD1).find(WORD2)!=SYNONYMS.at(WORD1).cend())
		return true;

	return false;
}

int main()
{
	map<string, int>command = { {"ADD",1},{"COUNT",2},{"CHECK",3} };
	map<string, set<string>>SYNONYMS;
	int n;
	cin >> n;
	vector<string>result(0);

	for (auto i = 1; i <= n; i++)
	{
		static string operation;
		cin >> operation;
		switch (command[operation])
		{
		case 1://ADD 
		{
			static string WORD1, WORD2;
			cin >> WORD1 >> WORD2;
			ADD(SYNONYMS, WORD1, WORD2);
		}
		break;
		case 2://COUNT 
		{
			static string WORD;
			cin >> WORD;
			result.push_back(to_string(COUNT(SYNONYMS, WORD)));
		}
		break;
		case 3://CHECK
		{
			static string WORD1, WORD2;
			cin >> WORD1 >> WORD2;
			if (CHECK(SYNONYMS, WORD1, WORD2))
				result.push_back("YES");
			else
				result.push_back("NO");
		}
		break;
		}
	}

	for (const auto& item : result)
		cout << item << endl;

	return 0;
}