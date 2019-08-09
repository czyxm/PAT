#include<iostream>
#include<string>
using namespace std;
int main()
{
    string number, numStr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int sum = 0;
    cin >> number;
    for (int i = 0; i < number.length(); i++)
    {
        sum += number[i] - '0';
    }
    number = to_string(sum);
    for (int i = 0; i < number.length(); i++)
    {
        cout << numStr[number[i] - '0'];
        if (i < number.length() - 1)
        {
            cout << " ";
        }
    }
    return 0;
}