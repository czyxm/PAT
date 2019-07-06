# 1017 The Best Peak Shape

In many research areas, one important target of analyzing data is to find the best "peak shape" out of a huge amount of raw data full of noises. A "peak shape" of length *L* is an ordered sequence of *L* numbers { *D*1, ⋯, *D**L* } satisfying that there exists an index *i* (1<*i*<*L*) such that *D*1<⋯<*D**i*−1<*D**i*>*D**i*+1>⋯>*D**L*.

Now given *N* input numbers ordered by their indices, you may remove some of them to keep the rest of the numbers in a peak shape. The best peak shape is the longest sub-sequence that forms a peak shape. If there is a tie, then the most symmetric (meaning that the difference of the lengths of the increasing and the decreasing sub-sequences is minimized) one will be chosen.

### Input Specification:

Each input file contains one test case. For each case, the first line gives an integer *N* (3≤*N*≤104). Then *N* integers are given in the next line, separated by spaces. All the integers are in [−10000,10000].

### Output Specification:

For each case, print in a line the length of the best peak shape, the index (starts from 1) and the value of the peak number. If the solution does not exist, simply print "No peak shape" in a line. The judge's input guarantees the uniqueness of the output.

### Sample Input1:

```in
20
1 3 0 8 5 -2 29 20 20 4 10 4 7 25 18 6 17 16 2 -1
```

### Sample Output1:

```out
10 14 25
```

### Sample Input2:

```
5
-1 3 8 10 20
```

### Sample Output2:

```
No peak shape
```

### Solution

```C++
#include<iostream>
#define MAX(x,y) (x)>(y)?(x):(y)
void FindPeak(int n, int *A);
using namespace std;
int main()
{
    int n, *A;
    cin >> n;
    A = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    FindPeak(n, A);
}
void FindPeak(int n, int *A) 
{
	int index = 0, i, j; //The index of the peak element in the result
	int *up = new int[n + 1], *down = new int[n + 1];  //Maximun length of ascending sequence and descending sequence
	//Initialize the two arrays
	for (int i = 0; i <= n; i++)
	{
		up[i] = down[i] = 0;
	}
	//Caculate the length of maximum ascending sequence
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (A[i] > A[j])
				up[i] = MAX(up[i], up[j] + 1);
		}	
	}
	//Caculate the length of maximum descending sequence
	for (int i = n; i >= 1; i--)
	{
		for (int j = n; j > i; j--)
		{
			if (A[i] > A[j])
				down[i] = MAX(down[i], down[j] + 1);
		}
	}		
	//Find a peak with maximum length
	for (int i = 1; i <= n; ++i)
	{
		if (up[i] && down[i])
		{
			//Longer length or the same length but more symmetric
			if (up[i] + down[i] > up[index] + down[index] ||
			   (up[i] + down[i] == up[index] + down[index] && abs(up[i] - down[i]) < abs(up[index] - down[index])))
			{
				index = i;
			}
		}
	}
	//Display the result		
	if (index == 0)  //Not found a peak
		cout << "No peak shape";
	else             //format: length index value
	    cout << up[index] + down[index] + 1 << " " << index << " " << A[index];
}
```