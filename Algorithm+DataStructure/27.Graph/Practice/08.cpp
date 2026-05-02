#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> base(3, vector<int>(3));

	for (int i = 0; i < base.size(); ++i)
	{
		for (int j = 0; j < base[i].size(); ++j)
		{
			cin >> base[i][j];
		}
	}

	struct Data
	{
		int data;
		int i;
		int j;
	};
	vector<Data> tmp;
	for (int k = 0; k < 2; ++k)
	{
		int max = INT_MIN;
		int iIdx, jIdx;
		for (int i = 0; i < base.size(); ++i)
		{
			for (int j = 0; j < base[i].size(); ++j)
			{
				if (max < base[i][j])
				{
					bool isIn = false;
					for (int p = 0; p < tmp.size(); ++p)
					{
						if (tmp[p].data == base[i][j] &&
							tmp[p].i == i && tmp[p].j == j)
						{
							isIn = true;
							break;
						}
					}
					if (isIn) continue;
					else
					{
						max = base[i][j];
						iIdx = i;
						jIdx = j;
					}
				}
			}
		}

		tmp.push_back(Data{ max, iIdx, jIdx });
	}

	cout << "첫번째: " << tmp[0].data << "(" << tmp[0].i << "," << tmp[0].j << ")" << endl;
	cout << "두번쨰: " << tmp[1].data << "(" << tmp[1].i << "," << tmp[1].j << ")" << endl;

	return 0;
}