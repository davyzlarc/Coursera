//В этой задаче вам нужно присваивать номера автобусным маршрутам:
//А именно, для каждого маршрута, заданного набором названий остановок, нужно 
//либо выдать новый номер(первому маршруту — 1, второму — 2 и т.д.), 
//либо вернуть номер существующего маршрута, которому соответствует такой набор остановок.
//Наборы остановок, полученные друг из друга перестановкой остановок, считаются различными(см.пример).
//
//Указание
//В C++ ключом словаря может быть не только число или строка, но и другой контейнер, например, vector.
//
//Формат ввода
//Сначала вводится количество запросов Q, затем Q описаний запросов.
//
//Каждый запрос представляет собой положительное количество остановок N, за которым следуют разделённые пробелом N
//различных названий остановок соответствующего маршрута.Названия остановок состоят лишь из латинских букв и символов
//подчёркивания.
//
//Формат вывода
//Выведите ответ на каждый запрос в отдельной строке.
//
//Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите
//Already exists for i, где i — номер маршрута с таким набором остановок.В противном случае нужно выделить
//введённому набору остановок новый номер i и вывести его в формате New bus i.
//
//Пример:
//Ввод
//4
//2 Marushkino Kokoshkino
//1 Kokoshkino
//2 Marushkino Kokoshkino
//2 Kokoshkino Marushkino
//
//Вывод
//New bus 1
//New bus 2
//Already exists for 1
//New bus 3
//
//Замечание:
//Будьте внимательны при обновлении словаря : если одновременно в одном выражении вычислять размер словаря 
//и добавлять в него новый элемент, результат может отличаться от ожидаемого на единицу.Чтобы этого избежать, 
//используйте временную переменную.
//
//Например, вместо кода:
//	map<string, int> m;
//	// ...
//	m["two"] = m.size();
//	// что нужно сделать раньше: вычислить size или добавить новый ключ?
//
//стоит написать такой код:
//	map<string, int> m;
//	// ...
//	int new_value = m.size();
//	m["two"] = new_value;
//	// теперь всё однозначно: нужен размер до добавления элемента

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main()
{
	map<vector <string>, int>GUIDE;
	int num_guides = 1;

	int n;
	cin >> n;
	vector<string>result(0);

	for (auto i = 1; i <= n; i++)
	{
		int num_stops;
		cin >> num_stops;
		vector<string> tmp_stops(num_stops);
		for (auto& item : tmp_stops)
			cin >> item;

		if (GUIDE.count(tmp_stops) == 0)
		{
			GUIDE[tmp_stops] = num_guides;
			result.push_back("New bus " + to_string(GUIDE.at(tmp_stops)));
			num_guides++;
		}
		else result.push_back("Already exists for " + to_string(GUIDE.at(tmp_stops)));
	}

	for (const auto& item : result)
		cout << item << endl;

	return 0;
}