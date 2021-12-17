//�������� ������� PrintVectorPart, ����������� ������ ����� ����� numbers, ����������� ����� �������
//�������������� ����� � �� � ��������� � ����������� ����� ��� �����, ������������� ����� 
//����������, � �������� �������.���� ������ �� �������� ������������� �����, �������� ��� ����� 
//� �������� �������.
//
//void PrintVectorPart(const vector<int>&numbers);
// 
//������ ����:
//int main() {
//	PrintVectorPart({ 6, 1, 8, -5, 4 });
//	cout << endl;
//	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ������ �� ���������
//	cout << endl;
//	PrintVectorPart({ 6, 1, 8, 5, 4 });
//	cout << endl;
//	return 0;
//}
//
//�����:
//8 1 6
//
//4 5 8 1 6

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void PrintVectorPart(const vector<int>& numbers)
{
	auto pivot = find_if(numbers.begin(), numbers.end(), [](const int& i) {return i < 0; });

	for (auto it = pivot; it != numbers.begin();)
		cout << *(--it) << " ";
}

int main()
{
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ������ �� ���������
	cout << endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	cout << endl;
	return 0;
}