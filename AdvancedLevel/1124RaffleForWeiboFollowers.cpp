#include<bits/stdc++.h>
using namespace std;

int main()
{
    int M, N, S;
    set<string> winner;
    vector<string> res;
    string str;
    cin >> M >> N >> S;
    for (int i = 1, j = S; i <= M; i++)
    {
        cin >> str;
        if (i == j)
        {
            if (winner.find(str) == winner.end())
            {
                winner.insert(str);
                res.push_back(str);
                j += N;
            }
            else
            {
                j++;
            }
        }
    }
    if (res.empty())
    {
        cout << "Keep going..." << endl;
    }
    else
    {
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << endl;
        }
    }
    return 0;
}