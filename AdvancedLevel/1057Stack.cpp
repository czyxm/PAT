#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int partition(int left, int right, vector<int> & array)
{
    int pivot = right;
    right--;
    while (left <= right)
    {
        while (left < pivot && array[left] <= array[pivot]) {left++;}
        while (right >= 0 && array[right] > array[pivot]) {right--;}
        if (left >= right)
        {
            break;
        }
        swap(array[left], array[right]);
    }
    swap(array[left], array[pivot]);
    return left;
}

int main()
{
    vector<int> stack, _stack;
    string command;
    int N, key, k, index, left, right;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> command;
        if (command == "Push")
        {
            cin >> key;
            stack.push_back(key);
        }
        else if (command == "Pop" && stack.size() > 0)
        {
            cout << stack.back() << endl;
            stack.pop_back();
        }
        else if (command == "PeekMedian" && stack.size() > 0)
        {
            k = stack.size();
            if ((k & 1) == 1){k++;}
            k >>= 1;
            k--;
            index = -1;
            left = 0;
            right = stack.size() - 1;
            _stack = stack;
            while (index != k)
            {
                index = partition(left, right, _stack);
                if (index < k)
                {
                    left = index + 1;
                }
                else if (index > k)
                {
                    right = index - 1;
                }
            }
            cout << _stack[k] << endl;
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}