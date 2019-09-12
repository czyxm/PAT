#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, num, index;
    vector<int> sequence;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        if (num > 0)
        {
            sequence.push_back(num);
        }
    }
    sort(sequence.begin(), sequence.end());
    num = 1;
    index = 0;
    while (index < sequence.size())
    {
        if (sequence[index] == num)
        {
            num++;
            index++;
        }
        else if (sequence[index] < num)
        {
            index++;
        }
        else
        {
            break;
        }
    }
    cout << num;
    return 0;
}