#include "Polinom.h"

void calculate_polinom(Polinom& p);

int main()
{
    int flag = 1;
    Polinom curr;
    while (flag != 0)
    {
        switch (flag)
        {
        case 1:
            cout << "Enter polinom:\n";
            {
                string s;
                cin >> s;
                Polinom p(s);
                calculate_polinom(p);
                curr = p;
            }
            break;
        case 2:
            calculate_polinom(curr);
            break;
        default:
            throw "invalid flag";
        }
        cout << "\nEnter another polinom, continue with this one or stop? (2 = this one, 1 = new, 0 = stop)\n";
        cin >> flag;
    }
    return 0;
}

void calculate_polinom(Polinom& p)
{
    cout << "Choose operation:\n(+) sum with const or another polinom\n(-) sub const or another polinom\n(*) mul to const or another polinom\n(#) calculate the value\n";
    char c, c1;
    cin >> c;
    switch (c)
    {
    case '+':
        cout << "const(0) or polinom(1)?\n";
        cin >> c1;
        switch (c1)
        {
        case '0':
            double a;
            cout << "Enter const:\n";
            cin >> a;
            cout << p + a;
            break;
        case '1':
            cout << "Enter second polinom:\n";
            {
                string s1;
                cin >> s1;
                Polinom p1(s1);
                cout << p + p1;
            }
            break;
        default:
            throw "invalid operator";
        }
        break;
    case '-':
        cout << "const(0) or polinom(1)?\n";
        cin >> c1;
        switch (c1)
        {
        case '0':
            double a;
            cout << "Enter const:\n";
            cin >> a;
            cout << p - a;
            break;
        case '1':
            cout << "Enter second polinom:\n";
            {
                string s1;
                cin >> s1;
                Polinom p1(s1);
                cout << p - p1;
            }
            break;
        default:
            throw "invalid operator";
        }
        break;
    case '*':
        cout << "const(0) or polinom(1)?\n";
        cin >> c1;
        switch (c1)
        {
        case '0':
            double a;
            cout << "Enter const:\n";
            cin >> a;
            cout << p * a;
            break;
        case '1':
            cout << "Enter second polinom:\n";
            {
                string s1;
                cin >> s1;
                Polinom p1(s1);
                cout << p * p1;
            }
            break;
        default:
            throw "invalid operator";
        }
        break;
    case '#':
        double x, y, z;
        cout << "Value of x is: ";
        cin >> x;
        cout << "\nValue of y is: ";
        cin >> y;
        cout << "\nValue of z is: ";
        cin >> z;
        cout << "\n" << p(x, y, z);
        break;
    default:
        throw "invalid operator";
    }
}
