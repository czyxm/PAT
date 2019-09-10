#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key;
    Node *left, *right;
    Node(int key):key(key), left(nullptr), right(nullptr){}
}*Tree;

vector<int> preorder;

Tree insert(int l, int r, Tree T)
{
    if (l > r)
    {
        return nullptr;
    }
    T = new Node(preorder[l]);
    int pos = l + 1;
    while (pos <= r && preorder[pos] < preorder[l])
    {
        pos++;
    }
    T->left = insert(l + 1, pos - 1, T->left);
    T->right = insert(pos, r, T->right);
    return T;
}

vector<int> path1, path2;

bool find(int key, Tree T, vector<int> & path)
{
    if (T == nullptr)
    {
        return false;
    }
    else
    {
        path.push_back(T->key);
        if (key < T->key)
        {
            return find(key, T->left, path);
        }
        else if (key > T->key)
        {
            return find(key, T->right, path);
        }
        else
        {
            return true;
        }
    }
}

int main()
{
    Tree T = nullptr;
    int M, N, A, B, U;
    cin >> M >> N;
    preorder.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> preorder[i];
    }
    T = insert(0, N - 1, T);
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
        path1.clear();
        path2.clear();
    }
    
    return 0;
}