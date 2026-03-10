#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const vector<vector<int>> map =
{
	{0, 80, 60, 30},	//N
	{80, 0, 0, 40},		//G
	{60, 0, 0, 70},		//D
	{30, 40, 70, 0},	//Y
};
struct Pos
{
	int i;
	int cost;
	string path;
};
queue<Pos> que;
int sIdx, eIdx;
int minCost = INT_MAX;

bool IsPushed(Pos cur, int idx)
{
	for (int i = 0; i < cur.path.size(); ++i)
	{
		if (cur.path[i] == idx + '0')
			return true;
	}

	return false;
}

void BFS()
{
	while (!que.empty())
	{
		Pos cur = que.front();
		que.pop();

		if (cur.i == eIdx)
		{
			if (minCost > cur.cost)
				minCost = cur.cost;
			continue;
		}

		for (int i = 0; i < map[cur.i].size(); ++i)
		{
			if (map[cur.i][i] == 0 ||
				cur.cost + map[cur.i][i] > minCost ||
				IsPushed(cur, i))
				continue;

			Pos pushData{ i, cur.cost + map[cur.i][i], cur.path };
			pushData.path.push_back(i + '0');
			que.push(pushData);
		}
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

	Pos first{ sIdx, 0 };
	first.path.push_back(sIdx + '0');
	que.push(first);

	BFS();

	cout << minCost;

	return 0;
}