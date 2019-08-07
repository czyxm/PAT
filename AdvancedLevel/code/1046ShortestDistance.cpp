#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> distance;
    int N, M, source, target, total = 0, shortestDistance;
    cin >> N;
    distance.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> distance[i];
        total += distance[i];
    }
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> source >> target;
        if (source > target)
        {
            swap(source, target);
        }
        shortestDistance = 0;
        for (int j = source - 1; j <= target - 2; j++)
        {
            shortestDistance += distance[j];
        }
        shortestDistance = shortestDistance < (total - shortestDistance) ? shortestDistance : total - shortestDistance;
        cout << shortestDistance << endl;
    }
    return 0;
}