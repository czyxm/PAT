#include<iostream> 
#include<regex>
#include<string>
#include<map>
using namespace std;

int main()
{
    int maxNum = -1;
    string target, res, temp;
    map<string, int> words;
    getline(cin, target);
    regex pattern("[A-Za-z0-9]+");
    smatch sm;
    string::const_iterator iter = target.begin();
    string::const_iterator end = target.end();
    while (iter != end && regex_search(iter, end, sm, pattern))
    {
        temp = sm[0].str();
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        words[temp]++;
        if (words[temp] > maxNum || (words[temp] == maxNum && temp < res))
        {
            maxNum = words[temp];
            res = temp;
        }
        iter = sm[0].second;
    }
    cout << res << " " << maxNum;
    return 0;
}