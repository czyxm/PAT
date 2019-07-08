#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int k1, k2, size = 0, exp, exponent[1001] = {0};
    float coe, coefficent[1001] = {0};
    for (int i = 0; i <= 1000; i++)
    {
        exponent[i] = 0;
        coefficent[i] = 0;
    }
    cin >> k1;
    size = k1;
    for (int i = 0; i < k1; i++)
    {
        cin >> exp >> coe;
        exponent[exp] = 1;
        coefficent[exp] = coe;
    }
    cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        cin >> exp >> coe;
        if (exponent[exp])
        {
            coefficent[exp] += coe;
            if (fabs(coefficent[exp]) < 1E-6)
            {
                exponent[exp] = 0;
                size--;
            }
        }
        else
        {
            exponent[exp] = 1;
            coefficent[exp] = coe;
            size++;
        }
    }
    cout << size;
    for (int i = 1000; i >= 0; i--)
    {
        if (exponent[i] == 1)
        {
            cout << " " << i << " " << fixed << setprecision(1) << coefficent[i];
        }
    }
    return 0;
}