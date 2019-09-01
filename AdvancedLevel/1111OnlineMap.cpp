#include<bits/stdc++.h>
using namespace std;

struct Graph
{
    int Nv, Ne, source, target;
    int length[500][500], time[500][500];
}graph;

struct Path
{
    vector<int> path;
    int totalDistance, totalTime;
}path0, path1, path2;

const int INF = 999999999;
bool _known[500];
int _distance[500], _time[500], _pioneer[500], _parent[500];
//Dijkstra's Algorithm
void Dijkstra1()
{
    int u, v, minDistance;
    _distance[graph.source] = _time[graph.source] = 0;
    _parent[graph.source] = -1;
    while (true)
    {
        u = -1;
        minDistance = INF;
        for (int i = 0; i < graph.Nv; i++)
        {
            if (!_known[i] && _distance[i] < minDistance)
            {
                minDistance = _distance[i];
                u = i;
            }
        }
        if (u == -1)
        {
            break;
        }
        _known[u] = true;
        for (v = 0; v < graph.Nv; v++)
        {
            if (!_known[v] && graph.length[u][v] > 0)
            {
                if (_distance[u] + graph.length[u][v] < _distance[v])
                {
                    _distance[v] = _distance[u] + graph.length[u][v];
                    _time[v] = _time[u] + graph.time[u][v];
                    _parent[v] = u;
                }
                else if (_distance[u] + graph.length[u][v] == _distance[v] && _time[u] + graph.time[u][v] < _time[v])
                {
                    _time[v] = _time[u] + graph.time[u][v];
                    _parent[v] = u;
                }
            }
        }
    }
    path1.totalDistance = _distance[graph.target];
    path1.totalTime = _time[graph.target];
    u = graph.target;
    while (u != -1)
    {
        path1.path.push_back(u);
        u = _parent[u];
    }
}

void Dijkstra2()
{
    int u, v, minTime;
    _distance[graph.source] = _time[graph.source] = 0;
    _parent[graph.source] = -1;
    while (true)
    {
        u = -1;
        minTime = INF;
        for (int i = 0; i < graph.Nv; i++)
        {
            if (!_known[i] && _time[i] < minTime)
            {
                u = i;
                minTime = _time[i];
            }
        }
        if (u == -1)
        {
            break;
        }
        _known[u] = true;
        for (v = 0; v < graph.Nv; v++)
        {
            if (!_known[v] && graph.time[u][v] > 0)
            {
                if (_time[u] + graph.time[u][v] < _time[v])
                {
                    _time[v] = _time[u] + graph.time[u][v];
                    _distance[v] = _distance[u] + graph.length[u][v];
                    _pioneer[v] = _pioneer[u] + 1;
                    _parent[v] = u;
                }
                else if (_time[u] + graph.time[u][v] == _time[v] && _pioneer[u] + 1 < _pioneer[v])
                {
                    _distance[v] = _distance[u] + graph.length[u][v];
                    _pioneer[v] = _pioneer[u] + 1;
                    _parent[v] = u;
                }
            }
        }
    }
    path2.totalDistance = _distance[graph.target];
    path2.totalTime = _time[graph.target];
    u = graph.target;
    while (u != -1)
    {
        path2.path.push_back(u);
        u = _parent[u];
    }
}

void display(const vector<int> & _path)
{
    for (int i = _path.size() - 1; i >= 0; i--)
    {
        cout << _path[i];
        if (i != 0)
        {
            cout << " -> ";
        }
    }
    cout << endl;
}

int main()
{
    int u, v, isOneWay, l, t;
    cin >> graph.Nv >> graph.Ne;
    for (int i = 0; i < graph.Nv; i++)
    {
        _known[i] = false;
        _pioneer[i] = _distance[i] = _time[i] = INF;
        for (int j = 0; j < graph.Nv; j++)
        {
            graph.length[i][j] = graph.time[i][j] = -1;
        }
    }
    for (int i = 0; i < graph.Ne; i++)
    {
        cin >> u >> v >> isOneWay >> l >> t;
        if (isOneWay == 0)
        {
            graph.length[v][u] = l;
            graph.time[v][u] = t;
        }
        graph.length[u][v] = l;
        graph.time[u][v] = t;
    }
    cin >> graph.source >> graph.target;
    Dijkstra1();
    for (int i = 0; i < graph.Nv; i++)
    {
        _known[i] = false;
        _distance[i] = _time[i] = INF;
    }
    Dijkstra2();
    if (path1.path == path2.path)
    {
        cout << "Distance = " << path1.totalDistance << "; Time = " << path1.totalTime << ": ";
        display(path1.path);
    }
    else
    {
        cout << "Distance = " << path1.totalDistance << ": ";
        display(path1.path);
        cout << "Time = " << path2.totalTime << ": ";
        display(path2.path);
    }
    return 0;
}
/*DFS -> TLE(27)
#include<bits/stdc++.h>
using namespace std;

struct Graph
{
    int Nv, Ne, source, target;
    int length[500][500], time[500][500];
}graph;

struct Path
{
    vector<int> path;
    int totalDistance, totalTime;
}path0, path1, path2;

const int INF = 999999999;
bool _known[500];

void copyPath(Path & p1, Path & p2)
{
    p2.path = p1.path;
    p2.totalDistance = p1.totalDistance;
    p2.totalTime = p1.totalTime;
}

void display(const vector<int> & _path)
{
    for (int i = 0; i < _path.size(); i++)
    {
        if (i != 0)
        {
            cout << " -> ";
        }
        cout << _path[i];
    }
    cout << endl;
}

void DFS(int u)
{
    known[u] = true;
    path0.path.push_back(u);
    if (u == graph.target)
    {
        if (path0.totalDistance < path1.totalDistance || (path0.totalDistance == path1.totalDistance && path0.totalTime < path1.totalTime))
        {
            copyPath(path0, path1);
        }
        if (path0.totalTime < path2.totalTime || (path0.totalTime == path2.totalTime && path0.path.size() < path2.path.size()))
        {
            copyPath(path0, path2);
        }
    }
    for (int v = 0; v < graph.Nv; v++)
    {
        if (graph.length[u][v] > 0 && !known[v])
        {
            path0.totalDistance += graph.length[u][v];
            path0.totalTime += graph.time[u][v];
            DFS(v);
            path0.totalDistance -= graph.length[u][v];
            path0.totalTime -= graph.time[u][v];
        }
    }
    known[u] = false;
    path0.path.pop_back();
}

int main()
{
    int u, v, isOneWay, l, t;
    cin >> graph.Nv >> graph.Ne;
    for (int i = 0; i < graph.Nv; i++)
    {
        known[i] = false;
        for (int j = 0; j < graph.Nv; j++)
        {
            graph.length[i][j] = graph.time[i][j] = -1;
        }
    }
    for (int i = 0; i < graph.Ne; i++)
    {
        cin >> u >> v >> isOneWay >> l >> t;
        if (isOneWay == 0)
        {
            graph.length[v][u] = l;
            graph.time[v][u] = t;
        }
        graph.length[u][v] = l;
        graph.time[u][v] = t;
    }
    cin >> graph.source >> graph.target;
    path0.totalDistance = path0.totalTime = 0;
    path1.totalDistance = path1.totalTime = path2.totalDistance = path2.totalTime = INF;
    DFS(graph.source);
    if (path1.path == path2.path)
    {
        cout << "Distance = " << path1.totalDistance << "; Time = " << path1.totalTime << ": ";
        display(path1.path);
    }
    else
    {
        cout << "Distance = " << path1.totalDistance << ": ";
        display(path1.path);
        cout << "Time = " << path2.totalTime << ": ";
        display(path2.path);
    }
    return 0;
}
*/