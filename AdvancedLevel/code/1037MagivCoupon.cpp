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