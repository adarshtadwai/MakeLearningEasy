/*
Cut the rod to maximize the profit.
*/

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>


int cut_rod(int prices[], int n)
{
	int max_val;
	std::vector<int> max_profits(n+1);

	max_profits[0] = 0;

	for (int i = 1; i <= n; i++){
		max_val = INT_MIN;
		for (int j = 0; j < i; j++){
			max_val = std::max(max_val, prices[j] + max_profits[i - j - 1]);
		}
		max_profits[i] = max_val;
	}

	return max_profits[n];
}


int main()
{
	int prices[] = {2, 5, 8, 9, 10};
	int n = sizeof(prices) / sizeof(prices[0]);

	std::cout << "Maximum obtainable profit: " << cut_rod(prices, n) << std::endl;

    return 0;
}
