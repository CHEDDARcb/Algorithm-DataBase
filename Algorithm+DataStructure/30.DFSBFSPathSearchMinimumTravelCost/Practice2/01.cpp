#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> cl =
{
	{0, 12, 0},
	{9, 0, 3},
	{0, 6, 0}
};

void PrintClock()
{
	for (auto& row : cl)
	{
		for (auto& data : row)
		{
			if (data)
				cout << data << " ";
		}
	}
}

void Rotate(int rad)
{
	int rotCnt = rad / 90;

	while (rotCnt--)
	{
		for (int i = 0; i < cl.size(); ++i)
		{
			for (int j = 1 + i; j < cl[i].size(); ++j)
			{
				int tmp = cl[i][j];
				cl[i][j] = cl[j][i];
				cl[j][i] = tmp;
			}
		}

		for (int i = 0; i < cl.size(); ++i)
		{
			reverse(cl[i].begin(), cl[i].end());
		}
	}
}

int main()
{
	int rad;

	cin >> rad;

	Rotate(rad);

	PrintClock();

	return 0;
}