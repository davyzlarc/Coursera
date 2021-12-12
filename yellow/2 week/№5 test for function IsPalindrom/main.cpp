//В этой задаче вам нужно разработать набор юнит - тестов для функции:
//bool IsPalindrom(const string & s);
// 
//	Эта функция проверяет, является ли строка s палиндромом. Палиндром — это слово или фраза, 
//которые одинаково читаются слева направо и справа налево. Примеры палиндромов: madam, 
//level, wasitacaroracatisaw
//
//	Разработайте набор юнит - тестов, который будет принимать правильные реализации функции IsPalindrom
//и отвергать неправильные. При этом учитывайте, что правильная реализация функции:
//считает пустую строку палиндромом;
//считает строку из одного символа палиндромом;
//осуществляет обычное сравнение символов на равенство, не игнорируя никакие символы, в том числе пробельные.
//
//	При разработке тестов подумайте, какие ошибки можно допустить при реализации функции IsPalindrom. Примеры ошибок :
//игнорируется первый или последний символ;
//сравнение соответствующих символов завершается не в середине строки, а раньше;
//игнорируются пробелы
//
//	Начать работу вы можете с шаблона, который содержит наш фреймворк юнит - тестов и заготовку 
//функции IsPalindrom - test_palindrome.cpp
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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

bool IsPalindrom(const string& a)
{
	if (a.length() == 0 || a.length() == 1)
		return true;
	else
		for (int i = 0; i <= a.length() / 2 - 1; i++)
			if (a[i] != a[a.length() - 1 - i]) return false;
	return true;
}

void TestCorrect()
{
	Assert(IsPalindrom("madam"), "madam");
	Assert(IsPalindrom("maam"), "maam");
}

void TestEmpty()
{
	Assert(IsPalindrom(""), "empty string");
}

void TestOneSymbol()
{
	Assert(IsPalindrom("q"), "q");
}

void TestSpecialCharacters()
{
	Assert(IsPalindrom("q!@ QWE_2_EWQ @!q"), "q!@ QWE_2_EWQ @!q");
}

void ExtremeSymbols()
{
	Assert(!IsPalindrom(" madam"), " madam");
	Assert(!IsPalindrom("madam "), "madam ");
}

void MiddleSymbols()
{
	Assert(!IsPalindrom("madalam"), "madalam");
}

void DifferentCaseSymbols()
{
	Assert(!IsPalindrom("Madam"), "Madam");
	Assert(!IsPalindrom("madaM"), "madaM");
}

int main() {
	TestRunner runner;
	runner.RunTest(TestCorrect, "Correct palindrom");
	runner.RunTest(TestEmpty, "Empty string");
	runner.RunTest(TestOneSymbol, "One symbol string");
	runner.RunTest(TestSpecialCharacters, "String with special characters, including space");
	runner.RunTest(ExtremeSymbols, "String with wrong extreme characters");
	runner.RunTest(MiddleSymbols, "String with wrong middle characters");
	runner.RunTest(DifferentCaseSymbols, "Different case of symbols");
	
	return 0;
}