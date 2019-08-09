#include<iostream>
#include<string>
using namespace std;

bool equal(string s1, string s2)
{
    int i, j;
    if (s1.size() != s2.size())
    {
        return false;
    }
    for (i = 0; i < s1.size(); i++)
    {
        for (j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                s2[j] = '-';
                break;
            }
        }
        if (j >= s2.size())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s1, s2;
    int digit, carry = 0;
    cin >> s1;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        digit = (s1[i] - '0') * 2 + carry;
        if (digit >= 10)
        {
            digit -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        s2 = to_string(digit) + s2;
    }
    if (carry == 1)
    {
        s2 = "1" + s2;
    }
    if (carry != 0 || !equal(s1, s2))
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    cout << s2 << endl;
    return 0;
}