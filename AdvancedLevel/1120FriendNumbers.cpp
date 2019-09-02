#include<bits/stdc++.h>
using namespace std;

int id(const string & str)
{
    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        sum += str[i] - '0';
    }
    return sum;
}

int main()
{
    int N, M = 0, sum;
    bool friendID[37] = {false};
    string str;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        sum = id(str);
        if (!friendID[sum])
        {
            M++;
        }
        friendID[sum] = true;
    }
    cout << M << endl;
    for (int i = 0; i < 37; i++)
    {
        if (friendID[i])
        {
            cout << i;
            if (--M != 0)
            {
                cout << " ";
            }
        }
    }
    cout << endl;
    return 0;
}