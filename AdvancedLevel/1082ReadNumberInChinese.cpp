#include<bits/stdc++.h>
using namespace std;

bool isStart = false, isPrint = false;
string grade[5] = {" Shi", " Bai", " Qian", " Wan", " Yi"};
string numStr[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

void display(int num)
{
    string str = to_string(num);
    if (isStart)
    {
        str = string(4 - str.size(), '0') + str;
    }
    else
    {
        isStart = true;
        str = string(4 - str.size(), '-') + str;
    }
    bool hasReadZero = true;
    for (int i = 0; i < 4; i++)
    {
        if (str[i] == '0')
        {
            hasReadZero = false;
        }
        else if ('1' <= str[i] && str[i] <= '9')
        {
            if (!hasReadZero)
            {
                cout << " ling";
                hasReadZero = true;
            }
            if (isPrint)
            {
                cout << " ";
            }
            else
            {
                isPrint = true;
            }
            cout << numStr[str[i] - '0'];
            if (i < 3)
            {
                cout << grade[2 - i];
            }
        }
    }
}

int main()
{
    int number, digit;
    string res, digitStr;
    cin >> number;
    if (number == 0)
    {
        cout << "ling";
        return 0;
    }
    if (number < 0)
    {
        cout << "Fu ";
        number = -number;
    }
    if (number >= 100000000)
    {
        digit = number / 100000000;
        number %= 100000000;
        cout << numStr[digit] << grade[4];
        isStart = isPrint = true;
    }
    if (number >= 10000)
    {
        digit = number / 10000;
        number %= 10000;
        display(digit);
        cout << grade[3];
    }
    if (number > 0)
    {
        display(number);
    }
    return 0;
}