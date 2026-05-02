#include <iostream>
#include <vector>

using namespace std;

string names[5] =
{
	"Amy",
	"Bob",
	"Chloe",
	"Diane",
	"Edger"
};

vector<vector<int>> graph =
{
	{0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0}

};

int main()
{
	int max = INT_MIN;
	int idx = -1;
	for (int j = 0; j < graph[0].size(); ++j)
	{
		int count = 0;
		for (int i = 0; i < graph.size(); ++i)
		{
			if (graph[i][j]) ++count;
		}
		if (max < count)
		{
			max = count;
			idx = j;
		}
	}

	cout << names[idx];


	return 0;
}