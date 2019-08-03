#include<iostream>
#include<string>
using namespace std;

char convert(int num)
{
    if (num < 10)
    {
        return num + '0';
    }
    else
    {
        return num - 10 + 'A';
    }
}

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    cout << "#" << convert(r / 13) << convert(r % 13) << convert(g / 13) << convert(g % 13) << convert(b / 13) << convert(b % 13);
    return 0;
}