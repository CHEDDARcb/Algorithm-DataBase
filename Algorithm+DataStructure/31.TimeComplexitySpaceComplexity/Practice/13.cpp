#include <iostream>
#include <vector>

using namespace std;

struct Data
{
	int data;
	int i;
	int j;
};

vector<vector<int>> A =
{
	{2, 6, 3},
	{7, 1, 1},
	{3, 4, 2}
};
vector<vector<int>> B =
{
	{6, 4, 2, 4},
	{1, 1, 5, 8}
};
vector<vector<int>> C =
{
	{9, 2, 3},
	{4, 2, 1}
};

vector<vector<int>> result(3, vector<int>(3));

bool IsIn(const vector<Data>& base, const Data& target)
{
	for (auto citer = base.cbegin(); citer != base.cend(); ++citer)
	{
		if ((*citer).data == target.data &&
			(*citer).i == target.i &&
			(*citer).j == target.j)
			return true;
	}

	return false;
}
void SortASC(vector<vector<int>>& target)
{
	for (int i = 0; i < target.size(); ++i)
	{
		for (int j = 0; j < target[i].size(); ++j)
		{
			int minI = i;
			int minJ = j;

			for (int q = i; q < target.size(); ++q)
			{
				for (int p = (q == i ? j + 1 : 0); p < target[i].size(); ++p)
				{
					if (target[minI][minJ] > target[q][p])
					{
						minI = q;
						minJ = p;
					}
				}
			}

			int tmp = target[minI][minJ];
			target[minI][minJ] = target[i][j];
			target[i][j] = tmp;
		}
	}
}
void FindMax(const int count, vector<vector<int>>& target, int inputRow, int inputCol)
{
	SortASC(target);

	int pushCount = 0;
	for (int i = target.size() - 1; i >= 0; --i)
	{
		for (int j = target[i].size() - 1; j >= 0; --j)
		{
			if (pushCount == count) return;

			result[inputRow][inputCol++] = target[i][j];
			++pushCount;
		}
		++inputRow;
		inputCol = 0;
	}
}
void FindMin(const int count, vector<vector<int>>& target, int inputRow, int inputCol)
{
	SortASC(target);

	int pushCount = 0;
	for (int i = 0; i < target.size(); ++i)
	{
		for (int j = 0; j < target[i].size(); ++j)
		{
			if (pushCount == count) return;

			result[inputRow][inputCol++] = target[i][j];
			++pushCount;
		}
		++inputRow;
		inputCol = 0;
	}
}
void AFunc()
{
	FindMax(3, A, 0, 0);
}

void BFunc()
{
	FindMin(3, B, 1, 0);
}

void CFunc()
{
	FindMin(2, C, 2, 0);
	FindMax(1, C, 2, 2);
}

int main()
{
	AFunc();
	BFunc();
	CFunc();

	for (auto& row : result)
	{
		for (auto& data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}

	return 0;
}