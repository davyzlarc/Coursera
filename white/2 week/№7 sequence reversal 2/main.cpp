//���������� ������� vector<int> Reversed(const vector<int>& v), ������������ ����� ������� v, � ������� ����� ������������ � �������� �������.
//
//������ v	        ��������� �������
//1, 5, 3, 4, 2 	2, 4, 3, 5, 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v)
{
    vector<int> a;
    for (auto i:v)
          a.emplace(a.begin(),i);

    return a;
}

int main()
{
    return 0;
}