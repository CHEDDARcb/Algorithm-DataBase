#include <iostream>

using namespace std;

char value[10] = "0123456";
int map[7][7] =
{
	0, 0, 0, 0, 1, 0, 1,
	0, 0, 0, 0, 0, 1, 0,
	1, 1, 0, 1, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0
};
char boss;
char under[10]{};
int underCount = 0;

void run(int cur, int prev, int level)
{
	if (value[cur] == '0')
	{
		boss = value[prev];
	}

	for (int i = 0; i < 7; ++i)
	{
		if (map[cur][i])
		{
			if (value[cur] == '0')
			{
				under[underCount++] = value[i];
			}

			run(i, cur, level + 1);
		}
	}
}


int main()
{
	run(2, -1, 0);

	cout << "boss: " << boss << endl;
	cout << "under: ";
	for (int i = 0; i < underCount; ++i)
		cout << under[i] << " ";
	return 0;
}