# The World's Richest
Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages. That is, given the net worths of N people, you must find the M richest people in a given range of their ages.
### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=10^5) - the total number of people, and K (<=10^3) - the number of queries. Then N lines follow, each contains the name (string of no more than 8 characters without space), age (integer in (0, 200]), and the net worth (integer in [?10^6,10^6]) of a person. Finally there are K lines of queries, each contains three positive integers: M (<=100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages. All the numbers in a line are separated by a space.
### Output Specification:
For each query, first print in a line Case #X: where X is the query number starting from 1. Then output the M richest people with their ages in the range [Amin, Amax]. Each person's information occupies a line, in the format
```
Name Age Net_Worth
```
The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages. If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two persons share all the same of the three pieces of information. In case no one is found, output None.
### Sample Input:
```
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
```
### Sample Output:
```
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
```
### Solution
There's allways a point resulting in TLE while searching orderly.
I referenced the idea on how to shrink the search scope from <https://blog.csdn.net/u012303532/article/details/12623007>.
```C++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
//Structure node for people
typedef struct PeopleNode
{
    char name[9];
    int age;
    int net_worth;
}*PNode;
//Compare function for sorting people
bool compare(const PNode & p1, const PNode p2)
{
    if (p1->net_worth == p2->net_worth)
    {
        if (p1->age == p2->age)
        {
            return strcmp(p1->name, p2->name) < 0;
        }
        return p1->age < p2->age;
    }
    return p1->net_worth > p2->net_worth;
}

int main()
{
    vector<PNode> people;
    int start[201], end[201];
    int N, K, M, minAge, maxAge, front, rear, count;
    cin >> N >> K;
    people.resize(N);
    for (int i = 0; i <= 200; i++)
    {
        start[i] = end[i] = -1;
    }
    for (int i = 0; i < N; i++)
    {
        people[i] = new PeopleNode;
        scanf("%s %d %d", people[i]->name, &people[i]->age, &people[i]->net_worth);
    }
    sort(people.begin(), people.end(), compare);
    //Find the start and end position for each age of given people
    for (int i = 0; i < N; i++)
    {
        if (start[people[i]->age] == -1)
        {
            start[people[i]->age] = i;
        }
        end[people[i]->age] = i;
    }
    for (int i = 1; i <= K; i++)
    {
        cin >> M >> minAge >> maxAge;
        cout << "Case #" << i << ":" << endl;
        front = N - 1;
        rear = 0;
        //Find the smallest position of start and largest position of end
        //Determine the search scope
        for (int j = minAge; j <= maxAge; j++)
        {
            if (start[j] == -1)
            {
                continue;
            }
            if (start[j] < front)
            {
                front = start[j];
            }
            if (end[j] > rear)
            {
                rear = end[j];
            }
        }
        count = 0;
        for (int j = front; j <= rear && count < M; j++)
        {
            if (minAge <= people[j]->age && people[j]->age <= maxAge)
            {
                count++;
                cout << people[j]->name << " " << people[j]->age << " " << people[j]->net_worth << endl;
            }
        }
        if (count == 0)
        {
            cout << "None" << endl;
        }
    }
    return 0;
}
```