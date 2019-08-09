#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> sequence;
    int N1, N2, number;
    cin >> N1;
    for (int i = 1; i <= N1; i++)
    {
        cin >> number;
        sequence.push(number);
    }
    cin >> N2;
    //Caculate the position of median
    N1 += N2;
    if (N1 & 1)
    {
        N1++;
    }
    N1 >>= 1;
    while (sequence.size() > N1)
    {
        sequence.pop();
    }
    for (int i = 1; i <= N2; i++)
    {
        cin >> number;
        sequence.push(number);
        if (sequence.size() > N1)
        {
            sequence.pop();
        }
    }
    cout << sequence.top();
    return 0;
}