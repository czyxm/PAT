#include<iostream>
#include<set>
using namespace std;

int main()
{
    char S1[10001] = {'\0'}, ch;
    set<char> S2;
    cin.getline(S1, 10001, '\n');
    while((ch = getchar()) != '\n')
    {
        S2.insert(ch);
    }
    for (int i = 0; S1[i]; i++)
    {
        if (S2.find(S1[i]) == S2.end())
        {
            cout << S1[i];
        }
    }
    return 0;
}