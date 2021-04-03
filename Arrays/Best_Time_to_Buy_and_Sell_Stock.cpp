/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day 
in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
int maxProfit(int price[], int start, int end)
{

	// If the stocks can't be bought
	if (end <= start)
		return 0;
	int profit = 0;
	for (int i = start; i < end; i++) {
		for (int j = i + 1; j <= end; j++) {
			if (price[j] > price[i]) {
				int curr_profit = price[j] - price[i]+ maxProfit(price, start, i - 1)+ maxProfit(price, j + 1, end);
                profit = max(profit, curr_profit);
			}
		}
	}
	return profit;
}

int main()
{
	int price[] = { 100, 180, 260, 310,40, 535, 695 };
	int n = sizeof(price) / sizeof(price[0]);
    cout << maxProfit(price, 0, n - 1);
    return 0;
}
