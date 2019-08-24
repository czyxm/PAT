#include<bits/stdc++.h>
using namespace std;
/*
 *Reduce the initial problem into a 0-1 bagpack problem regarding the target amount as the capacity of bag,
 the coins as objects with its value equals cost.
 */
int main()
{
    int N, M, f[101] = {0}, coin[10001] = {0};
    bool choose[10001][101] = {false};
    vector<int> solution;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> coin[i];
    }
    //Sort the coins in non-increasing order to find the smallest solution
    sort(coin + 1, coin + 1 + N, greater<int>());
    //0-1 bagpack DP
    for (int i = 1; i <= N; i++)
    {
        for (int j = M; j >= coin[i]; j--)
        {
            if (f[j] <= f[j - coin[i]] + coin[i])
            {
                f[j] = f[j - coin[i]] + coin[i];
                choose[i][j] = true;
            }
        }
    }
    if (f[M] == M)
    {
        int i = N, j = M;
        while (j > 0)
        {
            if (choose[i][j])
            {
                solution.push_back(coin[i]);
                j -= coin[i];
            }
            i--;
        }
        for (i = 0; i < solution.size(); i++)
        {
            if (i != 0)
            {
                cout << " ";
            }
            cout << solution[i];
        }
    }
    else
    {
        cout << "No Solution";
    }
    return 0;
}