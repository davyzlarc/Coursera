//��� ����� �����.������� ���������� ���������� ����� � ���� ������.
//
//������ �����
//������� �������� ���������� ����� N, ����� � ���� N �����, ���������� �������� �������� ������.
//��� ������ ������� ���� �� ��������� ����, ���� � �������� �������������.
//
//������ ������
//�������� ������������ ����� ����� � ���������� ���������� ����� � ������ ������.
//
//������:
//����
//6
//first
//second
//first
//third
//second
//second
//
//�����
//3

#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
	set<string> strings;
	int n;
	cin >> n;

	string s;
	getline(std::cin, s);
	for (auto i = 0; i < n; i++)
	{
		getline(std::cin,s);
		strings.insert(s);
	}

	cout << strings.size();
	return 0;
}