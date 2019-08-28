#include<bits/stdc++.h>
using namespace std;

vector<int> preorder, inorder, postorder;
void f(int inStart, int inEnd, int preStart, int preEnd)
{
    if (inStart > inEnd)
    {
        return;
    }
    int pos = inStart;
    while (preorder[preStart] != inorder[pos])
    {
        pos++;
    }
    f(inStart, pos - 1, preStart + 1, preStart + pos - inStart);
    f(pos + 1, inEnd, preStart + pos - inStart + 1, preEnd);
    postorder.push_back(preorder[preStart]);
}

int main()
{
    int N, number;
    string operation;
    vector<int> stack;
    cin >> N;
    for (int i = 1; i <= N << 1; i++)
    {
        cin >> operation;
        if (operation[1] == 'u')
        {
            cin >> number;
            stack.push_back(number);
            preorder.push_back(number);
        }
        else
        {
            inorder.push_back(stack.back());
            stack.pop_back();
        }
    }
    f(0, N - 1, 0, N - 1);
    for (int i = 0; i < postorder.size(); i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << postorder[i];
    }
    return 0;
}