//Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы Reverse для переворота строки 
//и ToString для получения строки.
//
//Пример:
//Код
//int main() {
//ReversibleString s("live");
//s.Reverse();
//cout << s.ToString() << endl;
//
//s.Reverse();
//const ReversibleString& s_ref = s;
//string tmp = s_ref.ToString();
//cout << tmp << endl;
//
//ReversibleString empty;
//cout << '"' << empty.ToString() << '"' << endl;
//
//return 0;
//}
//
//Вывод
//evil
//live
//""

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
	ReversibleString() {
		String = "";
	}
	ReversibleString(const string& string) {
		String = string;
	}
	void Reverse() {
		reverse(String.begin(), String.end());
	}
	string ToString() const {
		return String;
	}
private:
	string String;
};

int main()
{
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}