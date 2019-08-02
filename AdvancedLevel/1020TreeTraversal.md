# Tree Traversal
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.
### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.
### Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
### Sample Input:
```in
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
```
### Sample Output:
```out
4 1 6 3 5 7 2
```
### Solution
Considering the problem that requires prefix order given postfix order and infix order, I firstly figure out the prefix order and then find out the level order by means of prefix order and post order.

```C++
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
//Find the index of the element in the vector
int indexOf(int element, int left, int right, const vector<int> & array)
{
    for (int i = left; i <= right; i++)
    {
        if (element == array[i])
        {
            return i;
        }
    }
    return -1;
}

vector<int> postOrder, inOrder, preOrder;
queue<int> levelOrder;
//Split the inorder vector in prefix recursively
void split(int left, int postIndex, int inIndex, int right)
{
    if (left == right)
    {
        preOrder.push_back(inOrder[left]);
    }
    else if (left < right)
    {
        int index = postIndex - (right - inIndex) - 1;
        preOrder.push_back(postOrder[postIndex]);
        split(left, index, indexOf(postOrder[index], left, inIndex - 1, inOrder), inIndex - 1);
        split(inIndex + 1, postIndex - 1, indexOf(postOrder[postIndex - 1], inIndex + 1, right, inOrder), right);
    }
}

int main()
{
    int N, number, preIndex, postIndex;
    //Read input
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> number;
        postOrder.push_back(number);
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> number;
        inOrder.push_back(number);
    }
    split(0, N - 1, indexOf(postOrder.back(), 0, N -1, inOrder), N - 1);
    levelOrder.push(preOrder[0]);
    set<int> numbers;
    numbers.insert(preOrder[0]);
    bool flag = true;
    while (levelOrder.size() > 0)
    {
        number = levelOrder.front();
        if (flag)
        {
            cout << number;
            flag = false;
        }
        else
        {
            cout << " " << number;
        }
        levelOrder.pop();
        preIndex = indexOf(number, 0, N - 1, preOrder);
        postIndex = indexOf(number, 0, N - 1, postOrder);
        //Push the left child of data
        if (preIndex + 1 < preOrder.size() && numbers.find(preOrder[preIndex + 1]) == numbers.end())
        {
            levelOrder.push(preOrder[preIndex + 1]);
            numbers.insert(preOrder[preIndex + 1]);
        }
        //Push the right child of data
        if (postIndex > 0 && numbers.find(postOrder[postIndex - 1]) == numbers.end())
        {
            levelOrder.push(postOrder[postIndex - 1]);
            numbers.insert(postOrder[postIndex - 1]);
        }
    }
    return 0;
}
```