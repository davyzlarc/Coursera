//�������� ������� SplitIntoWords, ����������� ������ �� ����� �� ��������.
//vector<string> SplitIntoWords(const string& s);
// 
//�������������, ���:
//������ �������;
//������ ������� ���� �� ��������� ���� � ��������;
//������ � ��������� ������� ������ �� �������� ���������;
//������ �� �������� ���� �������� ������.
//
//���������:
//������������� ��������� ������ ������� ������ :
//������ ��������� ������ � ������� ��������� find;
//��������� ��������� ����� � ������� ������������ ������ �� ���� ����������.
//
//������ ����:
//int main() {
//    string s = "C Cpp Java Python";
//
//    vector<string> words = SplitIntoWords(s);
//    cout << words.size() << " ";
//    for (auto it = begin(words); it != end(words); ++it) {
//        if (it != begin(words)) {
//            cout << "/";
//        }
//        cout << *it;
//    }
//    cout << endl;
//
//    return 0;
//}
// 
//�����:
//� / Cpp / Java / Python
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> result;
	string::const_iterator it_begin = s.begin(),
		it_space;

	while ((it_space = find_if(it_begin, s.end(), [](const char& ch) {return ch == ' '; })) != s.end())
	{
		result.push_back({ it_begin, it_space });
		it_begin = ++it_space;
	}
	result.push_back({ it_begin, s.end() });

	return result;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}