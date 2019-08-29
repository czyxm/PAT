#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, number, index = 0, _index = N, flag = 0;
    vector<int> sequence, sortedSequence;
    cin >> N;
    sequence.resize(N);
    sortedSequence.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> sortedSequence[i];
        if (i >= 1)
        {
            if (sortedSequence[i] < sortedSequence[i - 1] && flag == 0)
            {
                index = i;
                flag = 1;
            }
            if (sortedSequence[i] < sortedSequence[0])
            {
                _index = i;
            }
        }
    }
    if (index <= 1)
    {
        cout << "Heap Sort" << endl;
        number = sortedSequence[_index];
        sortedSequence[_index] = sortedSequence[0];
        index = 0;
        int children;
        //Porcolate down
        while (index < _index)
        {
            children = (index << 1) + 1;
            if (children + 1 < _index && sortedSequence[children] < sortedSequence[children + 1])
            {
                children++;
            }
            if (children < _index && sortedSequence[children] > number)
            {
                sortedSequence[index] = sortedSequence[children];
                index = children;
            }
            else
            {
                break;
            }
        }
        sortedSequence[index] = number;
    }
    else
    {
        cout << "Insertion Sort" << endl;
        number = sortedSequence[index];
        while (index > 0)
        {
            if (sortedSequence[index - 1] >= number)
            {
                sortedSequence[index] = sortedSequence[index - 1];
                index--;
            }
            else
            {
                break;
            }
        }
        sortedSequence[index] = number;
    }
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << sortedSequence[i];
    }
    return 0;
}