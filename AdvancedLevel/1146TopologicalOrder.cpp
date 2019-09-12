#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> adjacentList[1001], indegree(1001, 0), res;
    int Nv, Ne, K, u, v;
    cin >> Nv >> Ne;
    for (int i = 1; i <= Ne; i++)
    {
        cin >> u >> v;
        adjacentList[u].push_back(v);
        indegree[v]++;
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        vector<int> _indegree = indegree;
        bool flag = true;
        for (int j = 1; j <= Nv; j++)
        {
            cin >> u;
            if (_indegree[u] != 0)
            {
                flag = false;
            }
            else
            {
                for (int & v : adjacentList[u])
                {
                    _indegree[v]--;
                }
            }
        }
        if (!flag)
        {
            res.push_back(i);
        } 
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << res[i];
    }
    return 0;
}