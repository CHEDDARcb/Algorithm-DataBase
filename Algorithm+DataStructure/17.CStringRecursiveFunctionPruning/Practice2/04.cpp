#include <iostream>

using namespace std;

int base[3][4] =
{
	3, 5, 4, 1,
	1, 1, 2, 3,
	6, 7, 1, 2
};
int ck[4];

int ChangeIdx(int idx)
{
	if (idx == 3) return 0;
	else return idx + 1;
}

int FindIdx(int num)
{
	for (int i = 0; i < 4; ++i)
	{
		if (num == ck[i]) return i;
	}

	return -1;
}

int main(void)
{
	for (auto& data : ck)
		cin >> data;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int idx;
			if ((idx = FindIdx(base[i][j])) >= 0)
			{
				int changeIdx = ChangeIdx(idx);
				base[i][j] = ck[changeIdx];
			}
		}
	}

	for (const auto& row : base)
	{
		for (const auto& data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}

}