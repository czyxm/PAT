# Counting Leaves

A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

### Input Specification:

Each input file contains one test case. Each case starts with a line containing 0<*N*<100, the number of nodes in a tree, and *M* (<*N*), the number of non-leaf nodes. Then *M* lines follow, each in the format:

```
ID K ID[1] ID[2] ... ID[K]
```

where `ID` is a two-digit number representing a given non-leaf node, `K` is the number of its children, followed by a sequence of two-digit `ID`'s of its children. For the sake of simplicity, let us fix the root ID to be `01`.

The input ends with *N* being 0. That case must NOT be processed.

### Output Specification:

For each test case, you are supposed to count those family members who have no child **for every seniority level** starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where `01` is the root and `02` is its only child. Hence on the root `01` level, there is `0` leaf node; and on the next level, there is `1` leaf node. Then we should output `0 1` in a line.

### Sample Input:

```in
2 1
01 1 02
```

### Sample Output:

```out
0 1
```

---

### Solution

Deal with the tree in level order bu means of a queue. Enqueue nodes from the root followed by its children, and each pass dequeue a node to check whether it’ s a leaf node, meanwhile count the leaves.

```C++
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
    delete [] nodeData;
    return 0;
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
```



