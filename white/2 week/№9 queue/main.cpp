//Ћюди сто€т в очереди, но никогда не уход€т из еЄ начала, зато могут приходить в конец и уходить оттуда.
//Ѕолее того, иногда некоторые люди могут прекращать и начинать беспокоитьс€ из - за того, что очередь не продвигаетс€.
//
//–еализуйте обработку следующих операций над очередью :
//WORRY i : пометить i - го человека с начала очереди(в нумерации с 0) как беспоко€щегос€;
//QUIET i : пометить i - го человека как успокоившегос€;
//COME k : добавить k спокойных человек в конец очереди;
//COME - k: убрать k человек из конца очереди;
//WORRY_COUNT: узнать количество беспоко€щихс€ людей в очереди.
//»значально очередь пуста.
//
//‘ормат ввода:
// оличество операций Q, затем описани€ операций.
//ƒл€ каждой операции WORRY i и QUIET i гарантируетс€, что человек с номером i существует в очереди на момент операции.
//ƒл€ каждой операции COME - k гарантируетс€, что k не больше текущего размера очереди.
//
//‘ормат вывода:
//ƒл€ каждой операции WORRY_COUNT выведите одно целое число Ч количество беспоко€щихс€ людей в очереди.
//
//ѕример:
//¬вод
//8
//COME 5
//WORRY 1
//WORRY 4
//COME - 2
//WORRY_COUNT
//COME 3
//WORRY 3
//WORRY_COUNT
//
//¬ывод
//1
//2

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	vector<bool> queue;//true- worrywart, false - quiet
	map<string, int>Map = { {"WORRY",1},{"QUIET",2},{"COME",3},{"WORRY_COUNT",4} };

	vector<int> result;

	int n;
	cin >> n;
	
	for (auto i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		int a;

		switch (Map[s])
		{
		case 1://WORRY
			cin >> a;
			queue[a] = true;
			break;
		case 2://QUIET
			cin >> a;
			queue[a] = false;
			break;
		case 3://COME
			cin >> a;
			if (a > 0)//adding
				for (auto i = 1; i <= a; i++)
					queue.push_back(false);
			if (a < 0)//deleting
				for (auto i = a; i <= -1; i++)
					queue.pop_back();
			break;
		case 4://WORRY_COUNT
			int total = 0;
			for (auto j : queue)
				if (j) total++;
			result.push_back(total);
			break;
		}
	}

	for (auto i : result)
		cout << i << endl;
	return 0;
}