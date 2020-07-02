//����� ���������� ����������� ���� �����, ���� ���� �� ��� ����� �������� ������������� ���� � ������.��������, ����� �eat� ����� �������� ������������� 
//���� ����� �tea�, ������� ��� ����� �������� ����������� ���� �����.���� ���� ����, ��������� ��� ������ �� ���, �������� �� ����� ���� ���� ����������� ���� �����.
//
//��������:
//���� �� �������� �������� ����, �������� �� ����� ����������� ���� �����, ����������� � ���������.��� ������� ����� � ������� ������� ����������,
//������� ��� � �� ����������� ������ �����.���� ��� ����� ���� ��� ������� �����(� ��� ����������� � ������� �������� ��������� == ), �� ����� ��������
//����������� ���� �����, � ��������� ������ �� ��������.
//��� ���� ���������� ������ ������� �� ����� ������ ������� � ��������� ������� BuildCharCounters.
//
//������ �����
//������� ���� ����� ��� ���� N, ����� � N ������� ���������� ���� ����, ������� ���������� ���������.�������������, ��� ��� ����� ������� ���� �� �������� ��������� ����.
//
//������ ������
//�������� N ����� : ��� ������ �������� ���� ���� YES, ���� ��� ����� �������� �����������, � NO � ��������� ������.
//
//������:
//����
//3
//eat tea
//find search
//master stream
//�����
//YES
//NO
//YES


#include <iostream>
#include<vector>
#include<map>
using namespace std;

bool check(const string& first, const string& second)
{
	map<char, int>a, b;
	size_t i_max = second.size() - 1, i_min = first.size() - 1;
	if (first.size() > second.size())
	{
		i_max = first.size() - 1;
		i_min = second.size() - 1;
	}

	for (auto i = 0; i <= i_max; i++)
	{
		if (i <= i_min)
			a[first[i]]++;
		if (i <= i_max)
			b[second[i]]++;
	}

	if (a == b)
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;
	vector<string>result(0);

	for (auto i = 1; i <= n; i++)
	{
		string first, second;
		cin >> first;
		cin >> second;

		if (check(first, second))
			result.push_back("YES");
		else
			result.push_back("NO");
	}

	for (const auto& item : result)
		cout << item << endl;
	return 0;
}