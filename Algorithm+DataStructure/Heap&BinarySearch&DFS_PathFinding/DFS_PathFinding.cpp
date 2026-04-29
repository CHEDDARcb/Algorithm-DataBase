#include <iostream>

using namespace std;

char name[5] = "ABCD";
int map[4][4] =
{
	0, 1, 1, 0,
	1, 0, 1, 1,
	1, 1, 0, 1,
	0, 1, 1, 0
};
char history[5] = "";
int cnt = 0;

bool IsPossible(int level, int select)
{
	for (int i = 0; i <= level; ++i)
	{
		if (history[i] == name[select])
			return false;
	}

	return true;
}

void DFS(int level, int now)
{
	if (name[now] == 'D')
	{
		cnt++;
		cout << history << endl;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (map[now][i] == 1)
		{
			if (IsPossible(level, i))
			{
				history[level + 1] = name[i];
				DFS(level + 1, i);
				history[level + 1] = 0;
			}
		}
	}
}

int main(void)
{
	history[0] = name[0];

	DFS(0, 0);

	return 0;
}