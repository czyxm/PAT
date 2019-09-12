#include<bits/stdc++.h>
using namespace std;

void postfix(int index, vector<int> & _heap)
{
    if (index >= _heap.size())
    {
        return;
    }
    int left = (index << 1) + 1;
    if (left < _heap.size())
    {
        postfix(left, _heap);
    }
    if (left + 1 < _heap.size())
    {
        postfix(left + 1, _heap);
    }
    cout << _heap[index];
    if (index != 0)
    {
        cout << " ";
    }
}

bool compare(int a, int b, bool flag)
{
    return flag ? a >= b : a <= b;
}

bool checkHeap(int index, bool flag, vector<int> & _heap)
{
    bool res = true;
    int left = (index << 1) + 1;
    if (left < _heap.size())
    {
        res &= compare(_heap[index], _heap[left], flag) ? checkHeap(left, flag, _heap) : false;
    }
    if (left + 1 < _heap.size())
    {
        res &= compare(_heap[index], _heap[left + 1], flag) ? checkHeap(left + 1, flag, _heap) : false;
    }
    return res;
}

int main()
{
    int M, N;
    cin >> M >> N;
    for (int i = 1; i <= M; i++)
    {
        vector<int> _heap(N, 0);
        int maxIndex = 0, minIndex = 0;
        for (int j = 0; j < N; j++)
        {
            cin >> _heap[j];
            if (_heap[j] > _heap[maxIndex])
            {
                maxIndex = j;
            }
            if (_heap[j] < _heap[minIndex])
            {
                minIndex = j;
            }
        }
        if (0 == maxIndex && checkHeap(0, true, _heap))
        {
            cout << "Max Heap" << endl;
        }
        else if (0 == minIndex && checkHeap(0, false, _heap))
        {
            cout << "Min Heap" << endl;
        }
        else
        {
            cout << "Not Heap" << endl;
        }
        postfix(0, _heap);
        cout << endl;
    }
    return 0;
}