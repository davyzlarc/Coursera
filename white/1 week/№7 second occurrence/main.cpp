//ƒана строка.Ќайдите в этой строке второе вхождение буквы f и выведите индекс этого вхождени€.≈сли буква f в данной строке встречаетс€ только один раз, выведите число - 1, 
//а если не встречаетс€ ни разу, выведите число - 2. »ндексы нумеруютс€ с нул€.
//
//stdin		stdout
//comfort	- 1
//coffee	3
//car		-2

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = -2, i = -1;
	for (auto c : s) {
		i++;
		if (c == 'f')
		{
			n++;
			if (n != -1)break;
		}

	}
	if (n == -2)
		cout << "-2";
	if (n == -1)
		cout << "-1";
	if (n == 0)
		cout << i;
	return 0;
}