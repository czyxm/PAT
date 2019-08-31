#include<bits/stdc++.h>
using namespace std;

int N, K, P, M, sum = 0, _sum = 0, resSum = 0;
vector<int> solution, res;
int power[401];

bool find(int level, int end)
{
    bool flag = false, found = false;
    if (sum < N && level < K)
    {
        for (int i = 1; i <= end; i++) //Prun [1,M] to [1,end] 
        {
            solution.push_back(i);
            sum += power[i];
            _sum += i;
            if (sum < N)
            {
                flag = find(level + 1, i);
                if (flag)
                {
                    found = true;
                }
            }
            else if (sum == N && level + 1 == K)
            {
                found = true;
                if (_sum >= resSum)
                {
                    resSum = _sum;
                    res = solution;
                }
            }
            solution.pop_back();
            sum -= power[i];
            _sum -= i;
        }
    }
    return found;
}

int main()
{
    cin >> N >> K >> P;
    M = int(pow(N, 1.0 / P));
    for (int i = 1; i <= M; i++)
    {
        power[i] = (int)pow(i, P);
    }
    if (find(0, M))
    {
        cout << N << " = ";
        for (int i = 0; i < K; i++)
        {
            if (i != 0)
            {
                cout << " + ";
            }
            cout << res[i] << "^" << P;
        }
    }
    else
    {
        cout << "Impossible";
    }
    return 0;
}