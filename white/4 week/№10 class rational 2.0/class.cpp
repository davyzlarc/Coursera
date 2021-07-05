#include <iostream>
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
            throw invalid_argument("denominator is null");

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
        throw domain_error("There is zero division");
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
