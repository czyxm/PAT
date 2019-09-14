#include<bits/stdc++.h>
using namespace std;

int adjacent[201][201] = {0};
const int MAXDISTANCE = 200000;
int main()
{
    int Nv, Ne, M, n, u, v, w, index = 0, minTotalDistance = MAXDISTANCE;
    cin >> Nv >> Ne;
    for (int i = 1; i <= Ne; i++)
    {
        cin >> u >> v >> w;
        adjacent[u][v] = adjacent[v][u] = w;
    }
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> n >> u;
        set<int> city;
        int flag = 1, totalDistance = 0, count = 0;
        w = u;
        for (int j = 1; j < n; j++)
        {
            cin >> v;
            if (adjacent[u][v] > 0)
            {
                totalDistance += adjacent[u][v];
                city.insert(v);
                count++;
            }
            else
            {
                flag = 0;
            }
            u = v;
        }
        cout << "Path " << i << ": ";
        if (flag == 0)
        {
            cout << "NA" << " (Not a TS cycle)" << endl;
        }
        else if (u != w || city.size() != Nv)
        {
            cout << totalDistance << " (Not a TS cycle)" << endl;
        }
        else
        {
            if (totalDistance < minTotalDistance)
            {
                index = i;
                minTotalDistance = totalDistance;
            }
            cout << totalDistance << " (TS" << (count == Nv ? " simple " : " ") << "cycle)" << endl;
        }
    }
    cout << "Shortest Dist(" << index << ") = " << minTotalDistance << endl;
    return 0;
}