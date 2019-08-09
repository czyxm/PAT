#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> preOrder, postOrder, mirrorPostOrder;
//BST check recursively
bool binaryCheck(int left, int right)
{
    postOrder.push_back(preOrder[left]);
    if (left == right)
    {
        return true;
    }
    int less, greater;
    for (less = left + 1; less <= right; less++)
    {
        if (preOrder[less] >= preOrder[left])
        {
            break;
        }
    }
    for (greater = less; greater <= right; greater++)
    {
        if (preOrder[greater] < preOrder[left])
        {
            break;
        }
    }
    //All the numbers are less or bigger than the root
    if (less > right || (less == left + 1 && greater > right))
    {
        return binaryCheck(left + 1, right);
    }
    //The former part of numbers are smaller than the root and the latter part bigger.
    if (greater > right)
    {
        return binaryCheck(less, right) && binaryCheck(left + 1, less - 1);
    }
    return false;
}
//Mirror BST check recursively
bool mirrorCheck(int left, int right)
{
    mirrorPostOrder.push_back(preOrder[left]);
    if (left == right)
    {
        return true;
    }
    int less, greater;
    for (greater = left + 1; greater <= right; greater++)
    {
        if (preOrder[greater] < preOrder[left])
        {
            break;
        }
    }
    for (less = greater; less <= right; less++)
    {
        if (preOrder[less] >= preOrder[left])
        {
            break;
        }
    }
    //All the numbers are less or bigger than the root
    if (greater > right || (greater == left + 1 && less > right))
    {
        return mirrorCheck(left + 1, right);
    }
    //The former part of numbers are bigger than the root and the latter part smaller.
    if (less > right)
    {
        return mirrorCheck(greater, right) && mirrorCheck(left + 1, greater - 1);
    }
    return false;
}

int main()
{
    int N, number;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> number;
        preOrder.push_back(number);
    }
    if (binaryCheck(0, preOrder.size() - 1))
    {
        cout << "YES" << endl;
        while (postOrder.size() > 0)
        {
            number = postOrder.back();
            cout << number;
            postOrder.pop_back();
            if (postOrder.size() > 0)
            {
                cout << " ";
            }
        }
    }
    else if (mirrorCheck(0, preOrder.size() - 1))
    {
        cout << "YES" << endl;
        while (mirrorPostOrder.size() > 0)
        {
            number = mirrorPostOrder.back();
            cout << number;
            mirrorPostOrder.pop_back();
            if (mirrorPostOrder.size() > 0)
            {
                cout << " ";
            }
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}