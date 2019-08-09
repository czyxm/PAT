#include<iostream>
#include<map>
#include<cmath>
using namespace std;

bool isPrime(long num)
{
    if (num == 2)
    {
        return true;
    }
    long half = (long)(sqrt(num));
    for (int i = 2; i <= half; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long N, M, _factor;
    map<long, int> factor;
    cin >> N;
    cout << N << "=";
    if (N == 1)
    {
        cout << "1";
        return 0;
    }
    while (N > 1)
    {
        M = N >> 1;
        _factor = N;
        for (long i = 2; i <= M; i++)
        {
            if (N % i == 0 && isPrime(i))
            {
                _factor = i;
                break;
            }
        }
        factor[_factor]++;
        N /= _factor;
    }
    for (auto begin = factor.begin(), end = factor.end(); begin != end;)
    {
        cout << begin->first;
        if (begin->second > 1)
        {
            cout << "^" << begin->second;
        }
        if (++begin != end)
        {
            cout << "*";
        }
    }
    return 0;
}