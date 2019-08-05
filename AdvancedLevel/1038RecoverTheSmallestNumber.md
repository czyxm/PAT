# Recover the Smallest Number
Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given { 32, 321, 3214, 0229, 87 }, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.
### Input Specification:
Each input file contains one test case. Each case gives a positive integer N (<=10^4) followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.
### Output Specification:
For each test case, print the smallest number in one line. Notice that the first digit must not be zero.
### Sample Input:
```
5 32 321 3214 0229 87
```
### Sample Output:
```
22932132143287
```
### Solution
To simplify this problem I hash the segments into 10 bucket according to their first character, then just need to sort them within each bucket. Great attention need to be attached to **substring**. Just consider the sample input: `32 321 3214`! Furthermore, I observed that regradless of the prefix, the next position matters! The key point is that which is smaller between the longer one and the short one **appending its first character**. For instance, `32` + `3` > `321`, then `321` + `3` < `3214`! Now you got the solution! But be careful, what if they're equal? Emmm, like `003` + `0` == `0030`. Look at the two different results: `0030003` < `0030030`, thus we should take the longer one first!
Now we can code a compare function for sorting, howbeit we have missed something--special case! Think about all the segments are equal 0: `3 0 00 000`.
Have fun :)
```C++
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//Compare function for sorting segments in each bucket
bool compare(const string & s1, const string & s2)
{
    //s2 is a substring of s1
    if (s1.find(s2) == 0)
    {
        //Abstract the first character of the substring and append to itself, then compare
        return s1 <= s2 + s2[0]; //The '=' is indispensable, just consider the input case : 2 003 0030
    }
    //s1 is a substring of s2
    else if (s2.find(s1) == 0)
    {
        return s1 + s1[0] <= s2;
    }
    else
    {
        return s1 < s2;
    }
}

int main()
{
    int N;
    bool flag = false;
    string str;
    //Bucket sort in the first step
    //10 buckets for segments, where segments in the same bucket have the same fisrt character
    vector<string> segment [10];
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> str; 
        if (stoi(str) != 0)
        {
            //Hash the segment into the proper bucket
            segment[str[0] - '0'].push_back(str);
            flag = true;  //There is a segment with value not equals 0
        }
    }
    for (int i = 0; i < 10; i++)
    {
        sort(segment[i].begin(), segment[i].end(), compare);
        for (int j = 0; j < segment[i].size(); j++)
        {
            if (i == 0 && j == 0)//The fisrt segment has '0' in the beginning
            {
                cout << stoi(segment[i][j]);//Remove these '0's
            }
            else
            {
                cout << segment[i][j];
            }
        }
    }
    if (!flag)  //All the given segments equal 0
    {
        cout << 0;
    }
    return 0;
}
```