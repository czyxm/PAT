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