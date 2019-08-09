#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
    string s1, s2, s3, s4;
    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cin >> s1 >> s2 >> s3 >> s4;
    int day = -1, hour = -1, minute = -1, i;
    for (i = 0; i < s1.size() && i < s2.size(); i++)
    {
        if (s1[i] == s2[i])
        {
            if (day == -1)
            {
                if (s1[i] == s2[i] && 'A' <= s2[i] && s2[i] <= 'G')
                {
                    day = s2[i] - 'A';
                }
            }
            else if (hour == -1)
            {
                if ('A' <= s2[i] && s2[i] <= 'N')
                {
                    hour = s2[i] - 'A' + 10;
                    break;
                }
                else if (isdigit(s2[i]) != 0)
                {
                    hour = s2[i] - '0';
                    break;
                }
            }
        }
        
    }
    for (i = 0; i < s3.size() && i < s4.size(); i++)
    {
        if (s3[i] == s4[i] && isalpha(s3[i]))
        {
            minute = i;
            break;
        }
    }
    cout << week[day] << " " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute;
    return 0;
}