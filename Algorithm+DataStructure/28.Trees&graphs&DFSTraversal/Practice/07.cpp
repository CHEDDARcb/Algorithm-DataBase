#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map =
{
	{3, 5, 1},
	{3, 1, 2},
	{3, 4, 6},
	{5, 4, 6}
};
vector<int> dat;

int main()
{
	dat.resize(7, 0);

	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			++dat[map[i][j]];
		}
	}

	for (int i = 1; i < dat.size(); ++i)
	{
		cout << i << " ";
		for (int j = 0; j < dat[i]; ++j)
			cout << "* ";
		cout << endl;
	}

	return 0;
}