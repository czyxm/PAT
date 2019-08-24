#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sequence, levelOrder;
int N;

void insert(int pos)
{
    static int index = 0;
    if (pos > N)
    {
        return;
    }
    insert(2 * pos);
    levelOrder[pos] = sequence[index++];
    insert(2 * pos + 1);
}

int main()
{
    cin >> N;
    sequence.resize(N);
    levelOrder.resize(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }
    sort(sequence.begin(), sequence.end(), less<int>());
    insert(1);
    for (int i = 1; i <= N; i++)
    {
        cout << levelOrder[i];
        if (i < N)
        {
            cout << " ";
        }
    }
    return 0;
}