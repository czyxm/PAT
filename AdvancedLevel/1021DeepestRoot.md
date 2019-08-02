# Deepest Root
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.
### Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=10^4) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N?1 lines follow, each describes an edge by given the two adjacent nodes' numbers.
### Output Specification:
For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print Error: K components where K is the number of connected components in the graph.
### Sample Input 1:
```in
5
1 2
1 3
1 4
2 5
```
### Sample Output 1:
```out
3
4
5
```
### Sample Input 2:
```in
5
1 3
1 4
2 5
3 4
```
### Sample Output 2:
```out
Error: 2 components
```
### Solution
DFS + Backtracking: 
Find the deepest height by DFS and if not all the vertices are gotten through there're more than 1 components in the graph. The size of vertex is up to 10^4 so I have to consider how to save time and space. I use an array `known[]` to mark this instead of `set` because the fuction `find()` takes more time and causes TLE. Furthermore, the 2-D array of connectivity between vertices wastes too much space causing MLE, thus I use adjacent vector to save space. Finally got AC!

```C++
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
```