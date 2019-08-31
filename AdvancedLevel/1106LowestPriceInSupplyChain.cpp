#include<bits/stdc++.h>
using namespace std;

int N, number = 0;
double price, rate, minLevel = 100000;
vector< vector<int> > adjacentList;

void DFS(int root, int level)
{
    if (adjacentList[root].empty())
    {
        if (level < minLevel)
        {
            minLevel = level;
            number = 1;
        }
        else if (level == minLevel)
        {
            number++;
        }
    }
    else
    {
        for (int i = 0; i < adjacentList[root].size(); i++)
        {
            DFS(adjacentList[root][i], level + 1);
        }
    }
}

int main()
{
    int degree;
    cin >> N >> price >> rate;
    rate = rate / 100 + 1;
    adjacentList.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> degree;
        adjacentList[i].resize(degree);
        for (int j = 0; j < degree; j++)
        {
            cin >> adjacentList[i][j];
        }
    }
    DFS(0, 0);
    price *= pow(rate, minLevel);
    cout << fixed << setprecision(4) << price << " " << number;
    return 0;
}