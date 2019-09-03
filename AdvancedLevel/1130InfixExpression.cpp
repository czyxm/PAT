#include<bits/stdc++.h>
using namespace std;

struct Node
{
    string key;
    int left, right;
    Node()
    {
        left = right = -1;
    }
};

int N, root = 1;
Node node[21];

void display(int n)
{
    if (n <= 0)
    {
        return;
    }
    int flag = false;
    if (n != root && node[n].right != -1)
    {
        flag = true;
        cout << "(";
    }
    display(node[n].left);
    cout << node[n].key;
    display(node[n].right);
    if (flag)
    {
        cout << ")";
    }
}

int main()
{
    cin >> N;
    vector<bool> isRoot(N + 1, true);
    for (int i = 1; i <= N; i++)
    {
        cin >> node[i].key >> node[i].left >> node[i].right;
        if (node[i].left != -1)
        {
            isRoot[node[i].left] = false;
        }
        if (node[i].right != -1)
        {
            isRoot[node[i].right] = false;
        }
    }
    while (!isRoot[root])
    {
        root++;
    }
    display(root);
    return 0;
}