//���� ������.������� � ���� ������ ������ ��������� ����� f � �������� ������ ����� ���������.���� ����� f � ������ ������ ����������� ������ ���� ���, �������� ����� - 1, 
//� ���� �� ����������� �� ����, �������� ����� - 2. ������� ���������� � ����.
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