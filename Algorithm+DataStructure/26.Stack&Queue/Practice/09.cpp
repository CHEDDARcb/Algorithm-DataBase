#include <iostream>
#include <vector>

using namespace std;

const vector<vector<int>> base =
{
	{3, 5, 1, 4},
	{2, 2, 1, 1},
	{0, 1, 2, 3},
	{3, 1, 3, 1}
};

void PrintLine(char moji)
{
	int idx = -1;

	if (moji >= '0' && moji <= '9')
	{
		idx = moji - '0';
		vector<int>::const_iterator iter = base[idx].cbegin();

		for (; iter != base[idx].cend(); ++iter)
			cout << *iter;
	}
	else
	{
		idx = moji - 'A';
		vector<vector<int>>::const_iterator iter = base.cbegin();
		for (; iter != base.cend(); ++iter)
			cout << (*iter)[idx];
	}

}

int main()
{
	char input;

	cin >> input;

	PrintLine(input);

	return 0;
}