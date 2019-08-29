#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, ID, degree;
    vector<int> adjacentList[100];
    queue<int> generation;
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> ID >> degree;
        adjacentList[ID].resize(degree);
        for (int j = 0; j < degree; j++)
        {
            cin >> adjacentList[ID][j];
        }
    }
    generation.push(1);
    int level = 1, _level = 1, count = 1, _count = 0, largestNum = 1, end = 1, _end = 1;
    while (!generation.empty())
    {
        ID = generation.front();
        generation.pop();
        for (int i = 0; i < adjacentList[ID].size(); i++)
        {
            _end = adjacentList[ID][i];
            _count++;
            generation.push(_end);
        }
        if (ID == end)
        {
            if (count > largestNum)
            {
                level = _level;
                largestNum = count;
            }
            _level++;
            count = _count;
            _count = 0;
            end = _end;
        }
    }
    cout << largestNum << " " << level;
    return 0;
}