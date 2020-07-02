//�������� �������, �������:
//���������� IsPalindrom
//���������� bool
//��������� �������� ���� string � ����������, �������� �� ���������� ������ �����������
//
//��������� - ��� ����� ��� �����, ������� ��������� �������� ����� ������� � ������ ������.������ ������ �������� �����������.
//
//�������� �������	���������
//madam				true
//gentleman			false
//X					true

#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string a)
{
	if (a.length() == 0 || a.length() == 1)
		return true;
	else
		for (int i = 0; i <= a.length() / 2 - 1; i++)
			if (a[i] != a[a.length() - 1 - i]) return false;
	return true;
}
int main()
{
	string a;
	getline(std::cin, a);
	cout << boolalpha;
	cout << IsPalindrom(a) << endl;
	return 0;
}