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