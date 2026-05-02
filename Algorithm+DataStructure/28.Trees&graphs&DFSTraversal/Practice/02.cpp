#include <iostream>
#include <vector>

using namespace std;

char value[10] = "ABCDEFGH";
int map[8][8] =
{
	0, 1, 1, 0, 0, 0, 0, 1,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 0, 1, 0,
	0, 0, 0, 0, 0, 1, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
};
char target;
vector<char> brothers;

void FindBrothers(int cur, int prev, int level)
{
	if (value[cur] == target)
	{
		if (prev != -1)
		{
			for (int i = 0; i < 8; ++i)
			{
				if (map[prev][i] && value[i] != target)
					brothers.push_back(value[i]);
			}
		}
	}

	for (int i = 0; i < 8; ++i)
	{
		if (map[cur][i])
		{
			FindBrothers(i, cur, level + 1);
		}
	}
}

int main()
{
	cin >> target;

	FindBrothers(0, -1, 0);

	if (brothers.size())
	{
		for (auto& brother : brothers)
			cout << brother << " ";
	}
	else
		cout << "¾øÀ½";

	return 0;
}