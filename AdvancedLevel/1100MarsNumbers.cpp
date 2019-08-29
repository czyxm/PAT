#include<bits/stdc++.h>
using namespace std;

string digit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string _digit[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int findIn_Digit(string str)
{
    for (int i = 0; i < 13; i++)
    {
        if (_digit[i] == str)
        {
            return 13 * i;
        }
    }
    return -1;
}

int findInDigit(string str)
{
    for (int i = 0; i < 13; i++)
    {
        if (digit[i] == str)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    
    int N, num;
    string str, str1, str2;
    cin >> N;
    getchar();
    for (int i = 1; i <= N; i++)
    {
        getline(cin, str);
        if ('0' <= str[0] && str[0] <= '9')
        {
            num = stoi(str);
            if (num / 13 > 0)
            {
                str = _digit[num / 13];
                if (num % 13 > 0)
                {
                    str += " " + digit[num % 13];
                }
            }
            else
            {
                str = digit[num % 13];
            }
            cout << str << endl;
        }
        else
        {
            if (str.size() <= 4)
            {
                num = findInDigit(str);
                if (num == -1)
                {
                    num = findIn_Digit(str);
                }
            }
            else
            {
                num = findIn_Digit(str.substr(0, 3)) + findInDigit(str.substr(4));
            }
            cout << num << endl;
        }
    }
    return 0;
}