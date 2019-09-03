#include<bits/stdc++.h>
using namespace std;

int N, M;
bool known[501] = {false};
int degree[501] = {0};
vector<int> adjacentList[501];

void DFS(int u)
{
    known[u] = true;
    for (int i = 0; i < adjacentList[u].size(); i++)
    {
        if (!known[adjacentList[u][i]])
        {
            DFS(adjacentList[u][i]);
        }
    }
}

int main()
{
    int u, v, oddDegreeNum = 0;
    bool isConnective = true;
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v;
        adjacentList[u].push_back(v);
        adjacentList[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    DFS(1);
    for (int i = 1; i <= N; i++)
    {
        if (i != 1)
        {
            cout << " ";
        }
        cout << degree[i];
        if ((degree[i] & 1) == 1)
        {
            oddDegreeNum++;
        }
        if (!known[i])
        {
            isConnective = false;
        }
    }
    cout << endl;
    if (isConnective)
    {
        if (oddDegreeNum == 0)
        {
            cout << "Eulerian";
        }
        else if (oddDegreeNum == 2)
        {
            cout << "Semi-Eulerian";
        }
        else
        {
            cout << "Non-Eulerian";
        }
    }
    else
    {
        cout << "Non-Eulerian";
    }
    return 0;
}