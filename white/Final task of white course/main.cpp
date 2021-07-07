#include <iostream>
#include <set>
#include <map>
#include <sstream>

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

bool operator<(const Date &lhs, const Date &rhs);

class Database
{
public:
    void AddEvent(const Date &date, const string &event);
    bool DeleteEvent(const Date &date, const string &event);
    int DeleteDate(const Date &date);

    /* type (not void) */ void Find(const Date &date) const;

    void Print() const;

private:
    map<Date, set<string>> tuple;
};

int main()
{
    Database db;
   
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