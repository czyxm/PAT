#include<iostream>
#include<string>
using namespace std;

void standardize(string & str)
{
    if (str[0] == '-')
    {
        str = "-" + string(21 - str.size(), '0') + str.substr(1);
    }
    else
    {
        str = "+" + string(20 - str.size(), '0') + str;
    }
}

string add(const string & A, const string & B)
{
    string C;
    C.resize(21);
    int carry = 0, digit;
    if (A[0] == B[0])
    {
        for (int i = 20; i >= 1; i--)
        {
            digit = A[i] - '0' + B[i] - '0' + carry;
            if (digit >= 10)
            {
                carry = 1;
                digit -= 10;
            }
            else
            {
                carry = 0;
            }
            C[i] = digit + '0';
        }
        C[0] = A[0];
    }
    else
    {
        if (A.substr(1) < B.substr(1))
        {
            C = add(B, A);
        }
        else if (A.substr(1) > B.substr(1))
        {
            for (int i = 20; i >= 1; i--)
            {
                digit = A[i] - B[i] - carry;
                if (digit < 0)
                {
                    carry = 1;
                    digit = -digit;
                }
                else
                {
                    carry = 0;
                }
                C[i] = digit + '0';
            }
            C[0] = A[0];
        }
        else
        {
            C = "+0";
        }
    }
    return C;
}

int main()
{
    string A, B, C;
    int N;
    bool flag;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A >> B >> C;
        standardize(A);
        standardize(B);
        standardize(C);
        A = add(A, B);
        if (A[0] == C[0])
        {
            flag = A[0] == '+' ? A > C : A < C;
        }
        else
        {
            flag = A[0] == '+';
        }
        cout << "Case #" << i << ": " << (flag ? "true" : "false") << endl;
    }
    return 0;
}