#include <iostream>

using namespace std;

char base[4][4] =
{
	'A', 'B', 'C', 'D',
	'B', 'B', 'A', 'B',
	'C', 'B', 'A', 'C',
	'B', 'A', 'A', 'A',
};
char arr[4][4];
int map[256]{};

int GoldenMapping()
{
	int max = INT_MIN;
	int maxIDX = -1;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (arr[i][j] == base[i][j])
			{
				int num = ++map[static_cast<int>(base[i][j])];

				if (num > max)
				{
					max = num;
					maxIDX = static_cast<int>(base[i][j]);
				}
			}
		}
	}

	return maxIDX;
}


int main(void)
{
	for (auto& row : arr)
	{
		for (auto& data : row)
		{
			cin >> data;
		}
	}

	int result = GoldenMapping();

	cout << static_cast<char>(result);

	return 0;
}