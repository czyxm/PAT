#include <iostream>
#include <vector>
using namespace std;
//Structure node for graph
typedef struct GraphNode {
    int Nv;  //#vertex
    int Ne;  //#edge
    vector<int> * map; //Adjacent vector
}* GNode;
//Read input
GNode ReadGraph()
{
    GNode graph = new GraphNode;
    int u, v;
    cin >> graph->Nv;
    graph->Ne = graph->Nv - 1;  //#edge = #vertex - 1
    graph->map = new vector<int> [graph->Nv + 1];
    for (int i = 1; i <= graph->Ne; i++)
    {
        cin >> u >> v;
        graph->map[u].push_back(v);
        graph->map[v].push_back(u);
    }
    return graph;
}
//Deep First Search
void DFS(int u, int & height, int * known, int & knownSize, const GNode & graph)
{
    static int maxHeight = 0;
    known[u] = 1;  //Insert into known set
    knownSize++;   //Increase known size
    //Refresh max height
    if (++maxHeight > height)
    {
        height = maxHeight;
    }
    auto begin = graph->map[u].begin(), end = graph->map[u].end();
    while (begin != end)
    {
        if (known[*begin] != 1)
        {
            DFS(*begin, height, known, knownSize, graph);
        }
        begin++;
    }
    //Backtracking
    maxHeight--;
}

int main()
{
    GNode graph = ReadGraph(); 
    int deepestHeight = 0, component = 1, height;
    vector<int> root;
    int knownSize, * known = new int [graph->Nv + 1];
    for (int i = 1; i <= graph->Nv; i++)
    {
        height = knownSize = 0;
        DFS(i, height, known, knownSize, graph);
        //Not a tree
        if (knownSize < graph->Nv)
        {
            while (knownSize < graph->Nv)
            {
                for (int j = 1; j <= graph->Nv; j++)
                {
                    if (known[j] != 1)
                    {
                        DFS(j, height, known, knownSize, graph);
                        component++;
                        break;
                    }
                }
            }
            cout << "Error: " << component << " components";
            return 0;
        }
        else if (height > deepestHeight)  //Refresh the deepest height and root vector
        {
            deepestHeight = height;
            root.clear();
            root.push_back(i);
        }
        else if (height == deepestHeight) //Add anpther root with the same height
        {
            root.push_back(i);
        }
        //Clear the known set
        for (int j = 1; j <= graph->Nv; j++)
        {
            known[j] = 0;
        }
    }
    for (int i = 0; i < root.size(); i++)
    {
        cout << root[i] << endl;
    }
    return 0;
}