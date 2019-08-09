#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> stack, sequence;
    int M, N, K, num;
    bool possible;
    cin >> M >> N >> K;
    sequence.resize(N);
    for (int i = 1; i <= K; i++)
    {
        num = 0;
        possible = true;
        stack.clear();
        for (int j = 0; j < N; j++)
        {
            cin >> sequence[j];
            if (num < sequence[j])
            {
                if (sequence[j] - num <= M - stack.size())
                {
                    for (int k = num + 1; k < sequence[j]; k++)
                    {
                        stack.push_back(k);
                    }
                    num = sequence[j];
                }
                else
                {
                    possible = false;
                }
            }
            else if (num > sequence[j])
            {
                if (sequence[j] != stack.back())
                {
                    possible = false;
                }
                stack.pop_back();
            }
            else
            {
                possible = false;
            }
        }
        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}