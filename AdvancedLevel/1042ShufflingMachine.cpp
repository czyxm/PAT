#include<iostream>
#include<string>
using namespace std;

int main()
{
    string cards[55], shadowCards[55];
    int randomOrder[55];
    int iteration;
    cin >> iteration;
    for (int i = 1; i <= 54; i++)
    {
        cin >> randomOrder[i];
        switch ((i - 1) / 13)
        {
            case 0 : cards[i] = "S" + to_string(i); break;
            case 1 : cards[i] = "H" + to_string(i - 13); break;
            case 2 : cards[i] = "C" + to_string(i - 26); break;
            case 3 : cards[i] = "D" + to_string(i - 39); break;
            case 4 : cards[i] = "J" + to_string(i - 52); break;
        }
    }
    for (int i = 1; i <= iteration; i++)
    {
        if ((i & 1) == 1)
        {
            for (int source = 1; source <= 54; source++)
            {
                shadowCards[randomOrder[source]] = cards[source];
            }
        }
        else
        {
            for (int source = 1; source <= 54; source++)
            {
                cards[randomOrder[source]] = shadowCards[source];
            }
        }
    }
    if ((iteration & 1) == 1)
    {
        for (int i = 1; i <= 54; i++)
        {
            cout << shadowCards[i];
            if (i < 54)
            {
                cout << " ";
            }
        }
    }
    else
    {
        for (int i = 1; i <= 54; i++)
        {
            cout << cards[i];
            if (i < 54)
            {
                cout << " ";
            }
        }
    }
    return 0;
}