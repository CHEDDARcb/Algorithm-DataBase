#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
vector<vector<int>> arr(3, vector<int>(3));
vector<vector<int>> target(3, vector<int>(3));

void Input()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> arr[i][j];
		}

	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> target[i][j];
		}

	}
}
bool Compare()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] != target[i][j])
				return false;
		}
	}

	return true;
}
void Rotate()
{
	int f, l;
	for (int i = 0; i < 3; ++i)
	{
		f = 0;
		l = 2;

		while (f < l)
		{
			int tmp = arr[i][f];
			arr[i][f] = arr[i][l];
			arr[i][l] = tmp;

			++f;
			--l;
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 1 + i; j < 3; ++j)
		{
			int tmp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = tmp;
		}
	}
}
void Solution()
{
	int maxRotate = 3;
	while (maxRotate--)
	{
		if (Compare())
			return;
		Rotate();
		++cnt;
	}
	cnt = -1;
}
int main()
{
	Input();
	Solution();

	cout << cnt;
}