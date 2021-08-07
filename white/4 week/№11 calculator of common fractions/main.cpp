// Итак, теперь у нас с вами есть полноценный тип для представления  обыкновенных дробей: класс Rational интегрирован
// в язык с помощью  перегрузки операторов и не позволяет выполнять некорректные операции за  счёт выбрасывания
// исключений. Давайте на основе класса Rational создадим  простой калькулятор для обыкновенных дробей.

// Вам надо написать программу, которая считывает из стандартного ввода одну строку в формате ДРОБЬ_1 операция
// ДРОБЬ_2.  ДРОБЬ_1 и ДРОБЬ_2 имеют формат X/Y, где X — целое, а Y — целое неотрицательное число. операция — это один
// из символов '+', '-', '*', '/'.

// Если ДРОБЬ_1 или ДРОБЬ_2 является  некорректной обыкновенной дробью, ваша программа должна вывести в  стандартный
// вывод сообщение "Invalid argument". Если считанная операция — это деление на ноль,  выведите в стандартный вывод
// сообщение  "Division by zero". В противном случае выведите результат операции.

// Пример:
// stdin	    stdout
// 1/2 + 1/3	5/6
// 1/2 + 5/0	Invalid argument
// 4/5 / 0/8	Division by zero

#include <iostream>
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

class Rational
{
public:
    Rational()
    {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator)
    {
        if (denominator == 0)
            throw invalid_argument("Invalid argument");

        p = numerator;
        q = denominator;

        if (p == 0)
            q = 1;
        else
        {
            if (q < 0)
            {
                p *= -1;
                q *= -1;
            }
            int a = gcd(p, q);
            if (a != 1)
            {
                p /= a;
                q /= a;
            }
        }
    }

    int Numerator() const
    {
        return p;
    }

    int Denominator() const
    {
        return q;
    }

private:
    int p,
        q;
};

bool operator==(const Rational &lhs, const Rational &rhs)
{
    if (lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator())
        return true;
    else
        return false;
}

Rational operator+(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs)
{
    if (lhs.Denominator() * rhs.Numerator() == 0)
        throw domain_error("Division by zero");
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

istream &operator>>(istream &stream, Rational &rational)
{
    int p = 0, q = 1;
    char ch;
    if (!(stream >> p) || !(stream >> ch) || !(stream >> q) || (ch != '/'))
        return stream;
    else
    {
        rational = Rational(p, q);
        return stream;
    }
}

ostream &operator<<(ostream &stream, const Rational &rational)
{
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

bool operator<(const Rational &lhs, const Rational &rhs)
{
    return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}

Rational ExecuteRational(const string &f1)
{
    stringstream ss;
    ss << f1;

    int p, q;
    char ch;
    if (ss >> p and ss >> ch and ss >> q)
        return Rational(p, q);
    else
        throw runtime_error("Invalid argument");
}

Rational CountOperation(const string &f1, const string &f2, const char &op)
{
    switch (op)
    {
    case '+':
        return ExecuteRational(f1) + ExecuteRational(f2);
        break;
    case '-':
        return ExecuteRational(f1) - ExecuteRational(f2);
        break;
    case '*':
        return ExecuteRational(f1) * ExecuteRational(f2);
        break;
    case '/':
        return ExecuteRational(f1) / ExecuteRational(f2);
        break;
    default:
        throw runtime_error("Invalid operation");
        break;
    }
}

int main()
{
    string frac1, frac2;
    char operation;
    cin >> frac1 >> operation >> frac2;

    try
    {
        cout << CountOperation(frac1, frac2, operation);
    }
    catch (exception &ex)
    {
        cout << ex.what();
    }

    return 0;
}