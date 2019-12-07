#include<bits/stdc++.h>
using namespace std;

int Nv, Ne, city;
vector<int> adjacent[501];
vector<int> setID(501, 0);
unordered_map<int, int> cost;
struct Edge
{
    int u, v;
    Edge(int u, int v):u(u), v(v){}
    bool operator> (const Edge & e)const
    {
        return cost[u * 500 + v] > cost[e.u * 500 + e.v];
    }
};
priority_queue<Edge, vector<Edge>, greater<Edge> > destroyedEdge, _destroyedEdge;
set<int> unknown;

void DFS(int u, int id)
{
    setID[u] = id;
    unknown.erase(u);
    for (int & v : adjacent[u])
    {
        if (unknown.find(v) != unknown.end())
        {
            DFS(v, id);
        }
    }
}

int main()
{
    int u, v, c, s, id, maxCost = 0;
    vector<int> res;
    cin >> Nv >> Ne;
    for (int i = 1; i <= Ne; i++)
    {
        cin >> u >> v >> c >> s;
        cost[u * 500 + v] = cost[v * 500 + u] = c;
        if (s == 1)
        {
            adjacent[u].push_back(v);
            adjacent[v].push_back(u);
        }
        else
        {
            destroyedEdge.push(Edge(u, v));
        }
    }
    for (int i = 1; i <= Nv; i++)
    {
        for (int j = 1; j <= Nv; j++)
        {
            unknown.insert(j);
        }
        id = c = 0;
        unknown.erase(i);
        fill(setID.begin(), setID.end(), 0);
        while (!unknown.empty())
        {
            DFS(*unknown.begin(), ++id);
        }
        if (id > 1)
        {
            _destroyedEdge = destroyedEdge;
            while (!_destroyedEdge.empty() && id > 1)
            {
                const Edge & e = _destroyedEdge.top();
                _destroyedEdge.pop();
                if (e.u != i && e.v != i && setID[e.u] != setID[e.v])
                {
                    for (v = 1; v <= Nv; v++)
                    {
                        if (setID[v] == setID[e.v])
                        {
                            setID[v] = setID[e.u];
                        }
                    }
                    id--;
                    c += cost[e.u * 500 + e.v];
                }
            }
            if (c > maxCost)
            {
                maxCost = c;
                res.clear();
                res.push_back(i);
            }
            else if (c == maxCost)
            {
                res.push_back(i);
            }
        }
    }
    if (maxCost == 0)
    {
        cout << 0;
    }
    else
    {
        sort(res.begin(), res.end(), less<int>());
        for (int & i : res)
        {
            if (i != res.front())
            {
                cout << " ";
            }
            cout << i;
        }
    }
    return 0;
}