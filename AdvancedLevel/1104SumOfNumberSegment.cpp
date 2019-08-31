#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    double number, sum = 0.00;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> number;
        sum += number * (i + 1) * (N - i);
    }
    cout << fixed << setprecision(2) << sum;
    return 0;
}