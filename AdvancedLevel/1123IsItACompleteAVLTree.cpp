#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key, height;
    Node *left, *right;
    Node()
    {
        left = right = nullptr;
        height = 0;
    }
}*Tree;

int Height(Tree T)
{
    if (T == nullptr)
    {
        return -1;
    }
    return T->height;
}

Tree leftRotate(Tree T)
{
    Tree leftChild = T->left;
    T->left = leftChild->right;
    leftChild->right = T;
    T->height = max(Height(T->left), Height(T->right)) + 1;
    leftChild->height = max(Height(T->left), T->height) + 1;
    return leftChild;
}

Tree rightRotate(Tree T)
{
    Tree rightChild = T->right;
    T->right = rightChild->left;
    rightChild->left = T;
    T->height = max(Height(T->left), Height(T->right)) + 1;
    rightChild->height = max(T->height, Height(T->right)) + 1;
    return rightChild;
}

Tree leftRightRotate(Tree T)
{
    T->left = rightRotate(T->left);
    return leftRotate(T);
}

Tree rightLeftRotate(Tree T)
{
    T->right = leftRotate(T->right);
    return rightRotate(T);
}

Tree insert(int key, Tree T)
{
    if (T == nullptr)
    {
        T = new Node;
        T->key = key;
    }
    else if (key < T->key)
    {
        T->left = insert(key, T->left);
        if (Height(T->left) - Height(T->right) == 2)
        {
            if (key < T->left->key)
            {
                T = leftRotate(T);
            }
            else
            {
                T = leftRightRotate(T);
            }
        }
    }
    else if (key > T->key)
    {
        T->right= insert(key, T->right);
        if (Height(T->left) - Height(T->right) == -2)
        {
            if (key > T->right->key)
            {
                T = rightRotate(T);
            }
            else
            {
                T = rightLeftRotate(T);
            }
        }
    }
    T->height = max(Height(T->left), Height(T->right)) + 1;
    return T;
}

int main()
{
    Tree T = nullptr, _T;
    int N, key, count = 1;
    bool flag = true;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> key;
        T = insert(key, T);
    }
    queue<Tree> levelorder;
    vector<int> data;
    levelorder.push(T);
    while (!levelorder.empty())
    {
        _T = levelorder.front();
        levelorder.pop();
        data.push_back(_T->key);
        if (_T->left != nullptr)
        {
            levelorder.push(_T->left);
            if (flag) count++;
        }
        else
        {
            flag = false;
        }
        if (_T->right != nullptr)
        {
            levelorder.push(_T->right);
            if (flag) count++;
        }
        else
        {
            flag = false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << data[i];
    }
    cout << endl << (count == N ? "YES" : "NO") << endl;
    return 0;
}