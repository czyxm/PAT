#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key;
    Node *left, *right;
    Node(int key):key(key), left(nullptr), right(nullptr){}
}*Tree;

vector<int> preorder, inorder;
vector<int> path;

Tree insert(int l1, int r1, int l2, int r2, Tree T)
{
    if (l1 > r1)
    {
        return nullptr;
    }
    T = new Node(preorder[l1]);
    int pos = l2;
    while (pos <= r2 && preorder[l1] != inorder[pos])
    {
        pos++;
    }
    T->left = insert(l1 + 1, l1 + pos - l2, l2, pos - 1, T->left);
    T->right = insert(l1 + pos - l2 + 1, r1, pos + 1, r2, T->right);
    return T;
}

bool find(int key, Tree T, vector<int> & _path)
{
    bool res = false;
    if (T != nullptr)
    {
        
        path.push_back(T->key);
        if (key == T->key)
        {
            _path = path;
            res = true;
        }
        else
        {
            res |= find(key, T->left, _path);
            res |= find(key, T->right, _path);
        }
        path.pop_back();
    }
    return res;
}

int main()
{
    Tree T = nullptr;
    vector<int> path1, path2;
    int M, N, A, B, U;
    cin >> M >> N;
    preorder.resize(N);
    inorder.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> inorder[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> preorder[i];
    }
    T = insert(0, N - 1, 0, N - 1, T);
    for (int i = 1; i <= M; i++)
    {
        cin >> A >> B;
        bool found1 = find(A, T, path1);
        bool found2 = find(B, T, path2);
        if (found1 && found2)
        {
            int i = 0;
            while (i < path1.size() && i < path2.size() && path1[i] == path2[i])
            {
                U = path1[i++];
            }
            if (U == A)
            {
                cout << U << " is an ancestor of " << B << "." << endl;
            }
            else if (U == B)
            {
                cout << U << " is an ancestor of " << A << "." << endl;
            }
            else
            {
                cout << "LCA of " << A << " and " << B << " is " << U << "." << endl;
            }
        }
        else if (!found1 && found2)
        {
            cout << "ERROR: " << A << " is not found." << endl;
        }
        else if (found1 && !found2)
        {
            cout << "ERROR: " << B << " is not found." << endl;
        }
        else
        {
            cout << "ERROR: " << A << " and " << B << " are not found." << endl;
        }
        path.clear();
        path1.clear();
        path2.clear();
    }
    
    return 0;
}