#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE = 10000;
vector<int> nameOf(MAXSIZE, -1), indexOf(MAXSIZE, -1);
vector<int> adjacentList[MAXSIZE];
unordered_map<int, int>line;
vector<int> route, _route, stop, _stop;
vector<int> known(MAXSIZE, false);
int source, target, n = 0, stationNum, minStationNum;

void DFS(int u, int lastLine)
{
    stationNum++;
    known[u] = true;
    if (u == target)
    {
        if (stationNum < minStationNum)
        {
            minStationNum = stationNum;
            _stop = stop;
            _route = route;
        }
        else if (stationNum == minStationNum && stop.size() < _stop.size())
        {
            _stop = stop;
            _route = route;
        }
    }
    else
    {
        int v, _line;
        for (int i = 0; i < adjacentList[u].size(); i++)
        {
            v = adjacentList[u][i];
            if (!known[v])
            {
                _line = line[u * MAXSIZE + v];
                if (lastLine != _line)
                {
                    stop.push_back(u);
                    route.push_back(_line);
                }
                DFS(v, _line);
                if (lastLine != _line)
                {
                    stop.pop_back();
                    route.pop_back();
                }
            }
        }
    }
    stationNum--;
    known[u] = false;
}

void find()
{
    minStationNum = MAXSIZE;
    stationNum = 0;
    _route.clear();
    _stop.clear();
    DFS(source, -1);
    _stop.push_back(target);
    cout << minStationNum - 1 << endl;
    for (int i = 0; i < _route.size(); i++)
    {
        cout << "Take Line#" << _route[i] << " from " << setw(4) << setfill('0') << nameOf[_stop[i]] << " to " << setw(4) << setfill('0') << nameOf[_stop[i + 1]] << "." << endl;
    }
}

int main()
{
    int N, M, K, u, v;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> M;
        cin >> u;
        if (indexOf[u] == -1)
        {
            indexOf[u] = n;
            nameOf[n++] = u;
        }
        for (int j = 1; j < M; j++)
        {
            cin >> v;
            if (indexOf[v] == -1)
            {
                indexOf[v] = n;
                nameOf[n++] = v;
            }
            adjacentList[indexOf[u]].push_back(indexOf[v]);
            adjacentList[indexOf[v]].push_back(indexOf[u]);
            line.insert(pair<int, int>(indexOf[u] * MAXSIZE + indexOf[v], i));
            line.insert(pair<int, int>(indexOf[v] * MAXSIZE + indexOf[u], i));
            u = v;
        }
    }
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        cin >> u >> v;
        source = indexOf[u];
        target = indexOf[v];
        find();
    }
    return 0;
}