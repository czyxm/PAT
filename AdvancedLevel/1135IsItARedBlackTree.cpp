#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key, BH;
    bool color;
    Node *left, *right;
    Node()
    {
        left = right = nullptr;
    }
}*Tree;

bool isRedBlackTree;

Tree insert(int key, Tree T)
{
    if (T == nullptr)
    {
        T = new Node;
        T->color = (key > 0 ? true : false);
        T->key = abs(key);
    }
    else if (abs(key) < T->key)
    {
        T->left = insert(key, T->left);
        if (!T->color && !T->left->color)
        {
            isRedBlackTree = false;
        }
    }
    else if (abs(key) > T->key)
    {
        T->right = insert(key, T->right);
        if (!T->color && !T->right->color)
        {
            isRedBlackTree = false;
        }
    }
    return T;
}

void checkBH(Tree T)
{
    if (!isRedBlackTree)
    {
        return;
    }
    if (T->left != nullptr && T->right != nullptr)
    {
        checkBH(T->left);
        checkBH(T->right);
        if (T->left->BH != T->right->BH)
        {
            isRedBlackTree = false;
        }
        else
        {
            T->BH = T->color ? T->left->BH + 1 : T->left->BH;
        }
    }
    else if (T->left != nullptr && T->right == nullptr)
    {
        checkBH(T->left);
        if (T->left->BH > 0)
        {
            isRedBlackTree = false;
        }
        else
        {
            T->BH = T->color ? 1 : 0;
        }
    }
    else if (T->left == nullptr && T->right != nullptr)
    {
        checkBH(T->right);
        if (T->right->BH > 0)
        {
            isRedBlackTree = false;
        }
        else
        {
            T->BH = T->color ? 1 : 0;
        }
    }
    else
    {
        T->BH = T->color ? 1 : 0;
    }
}

int main()
{
    int K, N, key;
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        Tree T = nullptr;
        cin >> N;
        isRedBlackTree = true;
        for (int j = 1; j <= N; j++)
        {
            cin >> key;
            T = insert(key, T);
        }
        if (!T->color)
        {
            isRedBlackTree = false;
        }
        if (isRedBlackTree)
        {
            checkBH(T);
        }
        cout << (isRedBlackTree ? "Yes" : "No") << endl;
    }
    return 0;
}