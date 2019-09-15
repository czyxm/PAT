#include<bits/stdc++.h>
using namespace std;

vector<int> adjacent[10000];

int main()
{
    int Nv, Ne, K, u, v;
    cin >> Nv >> Ne;
    for (int i = 1; i <= Ne; i++)
    {
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        vector<int> vertexColor(Nv, -1);
        set<int> res;
        bool flag = true;
        for (u = 0; u < Nv; u++)
        {
            cin >> vertexColor[u];
            for (int w : adjacent[u])
            {
                if (vertexColor[u] == vertexColor[w])
                {
                    flag = false;
                }
            }
            res.insert(vertexColor[u]);
        }
        if (flag)
        {
            cout << res.size() << "-coloring" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}