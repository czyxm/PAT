#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key;
    Node *left, *right;
    Node()
    {
        left = right = nullptr;
    }
}*Tree;

int N;
vector<int> inorder, postorder, levelorder;

Tree build(int iLeft, int iRight, int pLeft, int pRight)
{
    if (iLeft > iRight)
    {
        return nullptr;
    }
    int pos = iLeft;
    while (inorder[pos] != postorder[pRight])
    {
        pos++;
    }
    Tree T = new Node;
    T->key = inorder[pos];
    T->left = build(iLeft, pos - 1, pLeft, pLeft + pos - iLeft - 1);
    T->right = build(pos + 1, iRight, pLeft + pos - iLeft, pRight - 1);
    return T;
}

int main()
{
    cin >> N;
    inorder.resize(N);
    postorder.resize(N);
    levelorder.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> inorder[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> postorder[i];
    }
    Tree T = build(0, N - 1, 0, N - 1), _T;
    queue<Tree> node;
    vector<int> levelKey;
    int count, level = 0;
    node.push(T);
    while (!node.empty())
    {
        count = node.size();
        while (count > 0)
        {
            _T = node.front();
            node.pop();
            levelKey.push_back(_T->key);
            if (_T->left != nullptr)
            {
                node.push(_T->left);
            }
            if (_T->right != nullptr)
            {
                node.push(_T->right);
            }
            count--;
        }
        if (level == 0)
        {
            cout << levelKey[0];
        }
        else if ((level & 1) == 1)
        {
            for (int i = 0; i < levelKey.size(); i++)
            {
                cout << " " << levelKey[i];
            }
        }
        else
        {
            for (int i = levelKey.size() - 1; i >= 0; i--)
            {
                cout << " " << levelKey[i];
            }
        }
        level++;
        levelKey.clear();
    }
    return 0;
}