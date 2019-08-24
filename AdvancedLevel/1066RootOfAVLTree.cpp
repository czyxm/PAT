#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef struct TreeNode
{
    int key, height;
    TreeNode *left, *right;
}* TNode;

int Height(TNode T)
{
    return T == nullptr ? -1 : T->height;
}

TNode singleLeftRotate(TNode T)
{
    TNode leftChild = T->left;
    T->left = leftChild->right;
    leftChild->right = T;
    T->height = fmax(Height(T->left), Height(T->right)) + 1;
    leftChild->height = fmax(Height(leftChild->left), T->height) + 1;
    return leftChild;
}

TNode singleRightRotate(TNode T)
{
    TNode rightChild = T->right;
    T->right = rightChild->left;
    rightChild->left = T;
    T->height = fmax(Height(T->left), Height(T->right)) + 1;
    rightChild->height = fmax(Height(rightChild->right), T->height) + 1;
    return rightChild;
}

TNode leftRightRotate(TNode T)
{
    T->left = singleRightRotate(T->left);
    return singleLeftRotate(T);
}

TNode rightLeftRotate(TNode T)
{
    T->right = singleLeftRotate(T->right);
    return singleRightRotate(T);
}

TNode insert(int key, TNode T)
{
    if (T == nullptr)
    {
        T = new TreeNode;
        T->key = key;
        T->left = T->right = nullptr;
    }
    else if (key < T->key)
    {
        T->left = insert(key, T->left);
        if (Height(T->left) - Height(T->right) == 2)
        {
            if (key < T->left->key)
            {
                T = singleLeftRotate(T);
            }
            else
            {
                T = leftRightRotate(T);
            }
        }
    }
    else
    {
        T->right = insert(key, T->right);
        if (Height(T->left) - Height(T->right) == -2)
        {
            if (key >= T->right->key)
            {
                T = singleRightRotate(T);
            }
            else
            {
                T = rightLeftRotate(T);
            }
        }
    }
    T->height = fmax(Height(T->left), Height(T->right)) + 1;
    return T;
}

int main()
{
    TNode tree = nullptr;
    int N, key;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> key;
        tree = insert(key, tree);
    }
    cout << tree->key << endl;
    return 0;
}