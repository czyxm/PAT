#include<bits/stdc++.h>
using namespace std;

int N, key[100], _key[100], children[100][2];

void inorder(int n)
{
    static int index = 0;
    if (n == -1)
    {
        return;
    }
    inorder(children[n][0]);
    _key[n] = key[index++];
    inorder(children[n][1]);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> children[i][0] >> children[i][1];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> key[i];
    }
    sort(key, key + N, less<int>());
    inorder(0);
    queue<int> levelOrder;
    int index;
    levelOrder.push(0);
    while (!levelOrder.empty())
    {
        index = levelOrder.front();
        if (index != 0)
        {
            cout << " ";
        }
        cout <<_key[index];
        levelOrder.pop();
        if (children[index][0] != -1)
        {
            levelOrder.push(children[index][0]);
        }
        if (children[index][1] != -1)
        {
            levelOrder.push(children[index][1]);
        }
    }
    return 0;
}