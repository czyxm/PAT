# Public Bike Management

There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.

![](../img/1018.png)

The above figure illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S
?3, we have 2 different shortest paths:
1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S?3, so that both stations will be in perfect conditions.

2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

### Input Specification:
Each input file contains one test case. For each case, the first line contains 4 numbers: c_max(<=100), always an even number, is the maximum capacity of each station; N (<=500), the total number of stations; S_p, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers C?i(i=1,?,N) where each Ci is the current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj?. All the numbers in a line are separated by a space.

### Output Specification:
For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0?>Si?? ?>??>Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.

### Sample Input:
```in
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
```
### Sample Output:
```out
3 0->2->3 0
```
### Solution
DFS + Backtracking:
Search the path by DFS to find the shortest path and meanwhile record the path. If find an another shortest path, compare the #send-bikes and #recycle-bikes to determine if the path need to be changed. Actually I did this by Dijkstra's algorithm to find the shortest path howbeit there's always a test point wrong for unknown reasons :). Anyway, good luck for you!

```C++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*Structure for graph*/
typedef struct GraphNode{
    int Cmax;  //Maximum capacity
    int Nv;    //#vertex
    int Ne;    //#edge
    int source;//PBMC
    int target;//Problem station
    int * bike;//#bike of each station
    int ** map;//Weight map
}* GNode;

/*
 *@brief:read the basic information from the console
 *@return:a pointer for graph struct node
 */
GNode ReadG();
//Caculate #sending bikes and #recycling bikes
void SendOrRecycle(int & sendBike, int & recycleBike, const vector<int> & path, const GNode & graph);
//Deep First Search
void DFS(int vertex, const GNode & graph);

int send, recycle;
vector<int> bestPath;

int main()
{
    GNode graph = ReadG();
    send = recycle = graph->Cmax;
    DFS(graph->source, graph);
    cout << send << " ";
    for (int i = 0; i < bestPath.size(); i++)
    {
        cout << bestPath[i];
        if (i < bestPath.size() - 1)
        {
            cout << "->";
        }
    }
    cout << " " << recycle << endl;
    delete graph;
    return 0;
}

GNode ReadG()
{
	int i, j, w;
	int p, q;
	GNode graph = new GraphNode;
    //Number of cities, number of roads, serial number city
	cin >> graph->Cmax >> graph->Nv >> graph->target >> graph->Ne;
    graph->source = 0;
    graph->Nv++;  //Plus the PBMC
    //Allocate and initialize graph weight map
    graph->map = new int* [graph->Nv];
    graph->bike = new int [graph->Nv];
    for(i = 0; i < graph->Nv; i++)
    {
        if (i > 0)
        {
            cin >> graph->bike[i];
        }
        graph->map[i] = new int[graph->Nv];
        for(j = 0; j < graph->Nv; j++)
        {
            graph->map[i][j] = 0;
        }
    }
    //Assign weight
	for(i = 0; i < graph->Ne; i++)
	{
		cin >> p >> q >> w;
		graph->map[p][q] = graph->map[q][p] = w;
	}
	return graph;    
} 

void SendOrRecycle(int & sendBike, int & recycleBike, const vector<int> & path, const GNode & graph)
{
    int half = graph->Cmax / 2;
    sendBike = recycleBike = 0;
    for (int i = 1; i < path.size(); i++)
    {
        if (graph->bike[path[i]] > half)  //Recycle
        {
            recycleBike += graph->bike[path[i]] - half;
        }
        else if (graph->bike[path[i]] < half)  //Send
        {
            if (recycleBike >= half - graph->bike[path[i]])  //Recycle is enough
            {
                recycleBike -= half - graph->bike[path[i]];
            }
            else
            {
                sendBike += half - graph->bike[path[i]] - recycleBike;
                recycleBike = 0;
            }
        }
    }
}

void DFS(int vertex, const GNode & graph)
{
    static int minDistance = -1, totalDistance = 0;
    static int * known = new int [graph->Nv];
    static vector<int> path;
    int distance;
    if (vertex == graph->source)
    {
        distance = 0;
    }
    else
    {
        distance = graph->map[path.back()][vertex];
    }
    totalDistance += distance;
    path.push_back(vertex);
    known[vertex] = 1;
    if (vertex == graph->target)
    {
        if (minDistance == -1 || totalDistance < minDistance)
        {
            minDistance = totalDistance;
            SendOrRecycle(send, recycle, path, graph);
            bestPath = path;
        }
        else if (totalDistance == minDistance)
        {
            int num1, num2;
            SendOrRecycle(num1, num2, path, graph);
            if (num1 < send || (num1 == send && num2 < recycle))
            {
                send = num1;
                recycle = num2;
                bestPath = path;
            }
        }
    }
    else
    {
        for (int i = 1; i < graph->Nv; i++)
        {
            if (known[i] != 1 && graph->map[vertex][i] > 0)
            {
                DFS(i, graph);
            }
        }
    }
    known[vertex] = 0;
    path.pop_back();
    totalDistance -= distance;
}
```