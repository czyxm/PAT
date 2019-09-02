#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, Q, birdNum, treeNum = 0, b1, b2, t;
    vector<int> tree[10001];
    vector<int> bird[10001];
    int belong[10001];
    map<int, bool> known;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        if (K > 0)
        {
            tree[i].resize(K);
        }
        for (int j = 0; j < K; j++)
        {
            cin >> tree[i][j];
            bird[tree[i][j]].push_back(i);
            known.insert(pair<int, bool>(tree[i][j], false));
        }
    }
    while (true)
    {
        b1 = -1;
        for (auto begin = known.begin(); begin != known.end(); begin++)
        {
            if (!begin->second)
            {
                b1 = begin->first;
                break;
            }
        }
        if (b1 == -1)
        {
            break;
        }
        queue<int> birdsInOneTree;
        birdsInOneTree.push(b1);
        known[b1] = true;
        while (!birdsInOneTree.empty())
        {
            b1 = birdsInOneTree.front();
            belong[b1] = treeNum;
            birdsInOneTree.pop();
            for (int i = 0; i < bird[b1].size(); i++)
            {
                t = bird[b1][i];
                for (int j = 0; j < tree[t].size(); j++)
                {
                    b2 = tree[t][j];
                    if (!known[b2])
                    {
                        birdsInOneTree.push(b2);
                        known[b2] = true;
                    }
                }
            }
        }
        treeNum++;
    }
    cout << treeNum << " " << known.size() << endl;
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> b1 >> b2;
        if (belong[b1] == belong[b2])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}