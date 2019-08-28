#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, isMerge = 1, index, _index = 0, number, scale, flag = 0;
    vector<int> sequence, sortedSequence;
    cin >> N;
    scale = N;
    sequence.resize(N);
    sortedSequence.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> sortedSequence[i];
        if (i >= 1 && sortedSequence[i] < sortedSequence[i - 1])
        {
            if (i % 2 == 1)
            {
                isMerge = 0;
            }
            else
            {
                scale = i - _index < scale ? i - _index : scale;
                _index = i;
            }
            if (!flag)
            {
                flag = 1;
                index = i;
            }
        }
    }
    if (isMerge)
    {
        cout << "Merge Sort" << endl;
        scale <<= 1;
        index = 0;
        while (index + scale < N)
        {
            sort(sortedSequence.begin() + index, sortedSequence.begin() + index + scale, less<int>());
            index += scale;
        }
        sort(sortedSequence.begin() + index, sortedSequence.end(), less<int>());
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