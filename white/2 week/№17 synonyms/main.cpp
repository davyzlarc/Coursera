//��� ����� ���������� ���������� ���� �����, ���� ��� ����� ������� ��������. ���������� ��������� ��������
//��� ������� ��������� :
//ADD   -  word1 word2 � �������� � ������� ���� ���������(word1, word2).
//COUNT -  word � ������ ���������� ��������� ����� word.
//CHECK -  word1 word2 � ���������, �������� �� ����� word1 � word2 ����������. ����� word1 � word2 ��������� ����������,
//		   ���� ����� �������� ADD ��� ���� �� ���� ������ ADD word1 word2 ��� ADD word2 word1.
//
//���������
//��� ���������, ����� �������, ��� �������� �� �������� ���������������, �� ����, ���� A - ������� B, � B - ������� C,
//�� �� ����� �� �������, ��� A - ������� C.
//
//������ �����
//������� �������� ���������� �������� Q, ����� Q ����� � ���������� ��������.�������������, ��� � ������ ������� CHECK
//� ADD ����� word1 � word2 ��������.��� ����� ������� ���� �� ��������� ����, ���� � �������� �������������.
//
//������ ������
//��� ������� ������� � ��������������� ������ �������� ����� �� ���� :
//� ����� �� ������ COUNT word �������� ������������ ����� ����� � ���������� ��������� ����� word.
//� ����� �� ������ CHECK word1 word2 �������� ������ YES, ���� word1 � word2 �������� ����������, � NO � ��������� ������.
//
//������:
//����
//8
//ADD program code
//COUNT cipher
//ADD code cipher
//COUNT code
//COUNT program
//CHECK code program
//CHECK program cipher
//CHECK cpp java
//
//�����
//0
//2
//1
//YES
//NO
//NO

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

int ADD(map<string, set<string>>& SYNONYMS, const string& WORD1, const string& WORD2)
{
	SYNONYMS[WORD1].insert(WORD2);
	SYNONYMS[WORD2].insert(WORD1);
	return 0;
}

int COUNT(const map<string, set<string>>& SYNONYMS, const string& WORD)
{
	if (SYNONYMS.find(WORD) != SYNONYMS.cend())
		return int(SYNONYMS.at(WORD).size());

	return 0;
}

bool CHECK(const map<string, set<string>>& SYNONYMS, const string& WORD1, const string& WORD2)
{
	if (SYNONYMS.find(WORD1) != SYNONYMS.cend())
		if(SYNONYMS.at(WORD1).find(WORD2)!=SYNONYMS.at(WORD1).cend())
		return true;

	return false;
}

int main()
{
	map<string, int>command = { {"ADD",1},{"COUNT",2},{"CHECK",3} };
	map<string, set<string>>SYNONYMS;
	int n;
	cin >> n;
	vector<string>result(0);

	for (auto i = 1; i <= n; i++)
	{
		static string operation;
		cin >> operation;
		switch (command[operation])
		{
		case 1://ADD 
		{
			static string WORD1, WORD2;
			cin >> WORD1 >> WORD2;
			ADD(SYNONYMS, WORD1, WORD2);
		}
		break;
		case 2://COUNT 
		{
			static string WORD;
			cin >> WORD;
			result.push_back(to_string(COUNT(SYNONYMS, WORD)));
		}
		break;
		case 3://CHECK
		{
			static string WORD1, WORD2;
			cin >> WORD1 >> WORD2;
			if (CHECK(SYNONYMS, WORD1, WORD2))
				result.push_back("YES");
			else
				result.push_back("NO");
		}
		break;
		}
	}

	for (const auto& item : result)
		cout << item << endl;

	return 0;
}