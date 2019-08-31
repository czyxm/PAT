#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, K = 0;
    double sum = 0.00;
    string str;
    smatch sm;
    regex pattern("^(\\-?\\d+)(\\.\\d{0,2})?$");
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> str;
        if (regex_match(str, pattern) && abs(stof(str)) <= 1000)
        {
            K++;
            sum += stof(str);
        }
        else
        {
            cout << "ERROR: " << str << " is not a legal number" << endl;
        }
    }
    if (K == 0)
    {
        cout << "The average of 0 numbers is Undefined" << endl;
    }
    else if (K == 1)
    {
        cout << "The average of 1 number is " << fixed << setprecision(2) << sum << endl;
    }
    else
    {
        cout << "The average of " << K << " numbers is " << fixed << setprecision(2) << sum / K << endl;
    }
    return 0;
}