//�������� ������� UpdateIfGreater, ������� ��������� ��� ������������� ��������� : first � second.
//���� first �������� ������ second, ���� ������� ������ ���������� � second �������� ��������� first.
//��� ���� ��������� ������� �� ������ ������ ����������, � ��������� ��������� second ������ ���� ����� �� ���������� �������.
//
//������
//int a = 4;
//int b = 2;
//UpdateIfGreater(a, b); /*(b ������ ����� ����� 4)*/

#include <iostream>
using namespace std;

void UpdateIfGreater(int first, int& second)
{
	if (first > second)
		second = first;
}

int main()
{
	return 0;	
}