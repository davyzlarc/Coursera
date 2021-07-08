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
    // Return value: "Deleted successfully", "Event not found"
    string DeleteEvent(const Date &date, const string &event)
    {
        if (tuple.count(date) != 0 && tuple.at(date).count(event) != 0)
        {
            if (tuple.at(date).size() > 1)
                tuple.at(date).erase(event);
            else
                DeleteDate(date);
            return "Deleted successfully";
        }
        else
            return "Event not found";
    }

    // Удаление даты - date и всех событий в эту дату.
    // Return value: N>=0
    int DeleteDate(const Date &date)
    {
        if (tuple.count(date) != 0)
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
        if (tuple.count(date) != 0)
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
                     << setw(2) << setfill('0') << key.GetMonth() << "-"
                     << setw(2) << setfill('0') << key.GetDay() << " "
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
    stringstream output;

    try
    {
        string command;
        while (getline(cin, command))
        {
            stringstream ss;
            ss << command;

            string operation;
            ss >> operation;
            if (operation == "Add")
            {
                string date, event;
                ss >> date >> event;

                db.AddEvent(Date(date), event);
            }
            else if (operation == "Del")
            {
                string date, event;
                ss >> date;

                if (ss >> event)
                    cout << db.DeleteEvent(Date(date), event) << endl;
                else
                    cout << "Deleted " << db.DeleteDate(Date(date)) << " events" << endl;
            }
            else if (operation == "Find")
            {
                string date;
                ss >> date;

                for (const auto &item : db.Find(date))
                    cout << item << endl;
            }
            else if (operation == "Print")
            {
                db.Print();
            }
            else if (operation != "")
                throw runtime_error("Unknown command: " + operation);
        }
    }
    catch (exception &ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}