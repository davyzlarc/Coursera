//В стандартном потоке даны три строки, разделённые пробелом.Каждая строка состоит из строчных латинских букв и имеет длину не более 30 символов.
//Выведите в стандартный вывод лексикографически минимальную из них.
//
//stdin					stdout
//milk milkshake month	milk
//c a b	                a
//fire fog wood      	fire

#include <iostream>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	if (a < b && a < c) {
		cout << a;
	}
	else {
		if (b < c) {
			cout << b;
		}
		else {
			cout << c;
		}
	}
	return 0;
}