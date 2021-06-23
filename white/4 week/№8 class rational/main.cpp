// Общее описание
//
// В этой задаче вам надо разработать класс для представления рациональных чисел и внедрить его в систему типов 
// языка С++ так, чтобы им можно было пользоваться естественным образом. Задание состоит из нескольких частей. 
// К каждой части приложен файл с заготовкой программы, который имеет следующую структуру:

// #include <iostream>
// using namespace std;
//
// /*Комментарии, которые говорят, что именно нужно реализовать в этой программе*/
//
// int main() {
//     /*Набор юнит-тестов для вашей реализации*/
//     cout << "OK" << endl;
//     return 0;
// }

// Вам нужно, не меняя тело функции main, реализовать то, что предложено в комментариях, так, чтобы ваша программа
// выводила на экран сообщение OK. Функция main содержит ряд юнит-тестов, которые проверяют правильность вашей
// реализации. Если эти тесты находят ошибку в вашей реализации, то вместо OK программа выведет подсказку о том, что 
// именно работает неправильно.
// Когда ваша программа начнёт выводить OK, можете отправлять свой файл на проверку. Ваша реализация будет тестироваться 
// на другом, более полном наборе тестов. То есть, если ваша программа выводит OK, то это не даёт гарантии, что ваша
// реализация будет принята тестирующей системой. В случае неудачной посылки тестирующая система также выдаст вам 
// подсказку о том, какая именно часть реализации работает неправильно.
// Внимательно изучите набор юнит-тестов для каждой заготовки решения. Тесты описывают требования, предъявляемые к вашей 
// реализации, которые могут быть не указаны в условии задач
// На проверку можно отправлять весь файл с вашей реализацией: функцию main удалять из него не нужно.
//
// Часть 1
//
// В первой части Вам надо реализовать класс Rational, который представляет собой рациональное число вида p/q, 
// где p — целое, а q — натуральное и диапазоны возможных значений p, q таковы, что могут быть представлены
// типом int. При этом, класс Rational должен иметь следующий интерфейс:

// class Rational {
// public:
//   Rational();
//   Rational(int numerator, int denominator);
//
//   int Numerator() const;
//   int Denominator() const;
// };

// Класс Rational должен гарантировать, что p/q — это несократимая дробь. Например, код:

// Rational r(4, 6);
// cout << r.Numerator() << '/' << r.Denominator();

// должен выводить «2/3» — именно поэтому мы делаем Rational классом, а не структурой. Структура
// позволила бы нарушить этот инвариант:  

// struct Rational {
//     int numerator, denominator;
// };
//
// Rational r{2, 3};
// r.numerator = 6; // Нарушен инвариант несократимости

// Список требований, предъявляемых к реализации интерфейса класса Rational:
// Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1.
// При конструировании объека класса Rational с параметрами p и q должно выполняться сокращение дроби p/q
// (здесь вам может пригодиться решение задачи «Наибольший общий делитель»).
// Если дробь p/q отрицательная, то объект Rational(p, q) должен иметь отрицательный числитель и положительный знаменатель.
// Если дробь p/q положительная, то объект Rational(p, q) должен иметь положительные числитель и знаменатель 
// (обратите внимание на случай Rational(-2, -3)).
// Если числитель дроби равен нулю, то знаменатель должен быть равен 1.
// Гарантируется, что ни в одном из тестов, на которых будет тестироваться ваша реализация, не будет знаменателя, равного нулю.

// Замечание:
// В стандарте языка C++17 для вычисления НОД имеется стандартная функция gcd. Допустимо использовать данную функцию для 
// сокращения дробей. Подробнее с данной функцией и её ограничениями можно ознакомиться по 
// ссылке: https://en.cppreference.com/w/cpp/numeric/gcd
//
// Часть 2:
//
// Реализуйте для класса Rational операторы ==, + и - так, чтобы операции с дробями можно было записывать естественным 
// образом. Например, следующий код должен быть валидным:  

// const Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
// if (r == Rational(7, 12)) {
//   cout << "equal";
// }

// Гарантируется, что во всех тестах, на которых будет тестироваться ваша реализация, числители и знаменатели ВСЕХ дробей
// (как исходных, так и получившихся в результате соответствующих арифметических операций) будут укладываться в 
// диапазон типа int.
//
// Часть 3:
//
// Аналогично предыдущей части, реализуйте операторы * и /. Например, следующий код должен быть валидным: 
 
// const Rational r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
// if (r == Rational(2, 3)) {
//   cout << "equal";
// }

// Как и в предыдущем случае, гарантируется, что во всех тестах, на которых будет тестироваться ваша реализация, числители 
// и знаменатели ВСЕХ дробей (как исходных, так и получившихся в результате соответствующих арифметических операций) будут 
// укладываться в диапазон типа int.
//
// Кроме того, гарантируется, что ни в одном из тестов, на которых будет тестироваться ваша реализация, не будет выполняться 
// деление на ноль.
//
// Часть 4:
//
// В этой части вам нужно реализовать операторы ввода и вывода для класса Rational. В результате у вас должен 
// работать, например, такой код:  

// Rational r;
// cin >> r;
// cout << r;

// Часть 5:
//
// Наконец, вам нужно реализовать возможность использовать объекты класса Rational в качестве элементов
// контейнера set и ключей в контейнере map. Пример:

// set<Rational> rationals;
// rationals.insert(Rational(1, 2));
// rationals.insert(Rational(1, 3));

// map<Rational, string> name;
// name[Rational(1, 2)] = "одна вторая";

#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <set>
#include <map>

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

int main()
{
    {
        {
            const Rational r(3, 10);
            if (r.Numerator() != 3 || r.Denominator() != 10)
            {
                cout << "Rational(3, 10) != 3/10" << endl;
                return 101;
            }
        }

        {
            const Rational r(8, 12);
            if (r.Numerator() != 2 || r.Denominator() != 3)
            {
                cout << "Rational(8, 12) != 2/3" << endl;
                return 102;
            }
        }

        {
            const Rational r(-4, 6);
            if (r.Numerator() != -2 || r.Denominator() != 3)
            {
                cout << "Rational(-4, 6) != -2/3" << endl;
                return 103;
            }
        }

        {
            const Rational r(0, 15);
            if (r.Numerator() != 0 || r.Denominator() != 1)
            {
                cout << "Rational(0, 15) != 0/1" << endl;
                return 104;
            }
        }

        {
            const Rational defaultConstructed;
            if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1)
            {
                cout << "Rational() != 0/1" << endl;
                return 105;
            }
        }

        cout << "OK" << endl;
    }

    {
        {
            Rational r1(4, 6);
            Rational r2(2, 3);
            bool equal = r1 == r2;
            if (!equal)
            {
                cout << "4/6 != 2/3" << endl;
                return 201;
            }
        }

        {
            Rational a(2, 3);
            Rational b(4, 3);
            Rational c = a + b;
            bool equal = c == Rational(2, 1);
            if (!equal)
            {
                cout << "2/3 + 4/3 != 2" << endl;
                return 202;
            }
        }

        {
            Rational a(5, 7);
            Rational b(2, 9);
            Rational c = a - b;
            bool equal = c == Rational(31, 63);
            if (!equal)
            {
                cout << "5/7 - 2/9 != 31/63" << endl;
                return 203;
            }
        }

        cout << "OK" << endl;
    }

    {
        {
            Rational a(2, 3);
            Rational b(4, 3);
            Rational c = a * b;
            bool equal = c == Rational(8, 9);
            if (!equal)
            {
                cout << "2/3 * 4/3 != 8/9" << endl;
                return 301;
            }
        }

        {
            Rational a(5, 4);
            Rational b(15, 8);
            Rational c = a / b;
            bool equal = c == Rational(2, 3);
            if (!equal)
            {
                cout << "5/4 / 15/8 != 2/3" << endl;
                return 302;
            }
        }

        cout << "OK" << endl;
    }

    {
        {
            ostringstream output;
            output << Rational(-6, 8);
            if (output.str() != "-3/4")
            {
                cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
                return 401;
            }
        }

        {
            istringstream input("5/7");
            Rational r;
            input >> r;
            bool equal = r == Rational(5, 7);
            if (!equal)
            {
                cout << "5/7 is incorrectly read as " << r << endl;
                return 402;
            }
        }

        {
            istringstream input("");
            Rational r;
            bool correct = !(input >> r);
            if (!correct)
            {
                cout << "Read from empty stream works incorrectly" << endl;
                return 403;
            }
        }

        {
            istringstream input("5/7 10/8");
            Rational r1, r2;
            input >> r1 >> r2;
            bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct)
            {
                cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
                return 404;
            }

            input >> r1;
            input >> r2;
            correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct)
            {
                cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
                return 405;
            }
        }

        {
            istringstream input1("1*2"), input2("1/"), input3("/4");
            Rational r1, r2, r3;
            input1 >> r1;
            input2 >> r2;
            input3 >> r3;
            bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
            if (!correct)
            {
                cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                     << r1 << " " << r2 << " " << r3 << endl;

                return 406;
            }
        }

        cout << "OK" << endl;
    }

    {
        {
            const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
            if (rs.size() != 3)
            {
                cout << "Wrong amount of items in the set" << endl;
                return 1;
            }

            vector<Rational> v;
            for (auto x : rs)
            {
                v.push_back(x);
            }
            if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}})
            {
                cout << "Rationals comparison works incorrectly" << endl;
                return 2;
            }
        }

        {
            map<Rational, int> count;
            ++count[{1, 2}];
            ++count[{1, 2}];

            ++count[{2, 3}];

            if (count.size() != 2)
            {
                cout << "Wrong amount of items in the map" << endl;
                return 3;
            }
        }

        cout << "OK" << endl;
    }

    return 0;
}