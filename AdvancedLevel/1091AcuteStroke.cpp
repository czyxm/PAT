#include<bits/stdc++.h>
using namespace std;

int _slice[60][1286][128];
int M, N, L, T;

struct Point
{
    int z, x, y;
    Point(){}
    Point (int z, int x, int y):z(z), x(x), y(y){}
};
//DFS will lead to segment error because of too deep recursion
void BFS(int z, int x, int y, int & volumn)
{
    queue<Point> points;
    points.push(Point(z, x, y));
    while (!points.empty())
    {
        z = points.front().z;
        x = points.front().x;
        y = points.front().y;
        points.pop();
        if (_slice[z][x][y] == 1)
        {
            volumn++;
            _slice[z][x][y] = 0;
            if (z > 0)     points.push(Point(z - 1, x, y));
            if (z < L - 1) points.push(Point(z + 1, x, y));
            if (x > 0)     points.push(Point(z, x - 1, y));
            if (x < M - 1) points.push(Point(z, x + 1, y));
            if (y > 0)     points.push(Point(z, x, y - 1));
            if (y < N - 1) points.push(Point(z, x, y + 1));
        }
    }
}

int main()
{
    int volumn, totalVolumn = 0;
    cin >> M >> N >> L >> T;
    for (int k = 0; k < L; k++)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> _slice[k][i][j];
            }
        }
    }
    for (int k = 0; k < L; k++)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (_slice[k][i][j] == 1)
                {
                    BFS(k, i, j, volumn = 0);
                    totalVolumn += volumn >= T ? volumn : 0;
                }
            }
        }
    }
    cout << totalVolumn;
    return 0;
}