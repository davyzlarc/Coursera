//В первом курсе «Белый пояс по С++» у нас была задача «Имена и фамилии — 1».В ней надо было разработать класс Person, 
//поддерживающий историю изменений человеком своих фамилии и имени.В данной задаче вам надо разработать юнит - тесты
//на реализацию класса Person.При разработке тестов учитывайте ограничения, которые накладывает на класс Person условие
//задачи «Имена и фамилии — 1».
//
//Начать работу вы можете с шаблона, который содержит наш фреймворк юнит - тестов и заготовку класса - test_person.cpp

//Условие задачи «Имена и фамилии — 1»:
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
//	Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. 
//	При этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года́ в последовательных 
//вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.
//	Гарантируется, что все имена и фамилии непусты.
//	Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека по 
//состоянию на конец данного года.
//	Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
//	Если к данному году случилось изменение фамилии, но не было ни одного изменения имени,
//верните "last_name with unknown first name".
//	Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, 
//верните "first_name with unknown last name".

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (exception& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
		catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

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

void TestFirstLast()
{
	Person person;

	person.ChangeFirstName(50, "Ivan");
	person.ChangeLastName(60, "Ivanov");

	AssertEqual(person.GetFullName(40), "Incognito",
		"TestFirstLast | No data");
	AssertEqual(person.GetFullName(50), "Ivan with unknown last name",
		"TestFirstLast | Year equals the year of changing first name, but before the year of changing last name");
	AssertEqual(person.GetFullName(55), "Ivan with unknown last name",
		"TestFirstLast | Year after the year of changing first name, but before the year of changing last name");
	AssertEqual(person.GetFullName(60), "Ivan Ivanov",
		"TestFirstLast | Year equals the year of changing last name and after the year of changing first name");
	AssertEqual(person.GetFullName(65), "Ivan Ivanov",
		"TestFirstLast | Year after the year of changing last name and after the year of changing first name");
}

void TestLastFirst()
{
	Person person;

	person.ChangeLastName(50, "Ivanov");
	person.ChangeFirstName(60, "Ivan");

	AssertEqual(person.GetFullName(40), "Incognito",
		"TestLastFirst | No data");
	AssertEqual(person.GetFullName(50), "Ivanov with unknown first name",
		"TestLastFirst | Year equals the year of changing last name, but before the year of changing first name");
	AssertEqual(person.GetFullName(55), "Ivanov with unknown first name",
		"TestLastFirst | Year after the year of changing last name, but before the year of changing first name");
	AssertEqual(person.GetFullName(60), "Ivan Ivanov",
		"TestLastFirst | Year equals the year of changing first name and after the year of changing last name");
	AssertEqual(person.GetFullName(65), "Ivan Ivanov",
		"TestLastFirst | Year after the year of changing first name and after the year of changing last name");
}

void TestSort()
{
	Person person1, person2;

	person1.ChangeFirstName(60, "Ivan");
	person1.ChangeLastName(50, "Ivanov");

	person2.ChangeLastName(60, "Ivanov");
	person2.ChangeFirstName(50, "Ivan");

	AssertEqual(person1.GetFullName(55), "Ivanov with unknown first name",
		"TestSort | Year after changing last name, but before year of changing first name (changing first name operstion was pervious than changing last name)");
	AssertEqual(person1.GetFullName(65), "Ivan Ivanov",
		"TestSort | Year after changing last name and after year of changing first name (changing first name operstion was pervious than changing last name)");

	AssertEqual(person2.GetFullName(55), "Ivan with unknown last name",
		"TestSort | Year after changing first name, but before year of changing last name (changing last name operstion was pervious than changing first name)");
	AssertEqual(person2.GetFullName(65), "Ivan Ivanov",
		"TestSort | Year after changing first name and after year of changing last name (changing last name operstion was pervious than changing first name)");
}

void TestsWithoutRepeatChanges()
{
	TestFirstLast();
	TestLastFirst();
	TestSort();
}

int main() {
	TestRunner runner;
	runner.RunTest(TestsWithoutRepeatChanges, "Tests without any modifications");

	return 0;
}