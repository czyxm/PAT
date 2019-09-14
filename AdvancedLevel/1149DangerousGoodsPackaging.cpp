#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > adjacentList;

int main()
{
    int N, M, K, u, v;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> u >> v;
        adjacentList[u].push_back(v);
        adjacentList[v].push_back(u);
    }
    for (int i = 1; i <= M; i++)
    {
        bool flag = true;
        set<int> blackList;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> u;
            if (flag)
            {
                if (blackList.find(u) == blackList.end())
                {
                    for (int & v : adjacentList[u])
                    {
                        blackList.insert(v);
                    }
                }
                else
                {
                    flag = false;
                }
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}