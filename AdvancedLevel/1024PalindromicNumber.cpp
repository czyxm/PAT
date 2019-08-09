#include<iostream>
#include<string>
using namespace std;

bool isPalindromic(const string & s)
{
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}

void doubleStr(string & s)
{
    int digit, carry = 0;
    string _s = s;
    for (int i = s.size() - 1, j = 0; i >= 0; i--, j++)
    {
        digit = (s[i] - '0' + _s[j] - '0') + carry;
        if (digit >= 10)
        {
            digit -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        s[i] = digit + '0';
    }
    if (carry == 1)
    {
        s = "1" + s;
    }
}

int main()
{
    string s;
    int K;
    cin >> s >> K;
    for (int i = 0; i < K; i++)
    {
        if (isPalindromic(s))
        {
            cout << s << endl << i << endl;
            return 0;
        }
        else
        {
            doubleStr(s);
        }
    }
    cout << s << endl << K << endl;
    return 0;
}