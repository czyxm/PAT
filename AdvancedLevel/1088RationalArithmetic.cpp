#include<bits/stdc++.h>
using namespace std;

struct Fraction
{
    long int integer, numerator, denominator;
};

long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void reduction(Fraction & num)
{
    long sign = 1, factor;
    if (num.numerator < 0)
    {
        sign = -1;
        num.numerator = -num.numerator;
    }
    if (num.denominator > 0)
    {
        num.integer = num.numerator / num.denominator;
        num.numerator %= num.denominator;
    }
    if (num.numerator != 0 && num.denominator != 0)
    {
        factor = gcd(num.numerator, num.denominator);
        num.numerator /= factor;
        num.denominator /= factor;
    }
    num.integer *= sign;
    num.numerator *= sign;
}

Fraction arithmetic(Fraction & num1, Fraction & num2, char op)
{
    Fraction num;
    switch (op)
    {
        case '+' :
            num.denominator = num1.denominator * num2.denominator;
            num.numerator = num1.numerator * num2.denominator + num2.numerator * num1.denominator;
            break;
        case '-' :
            num.denominator = num1.denominator * num2.denominator;
            num.numerator = num1.numerator * num2.denominator - num2.numerator * num1.denominator;
            break;
        case '*' : 
            num.denominator = num1.denominator * num2.denominator;
            num.numerator = num1.numerator * num2.numerator;
            break;
        case '/' :
            num.denominator = num1.denominator * abs(num2.numerator);
            num.numerator = abs(num1.numerator) * num2.denominator;
            if (num1.numerator * num2.numerator < 0)
            {
                num.numerator *= -1;
            }
            break;
    }
    reduction(num);
    return num;
}

void display(Fraction & num)
{
    if (num.denominator == 0)
    {
        cout << "Inf";
    }
    else if (num.integer != 0 && num.numerator != 0)
    {
        if (num.integer < 0)
        {
            cout << "(" << num.integer << " " << -num.numerator << "/" << num.denominator << ")";
        }
        else
        {
            cout << num.integer << " " << num.numerator << "/" << num.denominator;
        }
    }
    else if (num.integer != 0)
    {
        if (num.integer < 0)
        {
            cout << "(" << num.integer << ")";
        }
        else
        {
            cout << num.integer;
        }
    }
    else if (num.numerator != 0)
    {
        if (num.numerator < 0)
        {
            cout << "(" << num.numerator << "/" << num.denominator << ")";
        }
        else
        {
            cout << num.numerator << "/" << num.denominator;
        }
    }
    else
    {
        cout << "0";
    }
}

int main()
{
    Fraction num, num1, num2, _num1, _num2;
    char op[4] = {'+', '-', '*', '/'};
    char devide;
    cin >> num1.numerator >> devide >> num1.denominator >> num2.numerator >> devide >> num2.denominator;
    _num1.numerator = num1.numerator;
    _num1.denominator = num1.denominator;
    _num2.numerator = num2.numerator;
    _num2.denominator = num2.denominator;
    reduction(_num1);
    reduction(_num2);
    for (int i = 0; i < 4; i++)
    {
        num = arithmetic(num1, num2, op[i]);
        display(_num1);
        cout << " " << op[i] << " ";
        display(_num2);
        cout << " = ";
        display(num);
        cout << endl;
    }
    return 0;
}