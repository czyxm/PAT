#include<iostream>
using namespace std;

int main()
{
    long N, R = 10, count = 0;
    cin >> N;
    while (R <= 10 * N)
    {
        count += N / R * R / 10;
        if (N % R * 10 / R > 1)
        {
            count += R / 10;
        }
        else if (N % R * 10 / R == 1)
        {
            if (R == 10)
            {
                count += 1;
            }
            else
            {
                count += N % (R / 10) + 1;
            }
        }
        R *= 10;
    }
    cout << count;
}