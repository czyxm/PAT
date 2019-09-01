#include<bits/stdc++.h>
using namespace std;

int N, root = 0, maxIdx = 0, rear, children[100][2], node[100];

void DFS(int n, int index)
{
    if (n == -1 || index > N)
    {
        return;
    }
    node[index] = n;
    DFS(children[n][0], index << 1);
    DFS(children[n][1], (index << 1) + 1);
}

int main()
{
    bool isRoot[100];
    string l, r;
    cin >> N;
    for (int i = 0; i < 100; i++)
    {
        node[i] = -1;
        isRoot[i] = true;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> l >> r;
        if (l == "-")
        {
            children[i][0] = -1;
        }
        else
        {
            children[i][0] = stoi(l);
            isRoot[children[i][0]] = false;
        }
        if (r == "-")
        {
            children[i][1] = -1;
        }
        else
        {
            children[i][1] = stoi(r);
            isRoot[children[i][1]] = false;
        }
    }
    while (!isRoot[root])
    {
        root++;
    }
    DFS(root, 1);
    for (int i = 1; i <= N; i++)
    {
        if (node[i] == -1)
        {
            cout << "NO " << root;
            return 0;
        }
    }
    cout << "YES " << node[N];
    return 0;
}