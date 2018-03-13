/*
---------- 0/1 knapsack problem ------------
Find the maximum value that can be obtained after putting items into the knapsack.
*/

#include<stdio.h>
#include <algorithm>
#include <vector>


int knapSack(int W, int wt[], int val[], int num_of_items)
{
	int i, w;
	std::vector< std::vector<int> > K(num_of_items + 1, std::vector<int>(W + 1));        // simply array -> int K[n+1][W+1];

	for (i = 0; i <= num_of_items; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)                // when no item exists or the capacity is 0
				K[i][w] = 0;
			else if (wt[i-1] > w)                // if the weight of the item is greater than the capacity
				K[i][w] = K[i - 1][w];
			else
				K[i][w] = std::max(val[i-1] + K[i - 1][w - wt[i-1]], K[i - 1][w]);       // find maximum value, either using the ith item or not; ith item is (i-1), as 0 based indexing
		}
	}

	return K[num_of_items][W];
}

int main()
{
	int W = 7;                                   // the capacity of the knapsack
	int wt[] = {1, 2, 4, 5 };
	int val[] = {5, 3, 2, 6 };

	int num_of_items = sizeof(val) / sizeof(val[0]);
	printf("%d\n", knapSack(W, wt, val, num_of_items));

	return 0;
}
