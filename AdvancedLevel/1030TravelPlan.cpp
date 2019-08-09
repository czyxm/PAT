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