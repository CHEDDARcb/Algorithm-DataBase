#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map(4, vector<int>(5));
int minI = INT_MAX;
int minJ = INT_MAX;
int maxI = INT_MIN;
int maxJ = INT_MIN;

void InitMap()
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			cin >> map[i][j];
		}
	}
}

void FindFrame()
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if (map[i][j])
			{
				if (minI > i) minI = i;
				if (minJ > j) minJ = j;
				if (maxI < i) maxI = i;
				if (maxJ < j) maxJ = j;
			}
		}
	}
}

int main()
{
	InitMap();
	FindFrame();

	cout << "(" << minI << "," << minJ << ")" << endl;
	cout << "(" << maxI << "," << maxJ << ")" << endl;

	return 0;
}