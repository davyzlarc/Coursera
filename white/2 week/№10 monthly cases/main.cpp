//У каждого из нас есть повторяющиеся ежемесячные дела, каждое из которых нужно выполнять в конкретный день каждого месяца : оплата счетов за электричество, 
//абонентская плата за связь и пр.Вам нужно реализовать работу со списком таких дел на месяц, а именно, реализовать набор следующих операций :
//ADD i s
//Назначить дело с названием s на день i текущего месяца.
//
//DUMP i
//Вывести все дела, запланированные на день i текущего месяца.
//
//NEXT
//Перейти к списку дел на новый месяц.При выполнении данной команды вместо текущего(старого) списка дел на текущий месяц создаётся и становится активным(новый) 
//список дел на следующий месяц : все дела со старого списка дел копируются в новый список.После выполнения данной команды новый список дел и следующий месяц становятся 
//текущими, а работа со старым списком дел прекращается.При переходе к новому месяцу необходимо обратить внимание на разное количество дней в месяцах :
//	если следующий месяц имеет больше дней, чем текущий, «дополнительные» дни необходимо оставить пустыми(не содержащими дел);
//	если следующий месяц имеет меньше дней, чем текущий, дела со всех «лишних» дней необходимо переместить на последний день следующего месяца.
//
//Замечания
//Историю списков дел хранить не требуется, работа ведется только с текущим списком дел текущего месяца.Более того, при создании списка дел на следующий месяц, он «перетирает» предыдущий список.
//Обратите внимание, что количество команд NEXT в общей последовательности команд при работе со списком дел может превышать 11.
//Начальным текущим месяцем считается январь.
//Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.
//
//Формат ввода
//Сначала число операций Q, затем описания операций.
////Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания.Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца.
//
//Формат вывода
//Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день, а затем их названия, разделяя их пробелом.Порядок вывода дел 
//в рамках каждой операции значения не имеет.
//
//Пример:
//Ввод
//12
//ADD 5 Salary
//ADD 31 Walk
//ADD 30 WalkPreparations
//NEXT
//DUMP 5
//DUMP 28
//NEXT
//DUMP 31
//DUMP 30
//DUMP 28
//ADD 28 Payment
//DUMP 28
//
//Вывод
//1 Salary
//2 WalkPreparations Walk
//0
//0
//2 WalkPreparations Walk
//3 WalkPreparations Walk Payment
//
//Указание:
//Для дописывания всех элементов вектора v2 в конец вектора v1 удобно использовать метод insert : 
//v1.insert(end(v1), begin(v2), end(v2));
//
//Кроме того, элементом вектора может быть любой тип, в том числе и другой вектор.Например, vector<vector<int>> — это вектор, элементами которого являются 
//вектора целых чисел(то есть двумерный массив).
//
//Пример использования:
//vector<vector<int>> m(10); // Создаём вектор из десяти векторов целых чисел
//m[0].push_back(5);  // Добавляем элементы в первый вектор
//m[0].push_back(15);
//cout << m[0][1]; // Выведет 15 — второй элемент первого вектора
//
//m[1].push_back(3);
//for (int x : m[1]) {
//	// Перебираем все элементы второго 
//}


#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void add(const int& i, const string& s, vector<string>& vector)
{
	if (vector[i] != "")
		vector[i] += " ";
	vector[i] += s;
}

int next_month(int& current_month, vector<string>& days)
{
	if (current_month == 1)//->28
	{
		for (auto i = 28; i <= 30; i++)
			if (days[i] != "")
				add(27, days[i], days);
		days.resize(28);
		current_month++;
		return 0;
	}
	if (current_month == 3 || current_month == 5 || current_month == 8 || current_month == 10)//->30
	{
		if (days[30] != "")
			add(29, days[30], days);
		days.resize(30);
		current_month++;
		return 0;
	}
	if (current_month == 2 || current_month == 4 || current_month == 6 || current_month == 7 || current_month == 9 || current_month == 11 || current_month == 12)//->31
	{
		days.resize(31);
		current_month++;
		if (current_month == 13)
			current_month = 1;
		return 0;
	}
}

string dump(const int& i, vector<string>& vector)
{
	return vector[i];
}

string count(string s)
{
	if (s.size() == 0)
		return to_string(0);
	int i = 0, result = 1;
	do
	{
		if ((i = s.find(" ", i) + 1) != 0)
			result++;
	} while (i != 0);
	return to_string(result);
}

int main()
{
	map<string, int>Map = { {"ADD",1},{"DUMP",2},{"NEXT",3} };
	int current_month = 1;
	vector<string>days(31);
	vector<string>result;

	int n;
	cin >> n;

	for (auto i = 1; i <= n; i++)
	{
		string opertion, s;
		cin >> opertion;
		int a;

		switch (Map[opertion])
		{
		case 1://ADD
			cin >> a;
			cin >> s;
			add(a - 1, s, days);
			break;
		case 2://DUMP
			cin >> a;
			if (a >= 1 && a <= days.size())
				s = dump(a - 1, days);
			result.push_back(count(s) + " " + s);
			break;
		case 3://NEXT
			next_month(current_month, days);
			break;
		}
	}

	for (auto i : result)
		cout << i << endl;
	return 0;
}