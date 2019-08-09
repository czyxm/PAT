#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#define MAXSIZE 100001
#define SQRSIZE 320
using namespace std;

int block[SQRSIZE] = {0};
int table[MAXSIZE] = {0};

int main()
{
    vector<int> stack, _stack;
    string command;
    int i, j, N, key, k, index, sum, left, right;
    cin >> N;
    for (i = 1; i <= N; i++)
    {
        cin >> command;
        if (command == "Push")
        {
            cin >> key;
            table[key]++;
            block[key / SQRSIZE]++;
            stack.push_back(key);
        }
        else if (command == "Pop" && stack.size() > 0)
        {
            key = stack.back();
            cout << key << endl;
            table[key]--;
            block[key / SQRSIZE]--;
            stack.pop_back();
        }
        else if (command == "PeekMedian" && stack.size() > 0)
        {
            k = stack.size();
            if ((k & 1) == 1){k++;}
            k >>= 1;
            sum = 0;
            for (j = 0; j < SQRSIZE && sum + block[j] < k; j++)
            {
                sum += block[j];
            }
            index = SQRSIZE * j;
            while (sum < k)
            {
                sum += table[index++];
            }
            cout << index - 1 << endl;
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}