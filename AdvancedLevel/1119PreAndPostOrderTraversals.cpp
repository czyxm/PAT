#include<bits/stdc++.h>
using namespace std;

vector<int> preorder, postorder, inorder;

bool find(int left1, int right1, int left2, int right2)
{
    if (left1 == right1)
    {
        inorder.push_back(preorder[left1]);
        return true;
    }
    else if (left1 > right1)
    {
        return false;
    }
    bool res;
    int root = preorder[left1];
    int index1, index2;
    for (int i = left2; i < right2; i++)
    {
        if (postorder[i] == preorder[left1 + 1])
        {
            index2 = i;
            index1 = index2 - left2 + left1 + 1;
            break;
        }
    }
    res = find(left1 + 1, index1, left2, index2);
    inorder.push_back(root);
    res &= find(index1 + 1, right1, index2 + 1, right2 - 1);
    return res;
}

int main()
{
    int N;
    cin >> N;
    preorder.resize(N);
    postorder.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> preorder[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> postorder[i];
    }
    if (find(0, N - 1, 0, N - 1))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << inorder[i];
    }
    cout << endl;
    return 0;
}