#pragma once
#include "RingHeadList.h"
#include <string>

class Monom
{
protected:
    int degree;
    double coeff;
public:
    Monom();
    Monom(int degree, double coeff);
    Monom(const string& s);

    int GetDegree() const;
    double GetCoeff() const;

    bool operator == (const Monom& m) const;
    bool operator != (const Monom& m) const;
    bool operator > (const Monom& m) const;
    bool operator < (const Monom& m) const;
    bool operator >= (const Monom& m) const;
    bool operator <= (const Monom& m) const;

    Monom operator+(const Monom& m);
    Monom operator-(const Monom& m);
    Monom operator*(const Monom& m);

    double operator()(double x, double y, double z) const;

    friend ostream& operator << (ostream& os, const Monom& m)
    {
        if ((m.coeff == 1 || m.coeff == 0) && m.degree == 0)// 1 const, 0 const
        {
            os << m.coeff;
            return os;
        }
        if (m.coeff == 0 && m.degree == -1)//голову не печатаю
        {
            return os;
        }
        if (m.coeff != 1) // чтобы не было 1ху
        {
            if (m.coeff == -1 && m.degree != 0)// чтобы не было -1ху
            {
                os << "-";
            }
            else if (m.coeff != 0)//чтобы 0 не выводилс€ (x + 0 -> x)
            {
                os << m.coeff;
            }
        }
        if (m.degree / 100 != 0)
        {
            if (m.degree / 100 == 1)
            {
                os << "x";
            }
            else
            {
                os << "x^" << m.degree / 100;
            }
        }
        if ((m.degree / 10) % 10 != 0)
        {
            if ((m.degree / 10) % 10 == 1)
            {
                os << "y";
            }
            else
            {
                os << "y^" << (m.degree / 10) % 10;
            }
        }
        if (m.degree % 10 != 0)
        {
            if (m.degree % 10 == 1)
            {
                os << "z";
            }
            else
            {
                os << "z^" << m.degree % 10;
            }
        }
        return os;
    }
};

class Polinom
{
private:
    void insert(Monom& m);
    Monom last_smaller(const Monom target_key); //перемещено в полином

protected:
    string infix;//вид строки - A*x^i*y^j*z^k+B*x^i*y^j*z^k+....
    RingHeadList<Monom> polinom;
public:
    Polinom() : polinom(), infix() {};
    Polinom(const Polinom& p) : polinom(p.polinom), infix(p.infix){};
    Polinom(const string& infix);

    Monom getMonom()const;

    bool operator == (const Polinom& p) const;
    bool operator != (const Polinom& p) const;

    Polinom operator+(const Polinom& p);
    Polinom operator-(const Polinom& p);
    Polinom operator*(const Polinom& p);

    Polinom operator+(const Monom& m);
    Polinom operator-(const Monom& m);
    Polinom operator*(const Monom& m);

    Polinom operator+(double a);
    Polinom operator-(double a);
    Polinom operator*(double a);

    const Polinom& operator = (const Polinom& p);

    double operator()(double x, double y, double z)const;

    friend ostream& operator << (ostream& os, Polinom& p)
    {
        p.polinom.reset();
        if (p.polinom.getCurr() == nullptr)
        {
            os << 0;
            return os;
        }
        while (!(p.polinom.is_ended()))
        {
            os << *(p.polinom.getCurr());
            p.polinom.next();
            if (!(p.polinom.is_ended()))
            {
                if (p.polinom.getCurr()->key.GetCoeff() > 0)
                {
                    os << "+";
                }
            }
        }
        return os;
    }
};