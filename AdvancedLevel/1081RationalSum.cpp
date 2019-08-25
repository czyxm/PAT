#include<bits/stdc++.h>
using namespace std;

struct Fraction
{
    long long numerator, denominater;
};

Fraction sum(Fraction & num1, Fraction & num2)
{
    Fraction num;
    num.denominater = num1.denominater * num2.denominater;
    num.numerator = num1.numerator * num2.denominater + num2.numerator * num1.denominater;
    return num;
}

long long gcd(long long num1, long long num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    return gcd(num2, num1 % num2);
}

int main()
{
    int N;
    long long integer = 0, divisor = 1;
    Fraction num1, num2;
    char devide;
    cin >> N >> num1.numerator >> devide >> num1.denominater;
    for (int i = 1; i <= N -1; i++)
    {
        cin >> num2.numerator >> devide >> num2.denominater;
        num1 = sum(num1, num2);
    }
    int sign = num1.numerator >= 0 ? 1 : -1;
    num1.numerator = abs(num1.numerator);
    if (num1.numerator > 0)
    {
        if (num1.numerator >= num1.denominater)
        {
            integer = num1.numerator / num1.denominater * sign;
            num1.numerator %= num1.denominater;
        }
        else
        {
            integer = 0;
        }
        divisor = gcd(num1.denominater, num1.numerator);
        num1.numerator /= divisor;
        num1.denominater /= divisor;
        num1.numerator *= sign;
    }
    if (integer != 0 && num1.numerator != 0)
    {
        cout << integer << " " << num1.numerator << devide << num1.denominater;
    }
    else if (integer != 0)
    {
        cout << integer;
    }
    else if (num1.numerator != 0)
    {
        cout << num1.numerator << devide << num1.denominater;
    }
    else
    {
        cout << 0;
    }
    return 0;
}