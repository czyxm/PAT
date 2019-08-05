#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct AccountNode
{
    string username;
    string password;
}* ANode;

int main()
{
    int N;
    bool isModified;
    string username, password;
    vector<ANode> modifiedAccount;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> username >> password;
        isModified = false;
        for (int j = 0; j < password.size(); j++)
        {
            switch (password[j])
            {
                case '1' : password[j] = '@'; isModified = true; break;
                case '0' : password[j] = '%'; isModified = true; break;
                case 'l' : password[j] = 'L'; isModified = true; break;
                case 'O' : password[j] = 'o'; isModified = true; break;
            }
        }
        if (isModified)
        {
            ANode newAccount = new AccountNode;
            newAccount->username = username;
            newAccount->password = password;
            modifiedAccount.push_back(newAccount);
        }
    }
    if (modifiedAccount.size() == 0)
    {
        if (N == 1)
        {
            cout << "There is 1 account and no account is modified" << endl;
        }
        else
        {
            cout << "There are " << N << " accounts and no account is modified" << endl;
        }
    }
    else
    {
        cout << modifiedAccount.size() << endl;
    }
    for (int i = 0; i < modifiedAccount.size(); i++)
    {
        cout << modifiedAccount[i]->username << " " << modifiedAccount[i]->password << endl;
    }
    return 0;
}