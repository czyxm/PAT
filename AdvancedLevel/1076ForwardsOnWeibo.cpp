#include<bits/stdc++.h>
using namespace std;

vector<int> adjacentList[1001];
int BFS(int start, int size, int level)
{
    int front, pos, tail, res = 0;
    queue<int> forward;
    vector<bool> known(size + 1, false);
    forward.push(start);
    known[start] = true;
    tail = start;
    while (!forward.empty() && level > 0)
    {
        front = forward.front();
        forward.pop();
        for (int i = 0; i < adjacentList[front].size(); i++)
        {
            if (!known[adjacentList[front][i]])
            {
                pos = adjacentList[front][i];
                forward.push(pos);
                known[pos] = true;
                res++;
            }
        }
        if (front == tail)
        {
            level--;
            tail = pos;
        }
    }
    return res;
}

int main()
{
    int N, L, inDegree, follower, repeat, start;
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
    {
        cin >> inDegree;
        for (int j = 1; j <= inDegree; j++)
        {
            cin >> follower;
            adjacentList[follower].push_back(i);
        }
    }
    cin >> repeat;
    for (int i = 1; i <= repeat; i++)
    {
        cin >> start;
        cout << BFS(start, N, L) << endl;
    }
    return 0;
}