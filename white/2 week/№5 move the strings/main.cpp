//�������� ������� MoveStrings, ������� ��������� ��� ������� �����, source � destination, � ���������� ��� ������ �� ������� ������� � ����� �������.
//����� ���������� ������� ������ source ������ ��������� ������.
//
//����� �������� ���������� �������, ���� ������� � ���� ����� clear :
//vector<string> words = { "hey", "hi" };
//words.clear();/*������ ������ words ����*/
//
//������
//vector<string> source = { "a", "b", "c" };
//vector<string> destination = { "z" };
//MoveStrings(source, destination); /*source ������ ��������� ������, destination ������ ��������� ������ "z", "a", "b", "c" ������ � ����� �������*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination)
{
	for (auto i : source)
		destination.push_back(i);
	source.clear();
}

int main()
{
	return 0;
}