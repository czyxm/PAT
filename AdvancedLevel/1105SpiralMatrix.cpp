#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, m, n, count, x, y, forward = 1;
    vector<int> sequence;
    int matrix[500][500] = {-1};
    cin >> N;
    sequence.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }
    sort(sequence.begin(), sequence.end(), greater<int>());
    for (n = int(sqrt(N)); n >= 1; n--)
    {
        if (N % n == 0)
        {
            m = N / n;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = -1;
        }
    }
    x = y = 0;
    count = 0;
    do
    {
        matrix[x][y] = sequence[count++];
        switch (forward)
        {
            case 1:
                if (matrix[x][y + 1] == -1)
                {
                    y++;
                }
                else
                {
                    x++;
                    forward = 2;
                }
            break;
            case 2:
                if (matrix[x + 1][y] == -1)
                {
                    x++;
                }
                else
                {
                    y--;
                    forward = 3;
                }
            break;
            case 3:
                if (matrix[x][y - 1] == -1)
                {
                    y--;
                }
                else
                {
                    x--;
                    forward = 4;
                }
            break;
            case 4:
                if (matrix[x - 1][y] == -1)
                {
                    x--;
                }
                else
                {
                    y++;
                    forward = 1;
                }
            break;
        }
    }while (count < N);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != 0)
            {
                cout << " ";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}