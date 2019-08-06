#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    vector<int> number;
    map<int, int> frequency;
    int N, num, index;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        number.push_back(num);
        frequency[num]++;
    }
    for (int i = 0; i < N; i++)
    {
        if (frequency[number[i]] == 1)
        {
            cout << number[i];
            return 0;
        }
    }
    cout << "None";
    return 0;
}