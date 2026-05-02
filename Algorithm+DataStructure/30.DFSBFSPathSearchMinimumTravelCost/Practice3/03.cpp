#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
vector<vector<int>> arr(6, vector<int>(6));
vector<bool> visited(6, false);
string path;

void Input()
{
	path.resize(6, '\0');

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cin >> arr[i][j];
		}
	}
}

void DFS(int curIdx, int curLev)
{
	bool levelUp = false;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[curIdx][i] && !visited[i])
		{
			levelUp = true;

			visited[i] = true;
			path[curLev] = 'A' + i;

			DFS(i, curLev + 1);

			visited[i] = false;
			path[curLev] = '\0';
		}
	}

	if (!levelUp)
		cout << path << endl;
}

int main()
{
	Input();

	visited[0] = true;
	path[0] = 'A';

	DFS(0, 1);
}