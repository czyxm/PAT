#include<bits/stdc++.h>

int main()
{
    long N, p, res = 1, low = 0, mid = 0, high = 0;
    std::cin >> N >> p;
    std::vector<long> sequence(N, 0);
    for (int i = 0; i < N; i++)
    {
        std::cin >> sequence[i];
    }
    //Sort the sequence with non-decreasing order
    sort(sequence.begin(), sequence.end(), std::less<long>());
    for (int i = 0; i < N; i++)
    {
        if (sequence[N - 1] <= sequence[i] * p)
        {
            res = N - i > res ? N - i : res;
            break;
        }
        //Binary search to find the maximum number M that satisfies M <= m * p
        low = mid;
        high = N - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (sequence[mid] > sequence[i] * p)
            {
                high = mid - 1;
            }
            else if (sequence[mid] < sequence[i] * p)
            {
                low = mid + 1;
            }
            else
            {
                break;
            }
        }
        mid = (low + high) / 2;
        res = mid - i + 1 > res ? mid - i + 1 : res;
    }
    std::cout << res;
    return 0;
}