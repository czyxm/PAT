# Waiting In Line

Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:

The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number. Customeri will take Ti minutes to have his/her transaction processed. The first N customers are assumed to be served at 8:00am. Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 custmers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer1 is served at window?1 while customer2 is served at window2. Customer3 will wait in front of window1 and customer4 will wait in front of window2. Customer5 will wait behind the yellow line.

At 08:01, customer1 is done and customer5 enters the line in front of window 1 since that line seems shorter now. Customer2 will leave at 08:02, customer4 at 08:06, customer3 at 08:07, and finally customer5 at 08:10.

### Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (<=20, number of windows), M (<=10, the maximum capacity of each line inside the yellow line), K (<=1000, number of customers), and Q (<=1000, number of customer queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.

### Output Specification:
For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output Sorry instead.

### Sample Input:
```in
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
```

### Sample Output:
```out
08:07
08:06
08:10
17:00
Sorry
```

### Solution
This problem simulates the queuing situation at the bank window, and the customers are divided into 2 parts:
* Within the yellow line[0, N*M-1]: Just line up one by one.
* Behind the yellow line[N*M, K-1]: Each time pop the customer that finishes the service earlist and push the next customer in.

What calls for our attention is that "for those customers who cannot be **served** before 17:00, you must output Sorry instead", note that the word in bold type is not 'finish'!!! Actually I waste lots of time here because of carelessness :(.

```C++
#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

int main()
{
    queue<int> * window;
    int N, M, K, Q, customer, index, *processingTime, *finishTime;
    cin >> N >> M >> K >> Q;
    processingTime = new int [K];  //Processing time for customers: minutes
    finishTime = new int [K];      //Finish time: minutes
    window = new queue<int> [N];   //Estimate the windows by queues
    for (int i = 0; i < K; i++)
    {
        cin >> processingTime[i];
        if (i < M * N)
        {
            if (i < N)
            {
                finishTime[i] = processingTime[i];
            }
            else
            {
                finishTime[i] = finishTime[window[i % N].back()] + processingTime[i];
            }
            window[i % N].push(i);
        }
        else
        {
            //Find the index of the earlist window that dequeue a customer
            index = 0;
            for (int j = 1; j < N; j++)
            {
                if (finishTime[window[j].front()] < finishTime[window[index].front()])
                {
                    index = j;
                }
            }
            //Push the next customer into this window
            finishTime[i] = finishTime[window[index].back()] + processingTime[i];
            window[index].pop();
            window[index].push(i);
        }
    }
    for (int i = 1; i <= Q; i++)
    {
        cin >> customer;
        customer--;
        if (finishTime[customer] - processingTime[customer] >= 540)
        {
            cout << "Sorry" << endl;
        }
        else
        {
            finishTime[customer] += 480;
            cout << setfill('0') << setw(2) << finishTime[customer] / 60 << ":" << setfill('0') << setw(2) << finishTime[customer] % 60 << endl;
        }
    }
    delete [] processingTime;
    delete [] finishTime;
    delete [] window;
    return 0;
}
```