#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
int n;

void Input()
{
	cin >> n;
	map.resize(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}
}

int m = INT_MIN;
void DFS(int curLev, int prevI, int mult)
{
	if (curLev == n)
	{
		if (mult > m)
			m = mult;
		return;
	}

	int curI = prevI + 1;
	for (int i = 0; i < map[curI].size(); ++i)
	{
		if (map[curI][i] == 0)
			continue;

		DFS(curLev + 1, curI, mult * map[curI][i]);
	}
}

int main(void)
{
	Input();

	DFS(0, -1, 1);

	cout << m;

	return 0;
}