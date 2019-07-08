#include<iostream>
#include<string>
using namespace std;
int main()
{
    int operand1, operand2, res;
    cin >> operand1 >> operand2;
    res = operand1 + operand2;
    string resStr = to_string(abs(res));
    for (int i = resStr.length() - 4; i >= 0; i -= 3)
    {
        resStr.insert(i + 1, 1, ',');
    }
    if (res < 0)
    {
        resStr = '-' + resStr;
    }
    cout << resStr;
}