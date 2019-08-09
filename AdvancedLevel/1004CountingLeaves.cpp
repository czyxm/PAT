#include<iostream>
#include<queue>
using namespace std;
/*
 *@brief:read data from the console
 *@return:an (N+1)X(N+1) 2d array, the first element of 
 *row i is the degree of node i follwed by its chidren
 */
int** readData();

int main()
{
    queue<int> nodeQueue;
    int curNum = 1, newNum = 0, leafNum = 0, parent;
    int ** nodeData = readData();
    nodeQueue.push(1);   //Push root into the node queue
    
    while (!nodeQueue.empty())
    {
        //Every time pop the front node and check if it's a leaf node
        parent = nodeQueue.front();
        nodeQueue.pop();
        if (nodeData[parent][0] == 0)//Leaf node
        {
            leafNum++;  
        }
        else//Non-leaf node, push its chidren into the queue
        {
            newNum += nodeData[parent][0]; //Increase the number of nodes in the next level
            for (int i = 1; i <= nodeData[parent][0]; i++)
            {
                nodeQueue.push(nodeData[parent][i]);
            }
        }
        if (--curNum == 0)//Current node is the end of this level
        {
            //Display the leafNum
            if (parent == 1)
            {
                cout << leafNum;
            }
            else
            {
                cout << " " << leafNum;
            }
            //Refresh curNum with the number of nodes in the next level
            curNum = newNum;
            leafNum = newNum = 0;
        }
    }
}

int** readData()
{
    int N, M, degree, parent, ** nodeData;
    //Allocate a (N+1)X(N+1) array
    nodeData = new int*[N + 1];
    for (int i = 0; i <= N; i++)
    {
        nodeData[i] = new int[N + 1];
        nodeData[i][0] = 0; 
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> parent >> degree;
        //Node i is stored in row i
        //The first element of each row is the number of it's children
        //Follwed by its children
        nodeData[parent][0] = degree;
        for (int j = 1; j <= degree; j++)
        {
            cin >> nodeData[parent][j];
        }
    }
}