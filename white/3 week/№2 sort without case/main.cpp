//� ����������� ������ ���� ���� ������, ��������� �� ����� N � ��������� �� ��� N ����� S.
//����� ����� ����� � ������ ��������� ��������.
//
//������������ ������ S � ������������������ ������� �� �����������, ��������� ������� ����, � �������� �� �
//����������� ����� ������.
//
//�����������:
//0 <= N <= 1000
//1 <= |S| <= 15
//������ ������ S[i] ����� �������� �� ��������� �������� : [0 - 9, a - z, A - Z]
//
//�������:
//stdin		stdout
//2 q A		A q
//3 a C b	a b C
//
//���������:
//�������� �������� �� ������� tolower.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<string>VECTOR(N);
	for (auto& item : VECTOR)
		cin >> item;

	sort(VECTOR.begin(), VECTOR.end(), [VECTOR](string a, string b) {
		for (auto& ch : a)
			ch = tolower(ch);
		for (auto& ch : b)
			ch = tolower(ch);
		return (a < b);
		});

	for (const auto& item : VECTOR)
		cout << item << " ";

	return 0;
}