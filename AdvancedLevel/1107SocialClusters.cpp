#include<bits/stdc++.h>
using namespace std;

set<int> _cluster;
bool known[1001] = {false};
vector<int> hobbyList[1001], cluster[1001], solution;

void DFS(int people)
{
    known[people] = true;
    _cluster.insert(people);
    for (int i = 0; i < hobbyList[people].size(); i++)
    {
        int hobby = hobbyList[people][i];
        for (int j = 0; j < cluster[hobby].size(); j++)
        {
            if (!known[cluster[hobby][j]])
            {
                DFS(cluster[hobby][j]);
            }
        }
    }
}

int main()
{
    int N, degree, hobby, people;
    char ch;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> degree >> ch;
        for (int j = 1; j <= degree; j++)
        {
            cin >> hobby;
            hobbyList[i].push_back(hobby);
            cluster[hobby].push_back(i);
        }
    }
    while (true)
    {
        people = -1;
        for (int i = 1; i <= N; i++)
        {
            if (!known[i])
            {
                people = i;
                break;
            }
        }
        if (people == -1)
        {
            break;
        }
        _cluster.clear();
        DFS(people);
        solution.push_back(_cluster.size());
    }
    cout << solution.size() << endl;
    auto begin = solution.begin(), end = solution.end();
    sort(begin, end, greater<int>());
    while (begin != end)
    {
        cout << *(begin++);
        if (begin != end)
        {
            cout << " ";
        }
    }
    return 0;
}