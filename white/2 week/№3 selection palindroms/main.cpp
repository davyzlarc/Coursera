//�������� �������, �������:
//���������� PalindromFilter
//���������� vector<string>
//��������� vector<string> words � int minLength � ���������� ��� ������ �� ������� words, ������� �������� ������������ � ����� ����� �� ������ minLength
//
//������� ������ �������� �� ����� 100 �����, ����� ������ ������ �� ������ 100 ��������.
//
//words				minLength	���������
//abacaba, aba		5			abacaba
//abacaba, aba		2			abacaba, aba
//weew, bro, code	4			weew
//
//�� �������� �������� ���� � ����������� ������� PalindromFilter.��� ���� ����� ��������� � ������ �������, ���� ��� ��� ����������.
//� ���� ������ ���� ��������� �� ������� ��� - �� ��������� �� stdin � ���������� � stdout � ����������� ������� ����� �������� ���� ������� PalindromFilter ��������

#include <iostream>
#include <string>
#include <vector>
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

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> a;
	for (auto i : words)
		if (i.length() >= minLength)
			if (IsPalindrom(i)) a.push_back(i);
	return a;
}

int main()
{
	return 0;
}