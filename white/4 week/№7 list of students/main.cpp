// Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения. Создайте
// вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля. Чтение
// и запись данных в этой задаче производится с использованием стандартных потоков.
//
// Формат ввода:
// Первая строка содержит одно целое число N от 0 до 10000 — число студентов.
// Далее идут N строк, каждая из которых содержит две строки длиной от 1 до 15 символов — имя и фамилию
// очередного студента, и три целых числа от 0 до 1000000000 — день, месяц и год рождения.
// Следующая строка содержит одно целое число M от 0 до 10000 — число запросов.
// Следующие M строк содержат строку длиной от 1 до 15 символов — запрос, и целое число от 1 до 1000000000 — номер
// студента (нумерация начинается с 1).
//
// Формат вывода:
// Для запроса вида name K, где K от 1 до N, выведите через пробел имя и фамилию K-го студента.
// Для запроса вида date K, где K от 1 до N, выведите через точку день, месяц и год рождения K-го студента.
// Для остальных запросов выведите bad request.
// NB: неверные запросы могут выходить за границы, указанные для данных.

// Пример ввода:
// 3
// Ivan Ivanov 1 1 1901
// Petr Petrox 2 2 1902
// Alexander Sidorov 3 3 1903
// 3
// name 1
// date 3
// mark 5
//
// Пример вывода:
// Ivan Ivanov
// 3.3.1903
// bad request

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date
{
    int Day,
        Month,
        Year;
};

struct Student
{
    string First_name,
        Last_name;
    Date Birth_date;
};

int main()
{
    int num_students;
    cin >> num_students;
    vector<Student> students(num_students);

    for (auto &item : students)
    {
        string s;
        int m;

        cin >> s;
        item.First_name = s;

        cin >> s;
        item.Last_name = s;

        cin >> m;
        item.Birth_date.Day = m;

        cin >> m;
        item.Birth_date.Month = m;

        cin >> m;
        item.Birth_date.Year = m;
    }

    int requests;
    cin >> requests;
    
    for (auto item = 0; item < requests; ++item)
    {
        string operation;
        int K;
        cin >> operation >> K;
        K--;

        if (K >= 0 && K < num_students)
        {
            if (operation == "name")
                cout << students.at(K).First_name << " " << students.at(K).Last_name << endl;
            else if (operation == "date")
                cout << students.at(K).Birth_date.Day << "." << students.at(K).Birth_date.Month  << "." << 
                students.at(K).Birth_date.Year<<endl; 
            else
                cout << "bad request"<<endl;
        }
        else
            cout << "bad request"<<endl;
    }
    return 0;
}