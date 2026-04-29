#include <iostream>
#include <vector>

using namespace std;

const vector<vector<vector<int>>> type =
{
	{
		{-1, 0},
		{0, 0},
		{0, -1},
		{0, 1},
		{1, 0}
	},
	{
		{-1, -1},
		{0, 0},
		{-1, 1},
		{1, 1},
		{1, -1}
	}
};
vector<vector<char>> cuji;
int n, k;
struct Order
{
	int ci;
	int cj;
	int t;
};
vector<Order> order;

void Input()
{
	cin >> n >> k;

	cuji.resize(n, vector<char>(n));
	order.resize(k);
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> cuji[i][j];
		}
	}

	for (int i = 0; i < k; ++i)
	{
		int ci, cj, t;
		cin >> ci >> cj >> t;

		order[i] = Order{ ci, cj, t - 1 };
	}
}

bool CheckRange(int i, int j)
{
	if (i >= 0 && i < n &&
		j >= 0 && j < n)
		return true;
	return false;
}

int main(void)
{
	Input();

	for (int z = 0; z < k; ++z)
	{
		int ci = order[z].ci;
		int cj = order[z].cj;
		int t = order[z].t;

		for (int c = 0; c < type[t].size(); ++c)
		{
			int newIdx = ci + type[t][c][0];
			int newJdx = cj + type[t][c][1];

			if (CheckRange(newIdx, newJdx))
				cout << cuji[newIdx][newJdx];
		}

		cout << endl;
	}

	return 0;
}