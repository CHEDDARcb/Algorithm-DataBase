#include <iostream>

using namespace std;

template <size_t H, size_t W, size_t T, size_t D>
bool StableCheck(const int(&_base)[H][W], int cy, int cx, const int(&_dir)[T][D])
{
	for (int i = 0; i < 8; ++i)
	{
		int ty = _dir[i][0];
		int tx = _dir[i][1];

		int ny = cy + ty;
		int nx = cx + tx;

		if (ny >= 0 && ny < H &&
			nx >= 0 && nx < W)
		{
			if (_base[ny][nx] == 1)
				return false;
		}
	}

	return true;
}

int main()
{
	const int direct[8][2] =
	{
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};
	int arr[5][4]{};

	for (auto& row : arr)
		for (auto& data : row)
			cin >> data;

	bool isStable = true;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (arr[i][j] &&
				!StableCheck(arr, i, j, direct))
			{
				isStable = false;
				break;
			}
		}

		if (!isStable) break;
	}

	if (isStable)
		cout << "안정된 상태";
	else
		cout << "불안정한 상태";

	return 0;
}