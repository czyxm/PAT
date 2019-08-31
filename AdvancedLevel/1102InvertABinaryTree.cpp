#include<bits/stdc++.h>
using namespace std;

int N, root, children[10][2] = {-1};

void levelorder()
{
    queue<int> nodes;
    int curNode;
    nodes.push(root);
    while (!nodes.empty())
    {
        curNode = nodes.front();
        cout << curNode;
        nodes.pop();
        if (children[curNode][0] != -1)
        {
            nodes.push(children[curNode][0]);
        }
        if (children[curNode][1] != -1)
        {
            nodes.push(children[curNode][1]);
        }
        if (!nodes.empty())
        {
            cout << " ";
        }
    }
    cout << endl;
}

void inorder(int n)
{
    static int count = 0;
    if (n == -1)
    {
        return;
    }
    inorder(children[n][0]);
    if (count != 0)
    {
        cout << " ";
    }
    cout << n;
    count++;
    inorder(children[n][1]);
}

int main()
{
    bool isRoot[10] = {true};
    string line;
    cin >> N;
    getchar();
    for (int i = 0; i < N; i++)
    {
        isRoot[i] = true;
    }
    for (int i = 0; i < N; i++)
    {
        getline(cin, line);
        children[i][1] = (line[0] == '-' ? -1 : line[0] - '0');
        children[i][0] = (line[2] == '-' ? -1 : line[2] - '0');
        if (children[i][0] >= 0)
        {
            isRoot[children[i][0]] = false;
        }
        if (children[i][1] >= 0)
        {
            isRoot[children[i][1]] = false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (isRoot[i])
        {
            root = i;
            break;
        }
    }
    levelorder();
    inorder(root);
    return 0;
}