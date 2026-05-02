#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> feild(4, vector<int>(8));
int is = -1, ie = -1, js = -1, je = -1;

void Input()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 8; ++j)
			cin >> feild[i][j];
	}
}

int AreaSum()
{
	int result = 0;
	for (int i = is; i <= ie; ++i)
	{
		int rowSum = 0;
		for (int j = js; j <= je; ++j)
		{
			if (!feild[i][j])
			{
				rowSum = 0;
				ie = i - 1;
				break;
			}
			rowSum += feild[i][j];
		}

		if (rowSum == 0)
			break;

		result += rowSum;
	}

	return result;
}
int FindMaxProfit()
{
	int max = INT_MIN;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (!feild[i][j]) continue;
			is = i;
			js = j;

			ie = feild.size() - 1;
			for (je = js; je < feild[is].size(); ++je)
			{
				if (!feild[is][je]) break;

				int sum = AreaSum();
				if (max < sum)
					max = sum;

			}
		}
	}

	return max;
}

int main(void)
{
	Input();
	int result = FindMaxProfit();

	cout << result;

	return 0;
}