#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> base(3, vector<int>(4));
	base[1][0] = 1;
	base[2][0] = 1;

	for (int i = 0; i < 4; ++i)
	{
		cin >> base[0][i];
	}

	for (int i = 1; i < base.size(); ++i)
	{
		for (int j = 1; j < base[i].size(); ++j)
		{
			base[i][j] = base[i][j - 1] + base[i - 1][j];
		}
	}

	for (auto& row : base)
	{
		for (auto& data : row)
			cout << data << ' ';
		cout << endl;
	}

	return 0;
}