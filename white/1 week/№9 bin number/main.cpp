//�� ���� ���� ����� ������������� ����� N.�������� ��� � �������� ������� ��������� ��� ������� �����.
//
//stdin	stdout
//5		101
//32	100000
//1		1
//
//���������
//����� N ����� ��������� � ���������� ���� int
//�������� �������� �� ���������� ������� ��������� � ��������, ����� ���� ������, ��������, �����:
//https://www.yaklass.ru/p/informatika/10-klass/informatciia-i-informatcionnye-protcessy-11955/predstavlenie-chislovoi-informatcii-v-kompiutere-11901/re-62e8903e-ba93-478a-85b5-ae45af40c658
//� ���� ������ ��� ����� ����������� ��������� vector; ����������, ��� ���������� �������� x � ����� ������� v �������� ��� : v.push_back(x);

#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a;
	while (n != 0)
	{
		a.insert(a.begin(), n % 2);
		n /= 2;
	}
	while (a.front() == 0)
	{
		a.erase(a.begin());
	}
	for (auto c : a) {
		cout << c;
	}
	return 0;
}