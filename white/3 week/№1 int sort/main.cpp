//� ����������� ������ ���� ���� ������, ��������� �� N + 1 ����� �����.������ ������ ��� ���� ����� N. 
//����� ������� ��� N �����, ��������� �� �� ������ A.����� ����� ����� ��������� ��������.
//
//������������ ������ � �� ������ � �������� ��� � ����������� �����.
//
//�����������:
//0 <= N <= 1000
//- 1000000 <= A[i] <= 1000000
//
//�������:
//stdin			stdout
//2 - 4 3		3 - 4
//3 1 - 3 2		1 2 - 3
//
//���������:
//������� sort ������������� ��������� ������ ��������. ������� ��� ��������� �� ������.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<int>VECTOR(N);
	for (auto& item : VECTOR)
		cin >> item;
	
	sort(VECTOR.begin(), VECTOR.end(), [](int a, int b) {return (abs(a) < abs(b));});

	for (const auto& item : VECTOR)
		cout << item << " ";

	return 0;
}