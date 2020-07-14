//На вход дано целое положительное число N.Выведите его в двоичной системе счисления без ведущих нулей.
//
//stdin	stdout
//5		101
//32	100000
//1		1
//
//Подсказка
//число N можно считывать в переменную типа int
//алгоритм перевода из десятичной системы счисления в двоичную, может быть найден, например, здесь:
//https://www.yaklass.ru/p/informatika/10-klass/informatciia-i-informatcionnye-protcessy-11955/predstavlenie-chislovoi-informatcii-v-kompiutere-11901/re-62e8903e-ba93-478a-85b5-ae45af40c658
//в этой задаче вам может пригодиться контейнер vector; напоминаем, что добавление значения x в конец вектора v делается так : v.push_back(x);

#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a;
	while (n != 0)
	{
		a.insert(a.begin(), n % 2);
		n /= 2;
	}
	while (a.front() == 0)
	{
		a.erase(a.begin());
	}
	for (auto c : a) {
		cout << c;
	}
	return 0;
}