#include<bits/stdc++.h>
using namespace std;

vector<int> preorder, inorder;

int find(int pLeft, int pRight, int iLeft, int iRight)
{
    int pos = iLeft;
    while (inorder[pos] != preorder[pLeft])
    {
        pos++;
    }
    if (iLeft < pos)
    {
        return find(pLeft + 1, pLeft + pos  - iLeft, iLeft, pos - 1);
    }
    else if (pos < iRight)
    {
        return find(pRight + pos + 1 - iRight, pRight, pos + 1, iRight);
    }
    else
    {
        return inorder[pos];
    }
}

int main()
{
    int N, res;
    cin >> N;
    preorder.resize(N);
    inorder.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> preorder[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> inorder[i];
    }
    res = find(0, N - 1, 0, N - 1);
    cout << res;
    return 0;
}