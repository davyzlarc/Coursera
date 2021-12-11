//Класс Rational представляет собой рациональное число и имеет следующий интерфейс:
//class Rational {
//public:
//	Rational();
//	Rational(int numerator, int denominator);
//
//	int Numerator() const;
//	int Denominator() const;
//};
// 
//Список требований, предъявляемых к реализации интерфейса класса Rational :
//		Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1.
//		При конструировании объекта класса Rational с параметрами p и q должно выполняться
//  сокращение дроби p / q.
//		Если дробь p / q отрицательная, то объект Rational(p, q) должен иметь отрицательный 
//	числитель и положительный знаменатель.
//		Если дробь p / q положительная, то объект Rational(p, q) должен иметь положительные 
//	числитель и знаменатель(обратите внимание на случай Rational(-2, -3)).
//		Если числитель дроби равен нулю, то знаменатель должен быть равен 1.
//		Разработайте набор юнит - тестов, которые будут проверять корректность реализации класса 
//	Rational. Тестировать случай, когда знаменатель равен нулю, не надо.
//
//Начать работу вы можете с шаблона, который содержит наш фреймворк юнит - тестов и заготовку 
//класса Rational - test_rational.cpp.
// 
//Примечание:
//Перед отправкой вашего файла убедитесь, что он не содержит класса Rational. В противном случае 
//вы получите ошибку компиляции. Наша тестирующая система умеет игнорировать функции в файлах
//(поэтому, например, в задаче "Тесты для функции IsPalindrom" необязательно удалять функцию IsPalindrom),
//но не умеет это делать для классов.

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

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

bool operator==(const Rational& lhs, const Rational& rhs)
{
    if (lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator())
        return true;
    else
        return false;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator());
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

istream& operator>>(istream& stream, Rational& rational)
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

ostream& operator<<(ostream& stream, const Rational& rational)
{
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs)
{
    return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}

void TestDefaultConstructor()
{
    Rational r;

    AssertEqual(r.Numerator(), 0, "Wrong numenator");
    AssertEqual(r.Denominator(), 1, "Wrong denominator");
}

void TestReduction()
{
    Rational r(12,24);

    AssertEqual(r.Numerator(), 1, "Wrong numenator");
    AssertEqual(r.Denominator(), 2, "Wrong denominator");
}

void TestNegative()
{
    Rational r(5, -7);

    AssertEqual(r.Numerator(), -5, "Wrong numenator");
    AssertEqual(r.Denominator(), 7, "Wrong denominator");
}

void TestPositive()
{
    Rational r(-5, -7);

    AssertEqual(r.Numerator(), 5, "Wrong numenator");
    AssertEqual(r.Denominator(), 7, "Wrong denominator");
}

void TestZero()
{
    Rational r(0, 7);

    AssertEqual(r.Numerator(), 0, "Wrong numenator");
    AssertEqual(r.Denominator(), 1, "Wrong denominator");
}

int main() {
    TestRunner runner;
    runner.RunTest(TestDefaultConstructor,"Test of default constructor (0/1)");
    runner.RunTest(TestReduction, "Test of reduction of fraction (12/24)");
    runner.RunTest(TestNegative, "Test of negative fraction (5/-7)");
    runner.RunTest(TestPositive, "Test of positive fraction (-5/-7)");
    runner.RunTest(TestZero, "Test of zero fraction (0/7)");

    return 0;
}
