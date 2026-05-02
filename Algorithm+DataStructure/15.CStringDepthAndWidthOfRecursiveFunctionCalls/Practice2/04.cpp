#include <iostream>

using namespace std;

char arr[4][3];

void Gravity(const char _ship, int i, int j)
{
	if (i >= 3 || arr[i + 1][j] != '_')
	{
		arr[i][j] = _ship;
		return;
	}

	arr[i][j] = '_';
	Gravity(_ship, i + 1, j);
}

int main()
{
	for (auto& row : arr)
	{
		for (auto& data : row)
			cin >> data;
	}

	for (int i = 2; i >= 0; --i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] != '_')
			{
				Gravity(arr[i][j], i, j);
			}
		}
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			cout << data;
		}
		cout << endl;
	}
	return 0;
}