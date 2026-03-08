#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dt;
int n, m;

void Input()
{
	cin >> n >> m;

	dt.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> dt[i];
	}
}

int MinusCount()
{
	int cnt = 0;
	for (int i = 0; i < dt.size(); ++i)
	{
		if (dt[i] >= 0)
			break;
		cnt++;
	}

	return cnt;
}

int main(void)
{
	Input();

	sort(dt.begin(), dt.end());

	int minusNum = MinusCount();
	int plusNum = dt.size() - minusNum;

	int min = INT_MAX;
	if(minusNum > 0 && plusNum > 0)
	{
		for (int me = 0; me < minusNum; me += 2)
		{
			int selCount = 0;
			int mul = 1;
			for (int ms = 0; ms <= me; ++ms)
			{
				mul *= dt[ms];
				selCount++;
			}

			if (selCount >= m) 
			{
				if(selCount == m)
				{
					if (min > mul)
						min = mul;
				}
				break;
			}

			int idx = dt.size() - 1;
			for (int k = 0; k < m - selCount; ++k)
			{
				mul *= dt[idx--];
			}

			if (min > mul)
				min = mul;

		}
	}
	else if(minusNum == 0)
	{
		int idx = 0;
		int mul = 1;
		for (int k = 0; k < m; ++k)
		{
			mul *= dt[idx++];
		}

		if (min > mul)
			min = mul;
	}
	else if (plusNum == 0)
	{
		int idx = dt.size() - 1;
		int mul = 1;
		for (int k = 0; k < m; ++k)
		{
			mul *= dt[idx--];
		}

		if (min > mul)
			min = mul;
	}

	cout << min;

	return 0;
}