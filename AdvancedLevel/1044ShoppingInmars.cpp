#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> diamond, sum, end, minSumIndex;
    int N, M, total = 0, index = 1;
    cin >> N >> M;
    diamond.resize(N + 1);
    sum.resize(N + 1);
    end.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> diamond[i];
        sum[i] = 0;
        total += diamond[i];
        while (total >= M)
        {
            sum[index] = total;
            end[index] = i;
            if (minSumIndex.size() == 0 || sum[index] == sum[minSumIndex.back()])
            {
                minSumIndex.push_back(index);
            }
            else if (sum[index] < sum[minSumIndex.back()])
            {
                minSumIndex.clear();
                minSumIndex.push_back(index);
            }
            total -= diamond[index];
            index++;
        }
    }
    for (int i = 0; i < minSumIndex.size(); i++)
    {
        cout << minSumIndex[i] << "-" << end[minSumIndex[i]] << endl;
    }
    return 0;
}