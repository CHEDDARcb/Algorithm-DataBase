#include <iostream>

using namespace std;

bool FindTeam(const int _base[], const int _startIdx,
	const int _pattern[], const size_t _pSize)
{
	for (size_t i = 0; i < _pSize; ++i)
	{
		if (_base[i + _startIdx] != _pattern[i])
			return false;
	}

	return true;
}

int main()
{
	const int train[8] = { 3, 7, 6, 4, 2, 9, 1, 7 };
	int team[3];

	for (auto& data : team)
		cin >> data;

	int trainLen = sizeof(train) / sizeof(int);
	int teamLen = sizeof(team) / sizeof(int);

	for (int i = 0; i < trainLen - teamLen + 1; ++i)
	{
		if (FindTeam(train, i, team, teamLen))
		{
			cout << i << "¹ø~" << i + 2 << "¹ø Ä­" << endl;
		}
	}

	return 0;
}