#include<bits/stdc++.h>
using namespace std;

struct City
{
    string name;
    int happiness;
}city[200];

struct Graph
{
    int Nv, Ne, source, target;
    int cost[200][200] = {0};
}graph;

void readGraph()
{
    string c1, c2, _source;
    map<string, int> _hash;
    int _c1, _c2, _cost;
    cin >> graph.Nv >> graph.Ne >> city[0].name;
    for (int i = 1; i < graph.Nv; i++)
    {
        cin >> city[i].name >> city[i].happiness;
        _hash.insert(pair<string, int>(city[i].name, i));
    }
    graph.source = 0;
    graph.target = _hash["ROM"];
    for (int i = 0; i < graph.Ne; i++)
    {
        cin >> c1 >> c2 >> _cost;
        _c1 = _hash[c1];
        _c2 = _hash[c2];
        graph.cost[_c1][_c2] = graph.cost[_c2][_c1] = _cost;
    }
}

int mostTotalHappiness = 0, totalHappiness = 0, leastTotalCost = 999999999, totalCost = 0, routeNum = 0;
vector<int> path, solution;
bool known[200] = {false};

void DFS(int u)
{
    if (u == graph.target)
    {
        if (totalCost < leastTotalCost)
        {
            leastTotalCost = totalCost;
            mostTotalHappiness = totalHappiness;
            routeNum = 1;
            solution = path;
        }
        else if (totalCost == leastTotalCost)
        {
            if (totalHappiness > mostTotalHappiness)
            {
                mostTotalHappiness = totalHappiness;
                solution = path;
            }
            else if (totalHappiness == mostTotalHappiness && path.size() < solution.size())
            {
                solution = path;
            }
            routeNum++;
        }
    }
    else
    {
        for (int v = 1; v < graph.Nv; v++)
        {
            if (!known[v] && graph.cost[u][v] > 0)
            {
                path.push_back(v);
                known[v] = true;
                totalHappiness += city[v].happiness;
                totalCost += graph.cost[u][v];
                DFS(v);
                path.pop_back();
                known[v] = false;
                totalHappiness -= city[v].happiness;
                totalCost -= graph.cost[u][v];
            }
        }
    }
}

int main()
{
    readGraph();
    DFS(graph.source);
    cout << routeNum << " " << leastTotalCost << " " << mostTotalHappiness << " " << mostTotalHappiness / solution.size() << endl;
    cout << city[graph.source].name;
    for (int i = 0; i < solution.size(); i++)
    {
        cout << "->" << city[solution[i]].name;
    }
    return 0;
}