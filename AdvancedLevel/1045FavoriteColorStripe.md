# Favorite Color Stripe
Eva is trying to make her own color stripe out of a given one. She would like to keep only her favorite colors in her favorite order by cutting off those unwanted pieces and sewing the remaining parts together to form her favorite color stripe.
It is said that a normal human eye can distinguish about less than 200 different colors, so Eva's favorite colors are limited. However the original stripe could be very long, and Eva would like to have the remaining favorite stripe with the maximum length. So she needs your help to find her the best result.
Note that the solution might not be unique, but you only have to tell her the maximum length. For example, given a stripe of colors {2 2 4 1 5 5 6 3 1 1 5 6}. If Eva's favorite colors are given in her favorite order as {2 3 1 5 6}, then she has 4 possible best solutions {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6}, and {2 2 3 1 1 5 6}.
### Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=200) which is the total number of colors involved (and hence the colors are numbered from 1 to N). Then the next line starts with a positive integer M (<=200) followed by M Eva's favorite color numbers given in her favorite order. Finally the third line starts with a positive integer L (<=10^4) which is the length of the given stripe, followed by L colors on the stripe. All the numbers in a line a separated by a space.
### Output Specification:
For each test case, simply print in a line the maximum length of Eva's favorite stripe.
### Sample Input:
```
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
```
### Sample Output:
```
7
```
### Solution
DP again! To make the problem clearer, I rank all the favorite colors form 1 to M, then cut those out of favorite list and replace the rest of colors by their rank, thus the problem is transformed into a max non-decreasing sub-sequence problem! Oh hu~
```C++
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    map<int, int>rank;  //Rank the color from 1 to M
    vector<int> stripe, length;
    int N, M, L, color, maxLength;
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> color;
        rank.insert(pair<int, int>(color, i));
    }
    cin >> L;
    for (int i = 1; i <= L; i++)
    {
        cin >> color;
        auto iter = rank.find(color);
        //Cut the colors out of the favorite colors
        if (iter!= rank.end())
        {
            stripe.push_back(iter->second);
        }
    }
    length.resize(stripe.size());
    maxLength = 1;
    for (int i = 0; i < stripe.size(); i++)
    {
        int j = i - 1;
        //Find the last color that ranks before stripe[i]
        while (j >= 0 && stripe[j] > stripe[i]) {j--;}
        //If stripe[i] is the first color
        if (j < 0)
        {
            length[i] = 1;
        }
        else
        {
            length[i] = length[j] + 1;
            //Refresh the max length
            if (length[i] > maxLength)
            {
                maxLength = length[i];
            }
        }
    }
    cout << maxLength;
    return 0;
}
```