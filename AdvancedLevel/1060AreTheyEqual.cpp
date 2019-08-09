#include<iostream>
#include<string>
using namespace std;
//Fill the bit with zero or chop to digit
string zeroFill(const string & str, int digit)
{
    if (str.size() >= digit)
    {
        return str.substr(0, digit);
    }
    else
    {
        return str + string(digit - str.size(), '0');
    }
}

void standardize(string & str, int digit)
{
    int exponent = 0, spotIndex = str.find('.'), firstDigit = -1, invalidZeroIndex = -1;
    //Find the index of firtst non-zero digit
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != '0' && str[i] != '.')
        {
            firstDigit = i;
            break;
        }
    }
    //0
    if (firstDigit == -1)
    {
        exponent = 0;
        str = string(digit, '0');
        str = "0." + str;
    }
    //No decimal point
    else if (spotIndex == string::npos)
    {
        str.erase(0, firstDigit);
        exponent = str.size();
        str = "0." + zeroFill(str, digit);
    }
    else
    {
        //Remove the previous invalid 0's
        if (firstDigit < spotIndex)
        {
            str.erase(0, firstDigit);
            spotIndex -= firstDigit;
            firstDigit = 0;
        }
        else if (firstDigit > spotIndex)
        {
            str.erase(0, spotIndex - 1);
            firstDigit -= spotIndex - 1;
            spotIndex = 1;
        }
        exponent = spotIndex - firstDigit;
        if (str[0] == '0')
        {
            exponent++;
            str = zeroFill(str.erase(spotIndex + 1, -exponent), digit + 2);
        }
        else
        {
            str.erase(spotIndex, 1);
            str = "0." + zeroFill(str, digit);
        }
    }
    str += "*10^" + to_string(exponent);
}

int main()
{
    string A, B;
    int digit;
    cin >> digit >> A >> B;
    if (digit == 0)
    {
        cout << "YES 0.*10^0";
        return 0;
    }
    standardize(A, digit);
    standardize(B, digit);
    if (A == B)
    {
        cout << "YES " << A;
    }
    else
    {
        cout << "NO " << A << " " << B;
    }
    return 0;
}