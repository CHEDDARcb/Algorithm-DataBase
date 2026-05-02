#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> base(3, vector<int>(3));

bool IsSame(const vector<int>& vec)
{
	int f = 0;
	int l = vec.size() - 1;
	int num = vec[0];

	while (f <= l)
	{
		if (num != vec[f] ||
			num != vec[l])
			return false;
		++f;
		--l;
	}

	return true;
}

int main()
{
	for (int i = 0; i < base.size(); ++i)
	{
		for (int j = 0; j < base[i].size(); ++j)
		{
			cin >> base[i][j];
		}
	}

	for (int i = 0; i < base.size(); ++i)
	{
		if (IsSame(base[i]))
			cout << base[i][0] << endl;
		else
			cout << "x" << endl;
	}

	return 0;
}