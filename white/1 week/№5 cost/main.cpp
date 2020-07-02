//�������� ��������� ���������� ��������� ������� ������ � ������ ������.���� �������� ��������� ������ ������ A ������, �� �� �� ��������������� ������ � X ���������.
//���� �������� ��������� ������ ������ B ������, �� �� �� ��������������� ������ � Y ���������.
//�� ���� ��������� ���� ���� ������������ ����� : N, A, B, X, Y(A < B) - ��� N - �������� ��������� ������.�������� ��������� ������� ������ � ������ ������.
//
//stdin					stdout
//100 110 120 5 10		100
//115 110 120 5 10		109.25
//150 110 120 5 12.5	131.25

#include <iostream>
using namespace std;

int main() {
	double n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;

	if (n <= a)
		cout << n;
	else {
		if (n <= b) {
			double nx = n - n * x / 100;
			if (nx < 0)
				cout << "0";
			else
				cout << nx;
		}
		if (n > b) {
			double ny = n - n * y / 100;
			if (ny < 0)
				cout << "0";
			else
				cout << ny;
		}
	}
	return 0;
}