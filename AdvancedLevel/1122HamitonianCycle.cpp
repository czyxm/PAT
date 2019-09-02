#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, n, u, v, adjacent[201][201];
    vector<int> degree(201, 0);
    cin >> N >> M;
    for (int i = 1; i <= 200; i++)
    {
        degree[i] = 0;
        for (int j = 1; j <= 200; j++)
        {
            adjacent[i][j] = 0;
        }
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v;
        adjacent[u][v] = adjacent[v][u] = 1;
    }
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        bool flag = true;
        for (int j = 1; j <= N; j++)
        {
            degree[j] = 0;
        }
        cin >> n >> u;
        if (n != N + 1)
        {
            flag = false;
        }
        for (int i = 1; i < n; i++)
        {
            cin >> v;
            if (adjacent[u][v] == 1)
            {
                degree[u]++;
                degree[v]++;
            }
            else
            {
                flag = false;
            }
            u = v;
        }
        if (flag)
        {
            for (int j = 1; j <= N; j++)
            {
                if (degree[j] != 2)
                {
                    flag = false;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}