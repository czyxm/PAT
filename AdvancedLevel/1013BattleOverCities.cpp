#include<iostream>
#include<set>
using namespace std;
//Node Structure for graph
typedef struct GraphNode
{
    int Nv;  //#Vertices
    int Ne;  //#Edges
    bool ** map;  //Bool array for connectivity
}*GNode;

GNode graph;

//Deep First Search
void DFS(int u, set<int> & vertex)
{
    int v;
    for (set<int>::iterator iter = vertex.begin(); iter != vertex.end(); iter++)
    {
        v = *iter;
        if (graph->map[u][v])
        {
            vertex.erase(v);
            DFS(v, vertex);
        }
    }
}

int main()
{
    int K, u, v, w, component;
    set<int> vertex;
    graph = new GraphNode;
    //Read graph and initialize map
    cin >> graph->Nv >> graph->Ne >> K;
    graph->map = new bool* [graph->Nv];
    for (int i = 0; i < graph->Nv; i++)
    {
        graph->map[i] = new bool [graph->Nv];
        for (int j = 0; j < graph->Nv; j++)
        {
            graph->map[i][j] = false;
        }
    }
    //Read map
    for (int i = 1; i <= graph->Ne; i++)
    {
        cin >> u >> v;
        graph->map[u - 1][v - 1] = graph->map[v - 1][u - 1] = true;
    }
    //Caculate #components each pass
    for (int i = 1; i <= K; i++)
    {
        cin >> w;
        w--;
        component = 0;
        //Initialize the vertex set
        vertex.clear();
        for (int j = 0; j < graph->Nv; j++)
        {
            vertex.insert(j);
        }
        vertex.erase(w);
        while (!vertex.empty())
        { 
            u = *vertex.begin();
            vertex.erase(u);
            DFS(u, vertex);
            component++;
        }
        cout << component - 1 << endl; 
    }
    return 0;
}