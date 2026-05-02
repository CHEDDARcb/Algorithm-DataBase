#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map =
{
	{0, 0, 0, 0, 10},
	{0, 0, 6, 2, 3},
	{1, 0, 0, 0, 0},
	{8, 0, 0, 0, 0},
	{4, 0, 2, 0, 0}
};
string name = "BGHKT";
vector<bool> visited(name.size());
string path;
char strt;
char nd;
int s;
int e;

void InitStartEnd()
{
	switch (strt)
	{
	case 'B':
		s = 0;
		break;
	case 'G':
		s = 1;
		break;
	case 'H':
		s = 2;
		break;
	case 'K':
		s = 3;
		break;
	case 'T':
		s = 4;
		break;
	default:
		break;
	};

	switch (nd)
	{
	case 'B':
		e = 0;
		break;
	case 'G':
		e = 1;
		break;
	case 'H':
		e = 2;
		break;
	case 'K':
		e = 3;
		break;
	case 'T':
		e = 4;
		break;
	default:
		break;
	}
}

void DFS(int curLev, int curIdx, int cost,
	string& minPath, int& minCost, bool& isFind)
{
	if (name[curIdx] == name[e])
	{
		isFind = true;
		if (cost < minCost)
		{
			minCost = cost;
			minPath = path;
		}
		return;
	}

	for (int i = 0; i < map.size(); ++i)
	{
		if (map[curIdx][i] > 0 && !visited[i])
		{
			path.push_back(name[i]);
			visited[i] = true;

			DFS(curLev + 1, i, cost + map[curIdx][i],
				minPath, minCost, isFind);

			path.pop_back();
			visited[i] = false;
		}
	}
}

int main(void)
{
	cin >> strt >> nd;

	InitStartEnd();

	path.push_back(name[s]);
	visited[s] = true;

	string minPath;
	int minCost = INT_MAX;
	bool isFind = false;
	DFS(1, s, 0, minPath, minCost, isFind);

	if (isFind)
	{
		cout << minCost << ':' << minPath;
	}
	else
		cout << "Impossible" << endl;
}