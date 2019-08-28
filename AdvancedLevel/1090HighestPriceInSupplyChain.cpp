#include<bits/stdc++.h>
using namespace std;

int maxLevel = 0, num = 0;
vector<int> adjacentList[100000];

void DFS(int n, int level)
{
    for (int i = 0; i < adjacentList[n].size(); i++)
    {
        DFS(adjacentList[n][i], level + 1);
    }
    if (level > maxLevel)
    {
        maxLevel = level;
        num = 1;
    }
    else if (level == maxLevel)
    {
        num++;
    }
}

int main()
{
    int N, root, supplier;
    double price, rate;
    cin >> N >> price >> rate;
    rate = rate / 100 + 1;
    for (int i = 0; i < N; i++)
    {
        cin >> supplier;
        if (supplier == -1)
        {
            root = i;
        }
        else
        {
            adjacentList[supplier].push_back(i);
        }
    }
    DFS(root, 0);
    price *= pow(rate, maxLevel);
    cout << fixed << setprecision(2) << price << " " << num;
    return 0;
}