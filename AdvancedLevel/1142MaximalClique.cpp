#include<bits/stdc++.h>
using namespace std;

int Nv, Ne;
bool adjacentList[201][201] = {false};

int main()
{
    int u, v, M, K;
    vector<int> clique;
    cin >> Nv >> Ne;
    for (int i = 1; i <= Ne; i++)
    {
        cin >> u >> v;
        adjacentList[u][v] = adjacentList[v][u] = true;
    }
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        int flag = 1;
        unordered_set<int> unknown;
        for (int j = 1; j <= Nv; j++)
        {
            unknown.insert(j);
        }
        cin >> K;
        clique.resize(K);
        for (int j = 0; j < K; j++)
        {
            cin >> clique[j];
            unknown.erase(clique[j]);
            for (int k = 0; k < j; k++)
            {
                if (!adjacentList[clique[j]][clique[k]])
                {
                    flag = -1;
                    break;
                }
            }
        }
        if (flag != 1)
        {
            cout << "Not a Clique" << endl;
        }
        else
        {
            auto begin = unknown.begin(), end = unknown.end();
            while (begin != end)
            {
                bool _flag = true;
                for (int k = 0; k < clique.size(); k++)
                {
                    if (!adjacentList[*begin][clique[k]])
                    {
                        _flag = false;
                        break;
                    }
                }
                if (_flag)
                {
                    flag = 0;
                    break;
                }
                begin++;
            }
            cout << (flag == 0 ? "Not Maximal" : "Yes") << endl;
        }
        clique.clear();
    }
    return 0;
}