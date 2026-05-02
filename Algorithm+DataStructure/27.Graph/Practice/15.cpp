#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map(5, vector<int>(4));

void Mapping()
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			cin >> map[i][j];
		}
	}
}

bool LineCheck(vector<int>& line)
{
	int count = 0;
	for (auto& data : line)
	{
		if (data) count++;
	}

	return count == line.size();
}

void Scrolling(int k)
{
	for (int i = k; i >= 0; --i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			map[i + 1][j] = map[i][j];
		}
	}

	for (int i = 0; i < map[0].size(); ++i)
	{
		map[0][i] = 0;
	}
}

void PrintMap()
{
	cout << endl;
	for (auto& row : map)
	{
		for (auto& data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}
}

int main()
{
	Mapping();

	for (int k = 0; k < map.size(); ++k)
	{
		bool lineResult = LineCheck(map[k]);
		if (lineResult)
		{
			Scrolling(k - 1);
		}
	}

	PrintMap();

	return 0;
}