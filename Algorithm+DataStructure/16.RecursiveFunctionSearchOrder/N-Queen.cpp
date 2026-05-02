#include <iostream>

using namespace std;

class NQueens
{
public:
	NQueens(int n)
		: mSize(n)
	{
		for (int i = 0; i < MAX_SIZE; ++i)
		{
			for (int j = 0; j < MAX_SIZE; ++j)
			{
				mBoard[i][j] = 0;
			}
			mPath[i] = -1;
		}
	}

public:
	void Solve()
	{
		SolveRecursive(0);
		cout << "총 " << mSolutionCount << "개의 해가 있습니다." << endl;
	}

private:
	bool IsSafe(int row, int col)
	{
		for (int i = 0; i < row; ++i)
		{
			if (mPath[i] == col)
				return false;
		}

		for (int i = 0; i < row; ++i)
		{
			if (abs(mPath[i] - col) == abs(i - row))
				return false;
		}

		return true;
	}
	void SolveRecursive(int row)
	{
		if (row == mSize)
		{
			mSolutionCount++;
			PrintSolution();
			return;
		}

		for (int col = 0; col < mSize; ++col)
		{
			if (IsSafe(row, col))
			{
				mPath[row] = col;
				mBoard[row][col] = 1;
				SolveRecursive(row + 1);
				mBoard[row][col] = 0;
				mPath[row] = -1;
			}
		}
	}
	void PrintSolution()
	{
		cout << "Solution " << mSolutionCount << ":" << endl;
		for (int i = 0; i < mSize; ++i)
		{
			for (int j = 0; j < mSize; j++)
			{
				cout << (mBoard[i][j] ? "Q " : ". ");
			}
			cout << endl;
		}
	}

private:
	static const int MAX_SIZE = 10;
	int mBoard[MAX_SIZE][MAX_SIZE];
	int mPath[MAX_SIZE];
	int mSize;
	int mSolutionCount = 0;

};

int main()
{
	int n;

	cout << "N-Queens 문제 해결기" << endl;
	cout << "체스판의 크기를 입력하세요 (1-10): ";
	cin >> n;

	cout << endl << n << "x" << n << " 체스판에서 " << n << "개의 퀸을 배치하는 모든 경우: " << endl << endl;

	NQueens nqueens(n);
	nqueens.Solve();

	return 0;
}