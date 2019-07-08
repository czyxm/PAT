# A+B for Polynomials

This time, you are supposed to find *A*+*B* where *A* and *B* are two polynomials.

### Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

*K* *N*1 *a**N*1 *N*2 *a**N*2 ... *N**K* *a**N**K*

where *K* is the number of nonzero terms in the polynomial, *N**i* and *a**N**i* (*i*=1,2,⋯,*K*) are the exponents and coefficients, respectively. It is given that 1≤*K*≤10，0≤*N**K*<⋯<*N*2<*N*1≤1000.

### Output Specification:

For each test case you should output the sum of *A* and *B* in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

### Sample Input:

```in
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```

### Sample Output:

```out
3 2 1.5 1 2.9 0 3.2
```

---

### Solution

```C++
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
```



