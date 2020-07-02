//�������� �������, �������:
//���������� Factorial
//���������� int
//��������� int � ���������� ��������� ������ ���������.�������������, ��� �������� ������� �� ������ �� ��������� 10. ��� ������������� ���������� ������� ������ ���������� 1.
//
//�������� �������	���������
//1					1
//- 2				1
//4					24

#include <iostream>
using namespace std;

int Factorial(int a)
{
	if (a <= 0)
	{
		return 1;
	}
	else
		return a * Factorial(a - 1);
}
int main() {
	int a;
	cin >> a;
	a = Factorial(a);
	cout << a;
	return 0;
}