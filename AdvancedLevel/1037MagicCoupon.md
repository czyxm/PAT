# Magic Coupon
The magic shop in Mars is offering some magic coupons. Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, you may get N times the value of that product back! What is more, the shop also offers some bonus product for free. However, if you apply a coupon with a positive N to this bonus product, you will have to pay the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's!
For example, given a set of coupons { 1 2 4 -1 }, and a set of product values { 7 6 -2 -3 } (in Mars dollars M$) where a negative value corresponds to a bonus product. You can apply coupon 3 (with N being 4) to product 1 (with value M$7) to get M$28 back; coupon 2 to product 2 to get M$12 back; and coupon 4 to product 4 to get M$3 back. On the other hand, if you apply coupon 3 to product 4, you will have to pay M$12 to the shop.
Each coupon and each product may be selected at most once. Your task is to get as much money back as possible.
### Input Specification:
Each input file contains one test case. For each case, the first line contains the number of coupons NC, followed by a line with NC coupon integers. Then the next line contains the number of products NP, followed by a line with NP product values. Here 1<=NC,NP<=10^5, and it is guaranteed that all the numbers will not exceed 2^30.
### Output Specification:
For each test case, simply print in a line the maximum amount of money you can get back.
### Sample Input:
```
4
1 2 4 -1
4
7 6 -2 -3
```
### Sample Output:
```
43
```
### Solution
Oh hu~
```C++
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    int num, value;
    vector<int> positiveCoupon, negativeCoupon;
    priority_queue<int, vector<int>, less<vector<int>::value_type> > positiveProduct;   //max heap
    priority_queue<int, vector<int>, greater<vector<int>::value_type> > negativeProduct;//min heap
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cin >> value;
        if (value > 0)
        {
            positiveCoupon.push_back(value);
        }
        else
        {
            negativeCoupon.push_back(value);
        }
    }
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cin >> value;
        if (value > 0)
        {
            positiveProduct.push(value);
        }
        else
        {
            negativeProduct.push(value);
        }
    }
    sort(positiveCoupon.begin(), positiveCoupon.end(), greater<int>());//Descending order
    sort(negativeCoupon.begin(), negativeCoupon.end(), less<int>());   //Asending order
    value = 0;
    for (int i = 0; i < positiveCoupon.size(); i++)
    {
        if (positiveProduct.size() > 0)
        {
            value += positiveCoupon[i] * positiveProduct.top();
            positiveProduct.pop();
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < negativeCoupon.size(); i++)
    {
        if (negativeProduct.size() > 0)
        {
            value += negativeCoupon[i] * negativeProduct.top();
            negativeProduct.pop();
        }
        else
        {
            break;
        }
    }
    cout << value;
    return 0;
}
```