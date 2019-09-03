#include<bits/stdc++.h>
using namespace std;

bool isQueen(vector<int> & Q)
{
    for (int i = 2; i < Q.size(); i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (Q[j] == Q[i] || abs(Q[i] - Q[j]) == i - j)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int K, N;
    vector<int> Q;
    cin >> K;
    while (K > 0)
    {
        K--;
        cin >> N;
        Q.resize(N + 1);
        for (int i = 1; i <= N; i++)
        {
            cin >> Q[i];
        }
        if (isQueen(Q))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
        Q.clear();
    }
    return 0;
}