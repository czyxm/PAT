#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Structure node for tree
typedef struct TreeNode
{
    int size;
    int givenWeight;
    vector<int> weight;
    vector< vector<int> > children;
}*TNode;

TNode tree;
//Compare function for sorting children by decreasing weight
bool compare(int node1, int node2)
{
    return tree->weight[node1] > tree->weight[node2];
}
//Read input
void ReadTree()
{
    tree = new TreeNode;
    int M, node, childrenNum;
    cin >> tree->size >> M >> tree->givenWeight;
    tree->weight.resize(tree->size);
    tree->children.resize(tree->size);
    for (int i = 0; i < tree->size; i++)
    {
        cin >> tree->weight[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> node >> childrenNum;
        tree->children[node].resize(childrenNum);
        for (int j = 0; j < childrenNum; j++)
        {
            cin >> tree->children[node][j];
        }
        //Make sure search from the children with bigger weight
        sort(tree->children[node].begin(), tree->children[node].end(), compare);
    }
}
//Search recursively
void Search(int node, vector<int> & path)
{
    static int weight = 0;
    weight += tree->weight[node];
    path.push_back(node);
    if (weight == tree->givenWeight && tree->children[node].size() == 0)
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << tree->weight[path[i]];
            if (i < path.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < tree->children[node].size(); i++)
    {
        Search(tree->children[node][i], path);
    }
    //Backtracking
    weight -= tree->weight[node];
    path.pop_back();
}

int main()
{
    ReadTree();
    vector<int> path;
    Search(0, path);
    return 0;
}