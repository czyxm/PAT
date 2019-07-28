# Battle Over Cities
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and city?1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city?3.

### Input Specification:
Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

### Output Specification:
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

### Sample Input:
```in
3 2 3
1 2
1 3
1 2 3
```
### Sample Output:
```out
1
0
0
```

### Solution
The number of highways to be repaired equals the number of components minus 1 after the city is occupied, thus just need to find the components by means of DFS or BFS. Here DFS is adopted.

```C++
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
```