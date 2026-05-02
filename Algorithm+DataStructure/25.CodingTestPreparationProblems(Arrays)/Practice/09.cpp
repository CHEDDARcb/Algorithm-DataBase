#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board =
{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};

bool ColumnCheck(int i, int j)
{
	char target = board[i][j];
	for (int k = 0; k < 9; ++k)
	{
		if (k != i && board[k][j] == target)
			return false;
	}

	return true;
}

bool RowrCheck(int i, int j)
{
	char target = board[i][j];
	for (int k = 0; k < 9; ++k)
	{
		if (k != j && board[i][k] == target)
			return false;
	}

	return true;
}

bool Check3X3(int i, int j)
{
	char target = board[i][j];
	int startI = (i / 3) * 3;
	int startJ = (j / 3) * 3;
	for (int p = startI; p < startI + 3; ++p)
	{
		for (int q = startJ; q < startJ + 3; ++q)
		{
			if ((p != i || q != j) && board[p][q] == target)
				return false;
		}
	}

	return true;
}

bool ValidSudoku()
{
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] >= '0' && board[i][j] <= '9')
			{
				bool rowResult = ColumnCheck(i, j);
				if (!rowResult) return false;

				bool colResult = ColumnCheck(i, j);
				if (!colResult) return false;

				bool result3X3 = Check3X3(i, j);
				if (!result3X3) return false;
			}
		}
	}



	return true;
}

int main()
{
	bool ret = ValidSudoku();

	cout << (ret ? "true" : "false");

	return 0;
}