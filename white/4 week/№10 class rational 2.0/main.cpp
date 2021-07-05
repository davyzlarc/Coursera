// Вспомним класс Rational, который мы реализовали в задачах, посвящённых перегрузке операторов. Там специально
// говорилось, что в тестах объекты класса Rational никогда не создаются с нулевым знаменателем и никогда не выполняется
// деление на ноль. Настало время избавиться от этого ограничения и научиться обрабатывать нулевой знаменатель и деление
// на ноль. В этой задаче вам предстоит это сделать.

// Поменяйте реализацию конструктора класса Rational так, чтобы он выбрасывал исключение invalid_argument, если знаменатель
// равен нулю. Кроме того, переделайте реализацию оператора деления для класса Rational так, чтобы он выбрасывал
// исключение domain_error, если делитель равен нулю.

// Напомним, что вам надо реализовать интерфейс:

// class Rational {
// public:
//   Rational();
//   Rational(int numerator, int denominator);

//   int Numerator() const;
//   int Denominator() const;
// };

// и оператор деления для класса Rational:

// Rational operator / (const Rational& lhs, const Rational& rhs);

// Так же, как и в задачах на перегрузку операторов, вам будет предложен файл с заготовкой кода. Функция main в этом файле
// содержит ряд юнит-тестов, которые позволят вам проверить свою реализацию. При проверке вашего решения оно будет
// тестироваться на более полном наборе тестов, так что успешное прохождение всех юнит-тестов не гарантирует, что ваша
// реализация будет зачтена.

#include <iostream>
#include "class.cpp"

using namespace std;

int main()
{
    try
    {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    }
    catch (invalid_argument & error)
    {
        //cout << error.what() << endl;
    }

    try
    {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error &)
    {
    }

    cout << "OK" << endl;
    return 0;
}