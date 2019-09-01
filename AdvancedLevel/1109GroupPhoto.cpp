#include<bits/stdc++.h>
using namespace std;

struct People
{
    char name[10];
    int height;
};

vector<People> people;

bool compare(const People & p1, const People & p2)
{
    if (p1.height == p2.height)
    {
        return strcmp(p1.name, p2.name) < 0;
    }
    return p1.height > p2.height;
}

void displayRow(int m)
{
    static int start = 0;
    bool flag = true;
    int count = 1, index, mid = m >> 1;
    vector<int> order(m, 0);
    order[mid] = start;
    for (int i = start + 1; i < start + m; i++)
    {
        index = flag ? mid - count : mid + count;
        if (!flag)
        {
            count++;
        }
        flag = !flag;
        order[index] = i;
    }
    for (int i = 0; i < m; i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << people[order[i]].name;
    }
    cout << endl;
    start += m;
}

int main()
{
    int N, K, M, _M;
    cin >> N >> K;
    people.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> people[i].name >> people[i].height;
    }
    sort(people.begin(), people.end(), compare);
    M = (N + (K >> 1)) / K;
    _M = N % K;
    if (_M > 0)
    {
        displayRow(_M + M);
        K--;
    }
    for (int i = 1; i <= K; i++)
    {
        displayRow(M);
    }
    return 0;
}