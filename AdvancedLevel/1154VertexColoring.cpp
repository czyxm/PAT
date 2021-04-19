#include<bits/stdc++.h> 
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.txt", "r", stdin);
#endif
    int M, N, K, u, v;
    vector< vector<int> > adjacentList;
    vector<int> colors;
    set<int> colorSet;
    cin >> N >> M;
    adjacentList.resize(N);
    colors.resize(N);
    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v;
        adjacentList[u].push_back(v);
    }
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        colorSet.clear();
        for (auto & color : colors)
        {
            cin >> color;
            colorSet.insert(color);
        }
        bool flag = true;
        for (u = 0; u < N; u++)
        {
            for (auto v : adjacentList[u])
            {
                if (colors[u] == colors[v])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << colorSet.size() << "-coloring" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}