#include <iostream>

using namespace std;

const int dir[4][2] =
{
	-1, 0,
	1, 0,
	0, 1,
	0, -1
};

template<size_t I, size_t J>
bool CanEatBlack(const char(&_go)[I][J], const int _checkY, const int _checkX)
{
	if (_go[_checkY][_checkX] != 'b')
		return false;

	for (int i = 0; i < 4; ++i)
	{
		int wY = _checkY + dir[i][0];
		int wX = _checkX + dir[i][1];

		if (_go[wY][wX] != 'w') return false;
	}

	return true;

}

int main()
{
	char go[7][7] =
	{
		{'-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', 'w', '-', 'w', '-', '-'},
		{'-', 'w', 'b', '-', 'b', 'w', '-'},
		{'-', '-', 'w', 'b', 'w', '-', '-'},
		{'-', '-', 'b', 'w', '-', 'w', '-'},
		{'-', 'w', 'w', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-'}
	};

	int y, x;

	cin >> y >> x;

	go[y][x] = 'w';

	int eatCnt = 0;
	for (int i = 0; i < 4; ++i)
	{
		int checkYIdx = y + dir[i][0];
		int checkXIdx = x + dir[i][1];

		if (checkYIdx >= 0 && checkYIdx <= 6 &&
			checkXIdx >= 0 && checkXIdx <= 6)
		{
			if (CanEatBlack(go, checkYIdx, checkXIdx))
				++eatCnt;
		}
	}

	cout << eatCnt;

	return 0;
}