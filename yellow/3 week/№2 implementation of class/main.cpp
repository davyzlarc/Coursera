//��� ��� ������������ ���� phone_number.h, ���������� ���������� ������ PhoneNumber.
//��� ���� � ������������ ������� ���������, ������� ��������� �� ���������� ����� ������.
// 
//�������� cpp - ���� � ������������� ������� ������ PhoneNumber, ������� ��������� ��������� ���������.
//
//��� ����� ������������� ��� ���:
//	�������������� ����������� ������� ������� ��� cpp - ���� � ������, ���������� ������ cpp - ���� �
//���� - ������� ��� ������ PhoneNumber, � ����� ���� phone_number.h.����� ��� ������ ���� 
//������ �, ���� ���������� ����� ��������� �������, �������� ������������ ����������� ����.
//���� �� ���������� �������(�.�.���� - ����� �� ������ ������ � ����� ����������), �� ���� ������� 
//����� ���������.

#include <iostream>
#include "phone_number.h"

using namespace std;

int main() {
	PhoneNumber p("+7-982-799-7887");
	cout << p.GetInternationalNumber() << endl;

	return 0;
}