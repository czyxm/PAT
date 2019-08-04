# Travel Plan
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.
### Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N?1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:
City1 City2 Distance Cost
where the numbers are all integers no more than 500, and are separated by a space.
### Output Specification:
For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.
### Sample Input:
```in
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
```
### Sample Output:
```out
0 2 3 3 40
```
### Solution
Dijkstra's algorithm + path record. Oh hu~
```C++
#include<iostream>
#include<string>
#include<set>
using namespace std;
#define INF 100000
//Structure node for graph
typedef struct GraphNode
{
    int nv;         //#vertex
    int ne;         //#edge
    int source;
    int target;
    int ** distance;
    int ** cost;
}* GNode;
//Structure node for vertex
typedef struct VertexNode
{
    int parent;
    int distance;
    bool known;
}* VNode;
//Read input
GNode readGraph()
{
    GNode graph = new GraphNode;
    int u, v, d, c;
    cin >> graph->nv >> graph->ne >> graph->source >> graph->target;
    graph->distance = new int* [graph->nv];
    graph->cost = new int* [graph->nv];
    for (int i = 0; i < graph->nv; i++)
    {
        graph->distance[i] = new int [graph->nv];
        graph->cost[i] = new int [graph->nv];
        for (int j = 0; j < graph->nv; j++)
        {
            graph->cost[i][j] = graph->distance[i][j] = 0;
        }
    }
    for (int i = 0; i < graph->ne; i++)
    {
        cin >> u >> v >> d >> c;
        graph->distance[u][v] = graph->distance[v][u] = d;
        graph->cost[u][v] = graph->cost[v][u] = c;
    }
    return graph;
}
//Caculate cost form source to target
int cost(int target, const VNode* vertex, const GNode & graph)
{
    int res = 0, parent = vertex[target]->parent;
    while (parent != -1)
    {
        res += graph->cost[parent][target];
        target = parent;
        parent = vertex[parent]->parent;
    }
    return res;
}

int main()
{
    GNode graph = readGraph();
    VNode * vertex = new VNode [graph->nv];
    int u, v, minCost;
    for (int i = 0; i < graph->nv; i++)
    {
        vertex[i] = new VertexNode;
        vertex[i]->known = false;
        vertex[i]->distance = INF;
    }
    //Initialize the source
    vertex[graph->source]->parent = -1;
    vertex[graph->source]->distance = 0;
    while (true)
    {
        //Find the nearest unknown vertex
        u = -1;
        for (int i = 0; i < graph->nv; i++)
        {
            if (!vertex[i]->known && (u == -1 || vertex[i]->distance < vertex[u]->distance))
            {
                u = i;
            }
        }
        //All the vertices are known
        if (u == -1)
        {
            break;
        }
        vertex[u]->known = true;
        for (v = 0; v < graph->nv; v++)
        {
            if (graph->distance[u][v] > 0 && !vertex[v]->known)
            {
                //Find a shorter path
                if (vertex[u]->distance + graph->distance[u][v] < vertex[v]->distance)
                {
                    vertex[v]->distance = vertex[u]->distance + graph->distance[u][v];
                    vertex[v]->parent = u;
                    if (v == graph->target)
                    {
                        minCost = cost(graph->target, vertex, graph);
                    }
                }
                //Find another path with the same distance
                else if (vertex[u]->distance + graph->distance[u][v] == vertex[v]->distance && v == graph->target)
                {
                    int temp = cost(u, vertex, graph) + graph->cost[u][v];
                    if (temp < minCost)
                    {
                        minCost = temp;
                        vertex[v]->distance = vertex[u]->distance + graph->distance[u][v];
                        vertex[v]->parent = u;
                    }
                }
            }
        }
    }
    string path;
    u = graph->target;
    while (u != -1)
    {
        path = to_string(u) + " " + path;
        u = vertex[u]->parent;
    }
    cout << path << vertex[graph->target]->distance << " " << minCost;
    return 0;
}
```