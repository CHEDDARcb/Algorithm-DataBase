#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> nums;
vector<vector<bool>> bits;
map<int, int> tmp;
vector <pair< int, int >> result;

void Input()
{
	cin >> n;

	nums.resize(n, vector<int>(n));
	bits.resize(n, vector<bool>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> nums[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			bool b;
			cin >> b;
			bits[i][j] = b;
		}
	}
}

void Extract()
{
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums[i].size(); ++j)
		{
			if (bits[i][j])
			{
				map<int, int>::iterator fr = tmp.find(nums[i][j]);
				if (fr == tmp.end())
					tmp.insert({ nums[i][j], 1 });
				else
					tmp[nums[i][j]] += 1;
			}
		}
	}

	for_each(tmp.begin(), tmp.end(),
		[&](const pair<int, int>& data)
		{
			result.push_back(data);
		});

	tmp.clear();
}

void Sort()
{
	for (int i = 1; i < result.size(); ++i)
	{
		pair<int, int> m = result[i];
		int j = i - 1;
		for (; j >= 0 &&
			(result[j].second < m.second || result[j].first > m.first); --j)
		{
			if (result[j].second != m.second)
			{
				if (result[j].second <= m.second)
					result[j + 1] = result[j];
			}
			else
			{
				if (result[j].first >= m.first)
					result[j + 1] = result[j];
			}
		}
		result[j + 1] = m;
	}
}

int main(void)
{
	Input();
	Extract();
	Sort();

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].second; ++j)
		{
			cout << result[i].first << " ";
		}
	}
	return 0;
}