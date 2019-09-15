#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    int m = (int)sqrt(n);
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int L, K, N;
    bool flag = false;
    string str;
    cin >> L >> K >> str;
    for (int i = 0; i <= str.size() - K && i <= L - K; i++)
    {
        N = stoi(str.substr(i, K));
        if (isPrime(N))
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << setw(K) << setfill('0') << N;
    }
    else
    {
        cout << 404;
    }
    return 0;
}