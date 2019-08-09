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