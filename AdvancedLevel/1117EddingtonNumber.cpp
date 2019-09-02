#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, _E, E = 0, num, sum = 0;
    cin >> N;
    vector<int> mile(N + 2, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        if (num > N)
        {
            mile[N + 1]++;
        }
        else
        {
            mile[num]++;
        }
        
    }
    for (int i = N; i >= 1; i--)
    {
        sum += mile[i + 1];
        _E = min(sum, i);
        E = max(E, _E);
    }
    cout << E;
    return 0;
}