#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key, level;
    Node *left, *right;
}*Tree;
int maxlevel = 0, n1 = 0, n2 = 0;
Tree insert(int key, int level, Tree T)
{
    if (T == nullptr)
    {
        T = new Node;
        T->key = key;
        T->level = level;
        T->left = T->right = nullptr;
        if (level > maxlevel)
        {
            maxlevel = level;
        }
        return T;
    }
    if (key <= T->key)
    {
        T->left = insert(key, level + 1, T->left);
    }
    else
    {
        T->right = insert(key, level + 1, T->right);
    }
    return T;
}

void inorder(Tree T)
{
    if (T == nullptr)
    {
        return;
    }
    if (T->level == maxlevel)
    {
        n1++;
    }
    else if (T->level + 1 == maxlevel)
    {
        n2++;
    }
    inorder(T->left);
    inorder(T->right);
}

int main()
{
    int N, key;
    Tree T = nullptr, t;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> key;
        T = insert(key, 1, T);
    }
    inorder(T);
    cout << n1 << " + " << n2 << " = " << n1 + n2;
    return 0;
}