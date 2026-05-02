#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> cog =
{
	{3, 7, 4},
	{2, 6, 9},
	{5, 1, 2},
	{3, 6, 7}
};
vector<int> rollCounts;

void Reverse(vector<int>::iterator start, vector<int>::iterator end)
{
	--end;
	while (start < end)
	{
		int tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

void Rolling()
{
	for (int i = 0; i < cog.size(); ++i)
	{
		int k = rollCounts[i] % cog[i].size();
		Reverse(cog[i].begin(), cog[i].end());
		Reverse(cog[i].begin(), cog[i].begin() + k);
		Reverse(cog[i].begin() + k, cog[i].end());
	}
}

int main()
{
	for (int i = 0; i < 4; ++i)
	{
		int n;
		cin >> n;
		rollCounts.push_back(n);
	}

	Rolling();

	for (int j = 0; j < cog[0].size(); ++j)
	{
		for (vector<vector<int>>::iterator iter = cog.begin();
			iter != cog.end(); ++iter)
		{
			cout << (*iter)[j];
		}
		cout << endl;
	}

	return 0;
}