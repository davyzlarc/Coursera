//���� ����� � �������, �� ������� �� ������ �� � ������, ���� ����� ��������� � ����� � ������� ������.
//����� ����, ������ ��������� ���� ����� ���������� � �������� ������������ �� - �� ����, ��� ������� �� ������������.
//
//���������� ��������� ��������� �������� ��� �������� :
//WORRY i : �������� i - �� �������� � ������ �������(� ��������� � 0) ��� ��������������;
//QUIET i : �������� i - �� �������� ��� ��������������;
//COME k : �������� k ��������� ������� � ����� �������;
//COME - k: ������ k ������� �� ����� �������;
//WORRY_COUNT: ������ ���������� ������������� ����� � �������.
//���������� ������� �����.
//
//������ �����:
//���������� �������� Q, ����� �������� ��������.
//��� ������ �������� WORRY i � QUIET i �������������, ��� ������� � ������� i ���������� � ������� �� ������ ��������.
//��� ������ �������� COME - k �������������, ��� k �� ������ �������� ������� �������.
//
//������ ������:
//��� ������ �������� WORRY_COUNT �������� ���� ����� ����� � ���������� ������������� ����� � �������.
//
//������:
//����
//8
//COME 5
//WORRY 1
//WORRY 4
//COME - 2
//WORRY_COUNT
//COME 3
//WORRY 3
//WORRY_COUNT
//
//�����
//1
//2

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	vector<bool> queue;//true- worrywart, false - quiet
	map<string, int>Map = { {"WORRY",1},{"QUIET",2},{"COME",3},{"WORRY_COUNT",4} };

	vector<int> result;

	int n;
	cin >> n;
	
	for (auto i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		int a;

		switch (Map[s])
		{
		case 1://WORRY
			cin >> a;
			queue[a] = true;
			break;
		case 2://QUIET
			cin >> a;
			queue[a] = false;
			break;
		case 3://COME
			cin >> a;
			if (a > 0)//adding
				for (auto i = 1; i <= a; i++)
					queue.push_back(false);
			if (a < 0)//deleting
				for (auto i = a; i <= -1; i++)
					queue.pop_back();
			break;
		case 4://WORRY_COUNT
			int total = 0;
			for (auto j : queue)
				if (j) total++;
			result.push_back(total);
			break;
		}
	}

	for (auto i : result)
		cout << i << endl;
	return 0;
}