#include<bits/stdc++.h> 
using namespace std;

int n;
vector<int> key;
vector<int> path;

void print()
{
    for (int i = 0;  i < path.size(); i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << path[i];
    }
    cout << endl;
}

bool traverse(int index, bool type)
{
    bool res = true;
    path.push_back(key[index]);
    int right = (index << 1) + 2;
    if (right < key.size())
    {
        res = type ? (key[index] > key[right] & key[index] > key[right - 1]) : (key[index] < key[right] & key[index] < key[right - 1]);
        res &= traverse(right, type) & traverse(right - 1, type);
    }
    else if (right == key.size())
    {
        res = type ? (key[index] > key[right - 1]) : (key[index] < key[right - 1]);
        res &= traverse(right - 1, type);
    }
    else
    {
        print();
    }
    path.pop_back();
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.txt", "r", stdin);
#endif
    cin >> n;
    key.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> key[i];
    }
    if (key[0] > key[1] && traverse(0, true))
    {
        cout << "Max Heap" << endl;
    }
    else if (key[0] < key[1] && traverse(0, false))
    {
        cout << "Min Heap" << endl;
    }
    else
    {
        cout << "Not Heap" << endl;
    }
    return 0;
}