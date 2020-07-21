//Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, позволяющим задать имя и фамилию человека 
//при рождении, а также сам год рождения. Класс не должен иметь конструктора по умолчанию.
//
//При получении на вход года, который меньше года рождения :
//методы GetFullName и GetFullNameWithHistory должны отдавать "No person";
//методы ChangeFirstName и ChangeLastName должны игнорировать запрос.
//
//Кроме того, необходимо объявить константными все методы, которые по сути ими являются.
//
//Пример:
//Код
//int main() {
//    Person person("Polina", "Sergeeva", 1960);
//    for (int year : {1959, 1960}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeFirstName(1965, "Appolinaria");
//    person.ChangeLastName(1967, "Ivanova");
//    for (int year : {1965, 1967}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    return 0;
//}
//
//Вывод
//No person
//Polina Sergeeva
//Appolinaria(Polina) Sergeeva
//Appolinaria(Polina) Ivanova(Sergeeva)

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
	Person(const string& first_name, const string& last_name, int year) {
		person.push_back({ year,first_name,last_name });
	}

	void ChangeFirstName(int year, const string& first_name) {
		if (!check_year(year))
			add_elem(year, first_name, "");
	}

	void ChangeLastName(int year, const string& last_name) {
		if (!check_year(year))
			add_elem(year, "", last_name);
	}

	string GetFullName(int year) const {
		if (check_year(year))
			return "No person";

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

	string GetFullNameWithHistory(int year) const {
		string result = GetFullName(year);

		if (result == "Incognito" || result == "No person")
			return result;

		vector<person_struct>::const_iterator it = person.cbegin();
		vector<string>first_names, last_names;
		while (it < person.end() - 1 && it->year < year)
		{
			vector<person_struct>::const_iterator it_last = it, it_next = it + 1;
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
	bool check_year(int year) const {
		if (year < person.begin()->year)
			return true;
		return false;
	}

	string print_names(const string& string_first, const string& string_last) const {
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

	//Person person;
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

	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}