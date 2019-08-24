#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
 1. Each step try to place one number at the right position by swap(0, i) until i == 0
 2. If i == 0 but there is number not at the right position then find it (like at j) and swap(0, j), go on the step 1
 swap(0, i) need to find the number i that not at the right position, actually we can directly place the number at index 0 to its right position i
 */
int main()
{
    vector<int> sequence;
    set<int> wrong;
    int N, index, temp, step = 0;
    cin >> N;
    sequence.resize(N);
    for (int i = 0; i < N; i++
    )
    {
        cin >> sequence[i];
        if (sequence[i] != i && i != 0)
        {
            wrong.insert(i);
        }
    }
    while (wrong.size() > 0)
    {
        if (sequence[0] != 0)
        {
            index = sequence[0];
            sequence[0] = sequence[index];
            sequence[index] = index;
            wrong.erase(index);
        }
        else
        {
            index = *wrong.begin();
            sequence[0] = sequence[index];
            sequence[index] = 0;
        }
        step++;
    }
    cout << step;
    return 0;
}