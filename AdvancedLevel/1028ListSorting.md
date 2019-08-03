# List Sorting
Excel can sort records according to any column. Now you are supposed to imitate this function.
### Input Specification:
Each input file contains one test case. For each case, the first line contains two integers N (<=10^5) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).
### Output Specification:
For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.
### Sample Input 1:
```in
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
```
### Sample Output 1:
```out
000001 Zoe 60
000007 James 85
000010 Amy 90
```
### Sample Input 2:
```in
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
```
### Sample Output 2:
```out
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
```
### Sample Input 3:
```in
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
```
### Sample Output 3:
```out
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
```
### Solution
Oh hu~
```C++
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct RecordNode
{
    string ID;
    int IDValue;  //Sort by int type is much faster than string!!!
    int score;
    string name;
}*RNode;

bool compare1(const RNode & r1, const RNode & r2)
{
    return r1->IDValue < r2->IDValue;
}

bool compare2(const RNode & r1, const RNode & r2)
{
    return r1->name < r2->name || (r1->name == r2->name && r1->IDValue < r2->IDValue);
}

bool compare3(const RNode & r1, const RNode & r2)
{
    return r1->score < r2->score || (r1->score == r2->score && r1->IDValue < r2->IDValue);
}

int main()
{
    int N, C;
    vector<RNode> records;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        RNode newRecord = new RecordNode;
        cin >> newRecord->ID >> newRecord->name >> newRecord->score;
        newRecord->IDValue = stoi(newRecord->ID);
        records.push_back(newRecord);
    }
    switch (C)
    {
        case 1 : sort(records.begin(), records.end(), compare1); break;
        case 2 : sort(records.begin(), records.end(), compare2); break;
        case 3 : sort(records.begin(), records.end(), compare3); break;
    }
    for (int i = 0; i < N; i++)
    {
        cout << records[i]->ID << " " << records[i]->name << " " << records[i]->score << endl;
    }
    return 0;
}
```