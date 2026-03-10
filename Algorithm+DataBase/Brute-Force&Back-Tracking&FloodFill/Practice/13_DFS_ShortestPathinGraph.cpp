#include <iostream>
#include <vector>

using namespace std;

const vector<vector<int>> map =
{
	{0, 80, 60, 30},	//N
	{80, 0, 0, 40},		//G
	{60, 0, 0, 70},		//D
	{30, 40, 70, 0},	//Y
};
vector<bool> visited(map.size(), false);
int minCost = INT_MAX;
int sIdx, eIdx;

void DFS(int curIdx, int cost)
{
	if (curIdx == eIdx)
	{
		if (minCost > cost)
			minCost = cost;
		return;
	}

	for (int i = 0; i < map[curIdx].size(); ++i)
	{
		if (visited[i] ||
			map[curIdx][i] == 0 ||
			cost + map[curIdx][i] > minCost)
			continue;

		visited[i] = true;
		DFS(i, cost + map[curIdx][i]);
		visited[i] = false;
	}
}

int ToIndex(char c)
{
	if (c == 'N') return 0;
	if (c == 'G') return 1;
	if (c == 'D') return 2;
	if (c == 'Y') return 3;
	return -1;
}

int main(void)
{
	char c1, c2;

	cin >> c1 >> c2;

	sIdx = ToIndex(c1);
	eIdx = ToIndex(c2);

	visited[sIdx] = true;

	DFS(sIdx, 0);

	cout << minCost;

	return 0;
}