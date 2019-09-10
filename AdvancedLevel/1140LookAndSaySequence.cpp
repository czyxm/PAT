#include<bits/stdc++.h>
using namespace std;

string lookAndSay(const string & str)
{
    string _str;
    int count = 0;
    char _ch = str.front();
    for (char ch : str)
    {
        if (_ch == ch)
        {
            count++;
        }
        else
        {
            _str += _ch + to_string(count);
            _ch = ch;
            count = 1;
        }
    }
    _str += _ch + to_string(count);
    return _str;
}

int main()
{
    int D, N;
    string str, DStr;
    cin >> DStr >> N;
    while (N > 1)
    {
        DStr = lookAndSay(DStr);
        N--;
    }
    cout << DStr;
    return 0;
}