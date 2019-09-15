#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> _heap, path;

void print()
{
    for (int & i : path)
    {
        cout << i;
        if (i != path.back())
        {
            cout << " ";
        }
    }
    cout << endl;
}

bool check(int index, bool type)
{
    int left = (index << 1) + 1;
    bool res = true;
    path.push_back(_heap[index]);
    if (left + 1 < N)
    {
        res &= check(left + 1, type);
        res &= check(left, type);
        if (type && (_heap[index] < _heap[left] || _heap[index] < _heap[left + 1]))
        {
            res = false;
        }
        else if (!type && (_heap[index] > _heap[left] || _heap[index] > _heap[left + 1]))
        {
            res = false;
        }
    }
    else if (left + 1 == N)
    {
        res &= check(left, type);
        if (type && _heap[index] < _heap[left])
        {
            res = false;
        }
        else if (!type && _heap[index] > _heap[left])
        {
            res = false;
        }
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
    int minIndex = 0, maxIndex = 0;
    bool flag = true;
    cin >> N;
    _heap.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> _heap[i];
        if (_heap[i] > _heap[maxIndex])
        {
            maxIndex = i;
        }
        if (_heap[i] < minIndex)
        {
            minIndex = i;
        }
    }
    if (maxIndex == 0)
    {
        if (check(0, true))
        {
            cout << "Max Heap" << endl;
        }
        else
        {
            flag = false;
        }
    }
    else if (minIndex == 0)
    {
        if (check(0, false))
        {
            cout << "Min Heap" << endl;
        }
        else
        {
            flag = false;
        }
    }
    else
    {
        check(0, true);
        flag = false;
    }
    if (!flag)
    {
        cout << "Not Heap" << endl;
    }
    return 0;
}