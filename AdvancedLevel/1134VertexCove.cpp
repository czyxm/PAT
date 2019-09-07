#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > adjacentList;

int main()
{
    int Nv, Ne, K, M, u, v;
    cin >> Nv >> Ne;
    adjacentList.resize(Nv);
    for (int i = 1; i <= Ne; i++)
    {
        cin >> u >> v;
        adjacentList[u].push_back(v);
        adjacentList[v].push_back(u);
    }
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        vector<bool> isLack(Nv, true), necessaryVertex(Nv, false);
        bool flag = true;
        cin >> M;
        for (int j = 1; j <= M; j++)
        {
            cin >> u;
            isLack[u] = false;
        }
        for (int j = 0; j < Nv; j++)
        {
            if (isLack[j])
            {
                if (necessaryVertex[j])
                {
                    flag = false;
                    break;
                }
                for (int & v : adjacentList[j])
                {
                    necessaryVertex[v] = true;
                }
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}