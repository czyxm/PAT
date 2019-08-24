#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int num, num1, num2;
    string str;
    cin >> str;
    while (true)
    {
        if (str.size() < 4)
        {
            str = string(4 - str.size(), '0') + str;
        }
        sort(str.begin(), str.end(), greater<char>());
        num1 = stoi(str);
        reverse(str.begin(), str.end());
        num2 = stoi(str);
        num = num1 - num2;
        str = to_string(num);
        cout << setw(4) << setfill('0') << num1 << " - " << setw(4) << setfill('0') << num2 << " = " << setw(4) << setfill('0') << str << endl;
        if (num == 0 || num == 6174)
        {
            break;
        }
    }
    return 0;
}