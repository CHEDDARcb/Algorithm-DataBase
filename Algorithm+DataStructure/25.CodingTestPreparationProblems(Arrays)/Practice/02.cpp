#include <iostream>
#include <vector>

using namespace std;

int MaxProfit(const vector<int>& prices)
{
	int profit = 0;
	for (int i = 0; i < prices.size() - 1; ++i)
	{
		if (prices[i] < prices[i + 1])
			profit += prices[i + 1] - prices[i];
	}

	return profit;
}

int main()
{
	vector<int> prices = { 7,1,5,3,6,4 };

	int maxProfit = MaxProfit(prices);

	cout << maxProfit;

	return 0;
}