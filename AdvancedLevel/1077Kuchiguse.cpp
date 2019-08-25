#include<bits/stdc++.h>
using namespace std;

string kuchiguse(string & s1, string & s2)
{
    string s;
    for (int i = s1.size() - 1, j = s2.size() - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (s1[i] == s2[j])
        {
            s = s1[i] + s;
        }
        else
        {
            break;
        }
    }
    return s;
}

int main()
{
    int N;
    string s1, s2;
    cin >> N;
    getchar();
    getline(cin, s1);
    for (int i = 1; i < N; i++)
    {
        getline(cin, s2);
        s1 = kuchiguse(s1, s2);
    }
    if (s1.empty())
    {
        cout << "nai";
    }
    else
    {
        cout << s1;
    }
    return 0;
}