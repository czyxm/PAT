#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, res;
    double length = 0.0;
    vector<int> rope;
    cin >> N;
    rope.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end(), less<int>());
    length = rope[0];
    for (int i = 1; i < N; i++)
    {
        length = (length + rope[i]) / 2.0;
    }
    res = min(int(length), rope[N - 1]);
    cout << res;
    return 0;
}