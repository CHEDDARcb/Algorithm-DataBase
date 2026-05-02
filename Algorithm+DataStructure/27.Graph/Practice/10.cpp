#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph =
{
	{0 ,1, 1, 1,},
	{1, 0, 1, 0 },
	{1, 1, 0, 0 },
	{1, 0, 0, 0 }
};

int ConnectCount(vector<int>& vec)
{
	int count = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i]) ++count;
	}

	return count;
}

int main()
{
	int max = INT_MIN;
	int mIdx = -1;
	for (int i = 0; i < graph.size(); ++i)
	{
		int count = ConnectCount(graph[i]);
		if (count > max)
		{
			max = count;
			mIdx = i;
		}
	}

	cout << char('A' + mIdx);

	return 0;
}