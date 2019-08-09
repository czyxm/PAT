#include<iostream>
#include<iomanip>
using namespace std;

inline int maxIdx(float * data, int n)
{
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (data[i] > data[index])
        {
            index = i;
        }
    }
    return index;
}

int main()
{
    float game[3], temp[3], profit = 1;
    char symbol[3] = {'W', 'T', 'L'};
    for (int i = 0; i < 3; i++)
    {
        cin >> temp[0] >> temp[1] >> temp[2];
        int index = maxIdx(temp, 3);
        game[i] = temp[index];
        profit *= game[i];
        cout << symbol[index] << " ";
    }
    profit = (profit * 0.65 - 1) * 2;
    cout << setprecision(2) << fixed << profit;

    return 0;
}