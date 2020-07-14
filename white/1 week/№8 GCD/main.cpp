//В stdin даны два натуральных числа.Выведите в stdout их наибольший общий делитель.
//
//stdin	stdout
//25 27	1
//12 16	4
//13 13	13

#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	cout << a;
	return 0;
}