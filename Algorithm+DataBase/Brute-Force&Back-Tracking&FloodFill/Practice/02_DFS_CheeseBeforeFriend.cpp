#include <iostream>
#include <vector>

using namespace std;

const vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};
const vector<vector<int>> map =
{
	{0, 0, 0, 0, -1},
	{-1, 0, -1, 0, 0},
	{0, 0, 0, 0, -1}
};
vector<vector<bool>> visited(3, vector<bool>(5, false));
const int cy = 2;
const int cx = 0;
const int fy = 0;
const int fx = 3;

int cMinCost = INT_MAX;
int fMinCost = INT_MAX;

void FindCheese(int y, int x, int cost)
{
	visited[y][x] = true;

	if (y == cy && x == cx)
	{
		if (cMinCost > cost)
			cMinCost = cost;

		return;
	}

	for (int i = 0; i < dir.size(); ++i)
	{
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		if (newY < 0 || newY >= map.size() ||
			newX < 0 || newX >= map[newY].size() ||
			visited[newY][newX] ||
			map[newY][newX] == -1)
			continue;

		FindCheese(newY, newX, cost + 1);
		visited[newY][newX] = false;
	}
}

void FindFriend(int y, int x, int cost)
{
	visited[y][x] = true;

	if (y == fy && x == fx)
	{
		if (fMinCost > cost)
			fMinCost = cost;

		return;
	}

	for (int i = 0; i < dir.size(); ++i)
	{
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		if (newY < 0 || newY >= map.size() ||
			newX < 0 || newX >= map[newY].size() ||
			visited[newY][newX] ||
			map[newY][newX] == -1)
			continue;

		FindFriend(newY, newX, cost + 1);
		visited[newY][newX] = false;
	}
}

int main(void)
{
	FindCheese(0, 0, 0);

	visited.assign(3, vector<bool>(5, false));

	FindFriend(cy, cx, 0);

	int result = cMinCost + fMinCost;

	cout << result;

	return 0;
}