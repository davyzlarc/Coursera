//Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом GetFullNameWithHistory:
//class Person {
//public:
//	void ChangeFirstName(int year, const string& first_name) {
//		// добавить факт изменения имени на first_name в год year
//	}
//	void ChangeLastName(int year, const string& last_name) {
//		// добавить факт изменения фамилии на last_name в год year
//	}
//	string GetFullName(int year) {
//		// получить имя и фамилию по состоянию на конец года year
//	}
//	string GetFullNameWithHistory(int year) {
//		// получить все имена и фамилии по состоянию на конец года year
//	}
//private:
//	// приватные поля
//};
//
//В отличие от метода GetFullName, метод GetFullNameWithHistory должен вернуть не только последние имя и фамилию 
//к концу данного года, но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке. Если текущие
//факты говорят о том, что человек два раза подряд изменил фамилию или имя на одно и то же, второе изменение при 
//формировании истории нужно игнорировать.
//
//Для лучшего понимания формата см.примеры.
//
//Пример 1:
//Код
//int main() {
//Person person;
//
//person.ChangeFirstName(1900, "Eugene");
//person.ChangeLastName(1900, "Sokolov");
//person.ChangeLastName(1910, "Sokolov");
//person.ChangeFirstName(1920, "Evgeny");
//person.ChangeLastName(1930, "Sokolov");
//cout << person.GetFullNameWithHistory(1940) << endl;
//
//return 0;
//}
//
//Вывод
//Evgeny (Eugene) Sokolov
//
//Пример 2:
//Код
//int main() {
//Person person;
//
//person.ChangeFirstName(1965, "Polina");
//person.ChangeLastName(1967, "Sergeeva");
//for (int year : {1900, 1965, 1990}) {
//	cout << person.GetFullNameWithHistory(year) << endl;
//}
//
//person.ChangeFirstName(1970, "Appolinaria");
//for (int year : {1969, 1970}) {
//	cout << person.GetFullNameWithHistory(year) << endl;
//}
//
//person.ChangeLastName(1968, "Volkova");
//for (int year : {1969, 1970}) {
//	cout << person.GetFullNameWithHistory(year) << endl;
//}
//
//person.ChangeFirstName(1990, "Polina");
//person.ChangeLastName(1990, "Volkova-Sergeeva");
//cout << person.GetFullNameWithHistory(1990) << endl;
//
//person.ChangeFirstName(1966, "Pauline");
//cout << person.GetFullNameWithHistory(1966) << endl;
//
//person.ChangeLastName(1960, "Sergeeva");
//for (int year : {1960, 1967}) {
//	cout << person.GetFullNameWithHistory(year) << endl;
//}
//
//person.ChangeLastName(1961, "Ivanova");
//cout << person.GetFullNameWithHistory(1967) << endl;
//
//return 0;
//}
//
//Вывод
//Incognito
//Polina with unknown last name
//Polina Sergeeva
//Polina Sergeeva
//Appolinaria(Polina) Sergeeva
//Polina Volkova(Sergeeva)
//Appolinaria(Polina) Volkova(Sergeeva)
//Polina(Appolinaria, Polina) Volkova - Sergeeva(Volkova, Sergeeva)
//Pauline(Polina) with unknown last name
//Sergeeva with unknown first name
//Pauline(Polina) Sergeeva
//Pauline(Polina) Sergeeva(Ivanova, Sergeeva)
//
//Пример 3:
//Код
//int main() {
//Person person;
//
//person.ChangeFirstName(1965, "Polina");
//person.ChangeFirstName(1965, "Appolinaria");
//
//person.ChangeLastName(1965, "Sergeeva");
//person.ChangeLastName(1965, "Volkova");
//person.ChangeLastName(1965, "Volkova-Sergeeva");
//
//for (int year : {1964, 1965, 1966}) {
//	cout << person.GetFullNameWithHistory(year) << endl;
//}
//
//return 0;
//}
//
//Вывод
//Incognito
//Appolinaria Volkova - Sergeeva
//Appolinaria Volkova - Sergeeva

//лично от меня тест 
//person.ChangeFirstName(1900, "Ivanova");
//person.ChangeLastName(1991, "Petrova");
//cout << person.GetFullNameWithHistory(1990) << endl;

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct person_struct
{
	int year;
	string first_name;
	string last_name;
};

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		add_elem(year, first_name, "");
	}

	void ChangeLastName(int year, const string& last_name) {
		add_elem(year, "", last_name);
	}

	string GetFullName(int year) {
		string first_name, last_name;
		bool first_in = true;

		if (person.size() == 0)
			return "Incognito";
		for (const auto& item : person)
		{
			if (item.year > year)
			{
				if (first_in)
					return "Incognito";
				else
					return print_names(first_name, last_name);
			}

			if (item.first_name != "")first_name = item.first_name;
			if (item.last_name != "")last_name = item.last_name;

			if (item.year == year)
				return print_names(first_name, last_name);
			first_in = false;
		}
		return print_names(first_name, last_name);
	}

	string GetFullNameWithHistory(int year) {
		string result = GetFullName(year);

		if (result == "Incognito")
			return result;

		vector<person_struct>::iterator it = person.begin();
		vector<string>first_names, last_names;
		while (it < person.end() - 1 && it->year < year)
		{
			vector<person_struct>::iterator it_last = it, it_next = it + 1;
			if (it != person.begin())
				it_last--;

			if (it->first_name != "" && (it_last->first_name != it->first_name || it_last == it) &&
				it_next->first_name != it->first_name)
				first_names.push_back(it->first_name);
			if (it->last_name != "" && (it_last->last_name != it->last_name || it_last == it) &&
				it_next->last_name != it->last_name)
				last_names.push_back(it->last_name);
			++it;
		}

		while (!first_names.empty() && result.find(first_names.back() + " ") != result.npos)
			first_names.pop_back();

		while (!last_names.empty() &&
			((result.find(" " + last_names.back()) != result.npos &&
				result.find(last_names.back()) + last_names.back().size() - 1 == result.size() - 1) ||
				result.find(last_names.back() + " ") != result.npos))
			last_names.pop_back();

		if (first_names.empty() && last_names.empty())
			return result;

		reverse(first_names.begin(), first_names.end());
		reverse(last_names.begin(), last_names.end());

		string first_string, last_string;
		for (const auto& item : first_names)
			first_string += item + ", ";
		if (first_string != "")first_string.erase(first_string.size() - 2, 2);
		for (const auto& item : last_names)
			last_string += item + ", ";
		if (last_string != "")last_string.erase(last_string.size() - 2, 2);

		size_t iter = result.find(" with unknown last name");
		if (iter != result.npos)
		{
			result.insert(iter, " (" + first_string + ")");
			return result;
		}

		iter = result.find(" with unknown first name");
		if (iter != result.npos)
		{
			result.insert(iter, " (" + last_string + ")");
			return result;
		}

		iter = result.find(" ");
		if (first_string != "")result.insert(iter, " (" + first_string + ")");
		if (last_string != "")result.insert(result.size(), " (" + last_string + ")");
		return result;
	}

	//void del()//недофункция удаления класса
	//{
	//	while (!person.empty())
	//		person.pop_back();
	//}

private:
	string print_names(const string& string_first, const string& string_last)
	{
		if (string_first != "" && string_last != "")
			return string_first + " " + string_last;
		if (string_first != "")
			return string_first + " with unknown last name";
		if (string_last != "")
			return string_last + " with unknown first name";
	}

	void add_elem(int year, const string& string_first, const string& string_last)
	{
		vector<person_struct>::iterator it = find_if(person.begin(), person.end(),
			[year](const auto& item) {if (item.year == year) return true; else return false; });
		if (it != person.end())
		{
			if (string_first != "")it->first_name = string_first;
			if (string_last != "")it->last_name = string_last;
		}
		else
		{
			person.push_back({ year,string_first,string_last });
			sort(person.begin(), person.end(), [](const auto& x, const auto& y) {return  x.year < y.year; });
		}
	}

	vector<person_struct> person;
};

int main()
{
	Person person;

	//while (true)
	//{
	//	string year, type, name;
	//	vector<string> result;

	//	cin >> year;
	//	if (year != "stop")
	//		cin >> type;
	//	if(type!="print")
	//		cin >> name;
	//	while (year != "stop")
	//	{
	//		if (atoi(type.c_str()) == 1)
	//			person.ChangeFirstName(atoi(year.c_str()), name);
	//		if (atoi(type.c_str()) == 2)
	//			person.ChangeLastName(atoi(year.c_str()), name);
	//		if (type == "print")
	//			result.push_back(person.GetFullNameWithHistory(atoi(year.c_str())));
	//		cin >> year;
	//		if (year != "stop")
	//			cin >> type;
	//		if (type != "print")
	//			cin >> name;
	//	}
	//	person.del();

	//	cout << endl;
	//	for (const auto& item : result)
	//		cout << item << endl;
	//	cout << endl;
	//}

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");
	cout << person.GetFullNameWithHistory(1940) << endl;

	return 0;
}