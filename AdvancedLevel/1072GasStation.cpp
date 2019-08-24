#include<bits/stdc++.h>
using namespace std;

struct Station
{
    bool valid;
    int minDistance, totalDistance;
};

int main()
{
    int N, M, K, D, Nv, u, v, w, index = -1;
    const int INFINIT = 999999999;
    string p1, p2;
    vector<bool> known;
    vector<int> distance;
    vector< vector<int> > weight;
    vector<Station> gasStations;
    cin >> N >> M >> K >> D;
    Nv = N + M;
    known.resize(Nv + 1);
    distance.resize(Nv + 1);
    weight.resize(Nv + 1);
    gasStations.resize(M + 1);
    for (u = 1; u <= Nv; u++)
    {
        weight[u].resize(Nv + 1);
        for (v = 1; v <= Nv; v++)
        {
            weight[u][v] = 0;
        }
    }
    for (int i = 1; i <= K; i++)
    {
        cin >> p1 >> p2 >> w;
        u = p1[0] == 'G' ? stoi(p1.substr(1)) + N : stoi(p1);
        v = p2[0] == 'G' ? stoi(p2.substr(1)) + N : stoi(p2);
        weight[u][v] = weight[v][u] = w;
    }
    for (u = 1; u <= M; u++)
    {
        for (v = 1; v <= Nv; v++)
        {
            known[v] = false;
            distance[v] = INFINIT;
        }
        distance[N + u] = 0;
        gasStations[u].valid = true;
        gasStations[u].totalDistance = 0;
        gasStations[u].minDistance = INFINIT;
        while (true)
        {
            w = INFINIT;
            for (int i = 1; i <= Nv; i++)
            {
                if (!known[i] && distance[i] < w)
                {
                    w = distance[i];
                    v = i;
                }
            }
            if (w >= INFINIT)
            {
                break;
            }
            known[v] = true;
            for (w = 1; w <= Nv; w++)
            {
                if (weight[v][w] > 0 && !known[w] && weight[v][w] + distance[v] < distance[w])
                {
                    distance[w] = weight[v][w] + distance[v];
                }
            }
        }
        for (v = 1; v <= N; v++)
        {
            if (distance[v] > D)
            {
                gasStations[u].valid = false;
                break;
            }
            if (distance[v] < gasStations[u].minDistance)
            {
                gasStations[u].minDistance = distance[v];
            }
            gasStations[u].totalDistance += distance[v];
        }
        if (gasStations[u].valid)
        {
            if (index == -1 || 
                gasStations[u].minDistance > gasStations[index].minDistance || 
                (gasStations[u].minDistance == gasStations[index].minDistance && gasStations[u].totalDistance < gasStations[index].totalDistance))
            {
                index = u;
            }
        }
    }
    if (index == -1)
    {
        cout << "No Solution";
    }
    else
    {
        cout << "G" << index << endl;
        cout << fixed << setprecision(1) << float(gasStations[index].minDistance) << " " << (gasStations[index].totalDistance * 100.0 + 5) / N / 100;
    }
    return 0;
}