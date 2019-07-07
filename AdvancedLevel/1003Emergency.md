# 1003 Emergency

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

### Input Specification:

Each input file contains one test case. For each test case, the first line contains 4 positive integers: *N* (≤500) - the number of cities (and the cities are numbered from 0 to *N*−1), *M* - the number of roads, *C*1 and *C*2 - the cities that you are currently in and that you must save, respectively. The next line contains *N* integers, where the *i*-th integer is the number of rescue teams in the *i*-th city. Then *M* lines follow, each describes a road with three integers *c*1, *c*2 and *L*, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from *C*1 to *C*2.

### Output Specification:

For each test case, print in one line two numbers: the number of different shortest paths between *C*1 and *C*2, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

### Sample Input:

```in
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
```

### Sample Output:

```out
2 4
```

### Solution

```C++
#include <iostream>
#define _INFINITY 1000000  //The maximum weight of the edge
using namespace std;

/*Structure for graph*/
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;    //#vertex
    int Ne;    //#edge
    int source;//current city
    int target;//city in danger
    int * team;//original team number array
    int ** G;  //weight map
};
typedef PtrToGNode MGraph;

/*
 *@brief:read the basic information from the console
 *@return:a pointer for graph struct node
 */
MGraph ReadG();

/*
 *@brief:find the shortest path using Dijkstra's algorithm
 *@param:Graph-the graph pointer
 *@param:roadNum-the number of shortest road
 *@param:teamNum-the maximum number of teams
 */
void ShortestDist(MGraph& Graph, int* roadNum, int* teamNum);

int main()
{
    int roadNum, teamNum;
    MGraph graph = ReadG();

    ShortestDist(graph, &roadNum, &teamNum);
    cout << roadNum << " " << teamNum;

    delete graph;
    return 0;
}

MGraph ReadG()
{
	int i, j, w;
	int p, q;
	MGraph graph = new GNode;
    //Number of cities, number of roads, serial number of source city and target city
	cin >> graph->Nv >> graph->Ne >> graph->source >> graph->target;
    //Allocate team array
    graph->team = new int[graph->Nv];
    for(i = 0; i < graph->Nv; i++)
    {
        cin >> graph->team[i];
    }
    //Allocate and initialize graph weight map
    graph->G = new int*[graph->Nv];
    for(i = 0; i < graph->Nv; i++)
    {
        graph->G[i] = new int[graph->Nv];
        for(j = 0; j < graph->Nv; j++)
        {
            graph->G[i][j] = 0;
        }
    }
    //Assign weight
	for(i = 0; i < graph->Ne; i++)
	{
		cin >> p >> q >> w;
		graph->G[p][q] = graph->G[q][p] = w;
	}
	return graph;    
} 

void ShortestDist(MGraph& graph, int* roadNum, int * teamNum)
{
	int i, j, minDist;
	int v, w;
	bool * known = new bool[graph->Nv];//Flag bit
    int * dist = new int[graph->Nv];   //Distance
    int * path = new int[graph->Nv];   //Number of paths
    int * team = new int[graph->Nv];   //Number of 
    //Initialize the arrays
	for(i = 0; i < graph->Nv; i++)
	{
		dist[i] = _INFINITY;
		path[i] = team[i] = 0;
        known[i] = false;
	}
    //Assign the source node
    dist[graph->source] = 0;
    path[graph->source] = 1;
    team[graph->source] = graph->team[graph->source];
    //Start the iteration
    while(true)
    {
        //Find the nearest city in the unknown set
    	minDist = _INFINITY;
    	for(i = 0; i < graph->Nv; i++)
        {
            if(!known[i] && dist[i] < minDist)
    	    {
    	    	minDist = dist[i];
    	    	v = i;
    	    }
        }	
        //All the cities have been handled->break
    	if(minDist == _INFINITY)
		    break;
        //Add current city into the known set
	    known[v] = true;
	    for(w = 0; w < graph->Nv; w++)
        {
            if(graph->G[v][w] > 0 && !known[w])
            {
                if(dist[v] + graph->G[v][w] < dist[w]) //Find a shorter road
	            {
                    //Refresh the distance, path and team
	            	dist[w] = dist[v] + graph->G[v][w];
                    path[w] = path[v];
                    team[w] = team[v] + graph->team[w];
	            } 	
				else if(dist[v] + graph->G[v][w] == dist[w])//Find another road of equal length
                {
                    //Refresh the path and assign a bigger number of teams
					path[w] += path[v];
                    if (team[v] + graph->team[w] > team[w])
                    {
                        team[w] = team[v] + graph->team[w];
                    }
                }
            }
        }	 
    }
    //Return the number of shortest roads and the maximum number of teams
    *roadNum = path[graph->target];
    *teamNum = team[graph->target];
    //Release the memory
    delete [] dist;
    delete [] path;
    delete [] team;
    delete [] known;
}
```

