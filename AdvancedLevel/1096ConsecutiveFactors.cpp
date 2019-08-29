#include<bits/stdc++.h>
using namespace std;
/*  12! < 2^31 < 13!
 *  length <= 12
 *  max_solution = {2,...,12}
 *  Just find the max consecutive with N can be devided by its product
 *  If not found, then N is a prime number, print "1\nN"
 */
int main()
{
    long N, sqrtN, product, length;
    vector<int> factors;
    cin >> N;
    sqrtN = (int)sqrt(N);
    for (length = 12; length >= 1; length--)
    {
        for (int i = 2; i <= sqrtN; i++)
        {
            product = 1;
            for (int j = i; j < i + length; j++)
            {
                product *= j;
            }
            if (N % product == 0)
            {
                cout << length << endl << i;
                for (int k = 1; k < length; k++)
                {
                    cout << "*" << i + k;
                }
                return 0;
            }
        }
    }
    cout << 1 << endl << N;
    return 0;
}