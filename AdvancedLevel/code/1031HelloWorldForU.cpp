#include<iostream>
#include<string>
using namespace std;

int main()
{
    int N1, N2;
    string text;
    cin >> text;
    for (N2 = 3; N2 <= text.size(); N2++)
    {
        N1 = text.size() + 2 - N2;
        //Make sure N1 is even
        if ((N1 & 1) == 0)
        {
            N1 >>= 1;
            if (N1 <= N2)
            {
                break;
            }
        }
    }
    //Display the U-shape result
    for (int i = 0; i < N1 - 1; i++)
    {
        cout << text[i];
        for (int j = 1; j <= N2 - 2; j++)
        {
            cout << " ";
        }
        cout << text[text.size() - 1 - i] << endl;
    }
    for (int i = 0; i < N2; i++)
    {
        cout << text[N1 - 1 + i];
    }
    return 0;
}