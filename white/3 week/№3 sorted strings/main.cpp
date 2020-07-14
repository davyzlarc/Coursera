//Реализуйте класс, поддерживающий набор строк в отсортированном порядке. Класс должен содержать два публичных метода :
//class SortedStrings {
//public:
//    void AddString(const string& s) {
//        // добавить строку s в набор
//    }
//    vector<string> GetSortedStrings() {
//        // получить набор из всех добавленных строк в отсортированном порядке
//    }
//private:
//    // приватные поля
//};
//
//Пример:
//Код
//void PrintSortedStrings(SortedStrings& strings) {
//for (const string& s : strings.GetSortedStrings()) {
//	cout << s << " ";
//}
//cout << endl;
//}
//
//int main() {
//	SortedStrings strings;
//
//	strings.AddString("first");
//	strings.AddString("third");
//	strings.AddString("second");
//	PrintSortedStrings(strings);
//
//	strings.AddString("second");
//	PrintSortedStrings(strings);
//
//	return 0;
//}
//
//Вывод
//first second third
//first second second third

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		strings.push_back(s);
		sort(strings.begin(), strings.end());
	}
	vector<string> GetSortedStrings() {
		return strings;
	}
private:
	vector<string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
	for (const string& s : strings.GetSortedStrings())
		cout << s << " ";
	cout << endl;
}

int main() {
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}