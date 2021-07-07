#include <iostream>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Date
{
public:
    Date(const string &s)
    {
        stringstream ss;
        ss << s;
        char ch;
        if (!(ss >> Year and ss >> ch and ch == '-' and ss >> Month and ss >> ch and ch == '-' and ss >> Day))
            throw invalid_argument("Wrong date format: " + s);
        else
        {
            if (!(Month >= 0 and Month <= 12))
                throw invalid_argument("Month value is invalid: " + to_string(Month));
            else if (!(Day >= 1 and Day <= 31))
                throw invalid_argument("Day value is invalid: " + to_string(Day));
        }
    }

    int GetYear() const
    {
        return Year;
    }
    int GetMonth() const
    {
        return Month;
    }
    int GetDay() const
    {
        return Day;
    }

private:
    int Day;
    int Month;
    int Year;
};

bool operator<(const Date &lhs, const Date &rhs)
{
    if (lhs.GetYear() != rhs.GetYear())
        return lhs.GetYear() < rhs.GetYear();
    else
    {
        if (lhs.GetMonth() != rhs.GetMonth())
            return lhs.GetMonth() < rhs.GetMonth();
        else
            return lhs.GetDay() < rhs.GetDay();
    }
}

// База данных событий
class Database
{
public:
    // Добавление события - event в дату - date
    void AddEvent(const Date &date, const string &event)
    {
        tuple[date].insert(event);
    }

    // Удаление события - event в дату - date.
    // Return value: true - "Deleted successfully", false - "Event not found"
    bool DeleteEvent(const Date &date, const string &event)
    {
        if (tuple.contains(date) && tuple.at(date).contains(event))
        {
            if (tuple.at(date).size() > 1)
                tuple.at(date).erase(event);
            else
                DeleteDate(date);
            return true;
        }
        else
            return false;
    }

    // Удаление даты - date и всех событий в эту дату.
    // Return value: N>=0 - "Deleted N events",
    int DeleteDate(const Date &date)
    {
        if (tuple.contains(date))
        {
            int num = tuple.at(date).size();
            tuple.erase(date);
            return num;
        }
        else
            return 0;
    }

    // Поиск собыйтий в указанную дату - date
    // Return value: set<string> events, empty set<string>
    set<string> Find(const Date &date) const
    {
        if (tuple.contains(date))
            return tuple.at(date);
        else
            return set<string>();
    }

    // Вывод всех дат - date и соответствующих им событий - event
    void Print() const
    {
        for (const auto &[key, value] : tuple)
        {
            for (const auto &item : value)
                cout << setw(4) << setfill('0') << key.GetYear() << "-"
                     << key.GetMonth() << "-"
                     << key.GetDay() << " "
                     << item << endl;
        }
    }

private:
    // Кортёж дата-события
    map<Date, set<string>> tuple;
};

int main()
{
    Database db;
    // db.AddEvent(Date("10-10-10"), "qq");
    // db.AddEvent(Date("10-10-10"), "qw");
    // db.AddEvent(Date("10-10-10"), "фq");
    // db.AddEvent(Date("0-10-10"), "qq");
    // db.AddEvent(Date("1-10-10"), "ф");
    // db.AddEvent(Date("1-10-10"), "аа");
    // db.AddEvent(Date("10-0-10"), "и");
    // db.AddEvent(Date("10-10-10"), "с");
    // db.AddEvent(Date("10-10-10"), "н");
    // db.Print();
    // cout << endl;
    // db.DeleteEvent(Date("10-10-10"), "qe");
    // db.DeleteEvent(Date("10-5-10"), "qe");
    // db.DeleteEvent(Date("10-10-10"), "qw");
    // db.DeleteEvent(Date("10-10-10"), "qq");
    // db.Print(); 
    
    // try{
    // Date d("");
    // }
    // catch(exception &ex)
    // {
    //     cout << ex.what();
    // }

    string command;
    while (getline(cin, command))
    {
        // ...
    }

    return 0;
}