#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> coins;
    int N, M, face, min, max, middle;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> face;
        if (face < M)
        {
            coins.push_back(face);
        }
    }
    sort(coins.begin(), coins.end(), less<int>());
    for (int i = 0; i < coins.size(); i++)
    {
        min = i + 1;
        max = coins.size() - 1;
        while (min <= max)
        {
            middle = (min + max) / 2;
            if (coins[middle] < M - coins[i])
            {
                min = middle + 1;
            }
            else if (coins[middle] > M - coins[i])
            {
                max = middle - 1;
            }
            else
            {
                cout << coins[i] << " " << coins[middle];
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}