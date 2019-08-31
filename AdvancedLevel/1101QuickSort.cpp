#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    vector<long> data, minimum, maximum, solution;
    cin >> N;
    data.resize(N);
    minimum.resize(N);
    maximum.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> data[i];
        if (i == 0)
        {
            maximum[i] = data[i];
        }
        else
        {
            maximum[i] = max(maximum[i - 1], data[i]);
        }
    }
    minimum[N - 1] = data[N - 1];
    if (N == 1)
    {
        solution.push_back(data[0]);
    }
    else if (maximum[N - 2] < data[N - 1])
    {
        solution.push_back(data[N - 1]);
    }
    for (int i = N - 2; i >= 1; i--)
    {
        minimum[i] = min(minimum[i + 1], data[i]);
        if (maximum[i - 1] < data[i] && data[i] < minimum[i + 1])
        {
            solution.push_back(data[i]);
        }
    }
    if (N > 1 && data[0] < minimum[1])
    {
        solution.push_back(data[0]);
    }
    cout << solution.size() << endl;
    while (!solution.empty())
    {
        cout << solution.back();
        solution.pop_back();
        if (!solution.empty())
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}