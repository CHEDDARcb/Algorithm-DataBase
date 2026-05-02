#include <iostream>
#include <vector>
using namespace std;

const int I = 3;
const int J = 6;
vector<char> taiyakis(I* J, '-');

void Init()
{
	for (int i = 0; i < I; ++i)
	{
		for (int j = 0; j < J; ++j)
		{
			taiyakis[j + J * i] = 'A' + (j + J * i);
		}
	}
}

void Reverse(char c)
{
	int idx = c - 'A';
	int i = idx / J;
	int j = idx % J;
	const vector<vector<int>> dir =
	{
		{0, 0},
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};

	for (int k = 0; k < dir.size(); ++k)
	{
		int newI = dir[k][0] + i;
		int newJ = dir[k][1] + j;

		if (newI < 0 || newI >= I ||
			newJ < 0 || newJ >= J)
			continue;

		if (taiyakis[newJ + J * newI] == '#')
		{
			taiyakis[newJ + J * newI] = 'A' + (newJ + J * newI);
		}
		else
		{
			taiyakis[newJ + J * newI] = '#';
		}
	}
}

int main(void)
{
	Init();

	string target;
	cin >> target;

	for (int i = 0; i < target.size(); ++i)
	{
		char c = target[i];
		Reverse(c);
	}

	for (int i = 0; i < I; ++i)
	{
		for (int j = 0; j < J; ++j)
		{
			cout << taiyakis[j + J * i];
		}
		cout << endl;
	}

	return 0;
}