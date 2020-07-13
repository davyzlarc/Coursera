//Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
//class Person {
//public:
//    void ChangeFirstName(int year, const string& first_name) {
//        // добавить факт изменения имени на first_name в год year
//    }
//    void ChangeLastName(int year, const string& last_name) {
//        // добавить факт изменения фамилии на last_name в год year
//    }
//    string GetFullName(int year) {
//        // получить имя и фамилию по состоянию на конец года year
//    }
//private:
//    // приватные поля
//};
//
//Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени.
//При этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года́ в последовательных
//вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.
//
//Гарантируется, что все имена и фамилии непусты.
//
//Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека по 
//состоянию на конец данного года.
//
//Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
//Если к данному году случилось изменение фамилии, но не было ни одного изменения имени,
//верните "last_name with unknown first name".
//Если к данному году случилось изменение имени, но не было ни одного изменения фамилии,
//верните "first_name with unknown last name".
//
//Пример:
//Код
//int main() {
//Person person;
//
//person.ChangeFirstName(1965, "Polina");
//person.ChangeLastName(1967, "Sergeeva");
//for (int year : {1900, 1965, 1990}) {
//    cout << person.GetFullName(year) << endl;
//}
//
//person.ChangeFirstName(1970, "Appolinaria");
//for (int year : {1969, 1970}) {
//    cout << person.GetFullName(year) << endl;
//}
//
//person.ChangeLastName(1968, "Volkova");
//for (int year : {1969, 1970}) {
//    cout << person.GetFullName(year) << endl;
//}
//
//return 0;
//}
//
//Вывод
//Incognito
//Polina with unknown last name
//Polina Sergeeva
//Polina Sergeeva
//Appolinaria Sergeeva
//Polina Volkova
//Appolinaria Volkova

#include <iostream>
#include <vector>
#include <algorithm>
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

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}