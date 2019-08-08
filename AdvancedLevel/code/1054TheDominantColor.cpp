#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    vector<int> pixel;
    map<int, int> number;
    int M, N, color, dominantColor; 
    cin >> M >> N;
    pixel.resize(N * M);
    for (int i = 0; i < N * M; i ++)
    {
        cin >> color;
        auto iter = number.find(color);
        if (iter == number.end())
        {
            number.insert(pair<int, int>(color, 1));
            if (1 > M * N / 2)
            {
                dominantColor = color;
            }
        }
        else if (++(iter->second) > M * N / 2)
        {
            dominantColor = color;
        }
    }
    cout << dominantColor;
    return 0;
}