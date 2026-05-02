#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> base =
{
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9}
};

void ReverseRow(vector<int>::iterator b, vector<int>::iterator e)
{
	reverse(b, e);
}

void Transpos(vector<vector<int>>& base)
{
	int arrN = base.size();
	for (int i = 0; i < base.size() - 1; ++i)
	{
		for (int j = 0; j < base.size() - i - 1; ++j)
		{
			int switchI = arrN - j - 1;
			int switchJ = arrN - i - 1;

			int tmp = base[i][j];
			base[i][j] = base[switchI][switchJ];
			base[switchI][switchJ] = tmp;
		}
	}
}

int main()
{
	for (int i = 0; i < base.size(); ++i)
	{
		ReverseRow(base[i].begin(), base[i].end());
	}

	Transpos(base);

	for (auto& row : base)
	{
		for (auto data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}

	return 0;
}