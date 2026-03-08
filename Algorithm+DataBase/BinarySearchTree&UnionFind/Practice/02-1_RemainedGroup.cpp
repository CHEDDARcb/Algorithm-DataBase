#include <iostream>
#include <vector>

using namespace std;

vector<int> groups(256, 0);
int gCnt = 1;
vector<char> names(256);
int nCnt;

void MakeGroup(char a, char b)
{
	if (groups[a] == 0)
		names[nCnt++] = a;
	if (groups[b] == 0)
		names[nCnt++] = b;

	if (groups[a] != 0 && groups[b] == 0)
	{
		groups[b] = groups[a];
	}
	else if (groups[a] == 0 && groups[b] != 0)
	{
		groups[a] = groups[b];
	}
	else if (groups[a] == 0 && groups[b] == 0)
	{
		groups[a] = gCnt;
		groups[b] = gCnt;
		++gCnt;
	}
	else
	{
		int target = groups[a] < groups[b] ? 
			groups[b] : groups[a];
		int changeGNum = groups[a] < groups[b] ?
			groups[a] : groups[b];

		if (target == changeGNum) return;

		for (int i = 0; i < nCnt; ++i)
		{
			if (groups[names[i]] == target)
			{
				groups[names[i]] = changeGNum;
			}
		}

		--gCnt;

	}
}

void Groupping()
{
	MakeGroup('A', 'B');
	MakeGroup('B', 'C');

	MakeGroup('E', 'F');
	MakeGroup('D', 'E');

	MakeGroup('G', 'H');

	MakeGroup('I', 'J');
}

int main(void)
{
	int n;
	cin >> n;

	Groupping();

	while (n--)
	{
		char a, b;
		cin >> a >> b;

		MakeGroup(a, b);
	}

	cout << gCnt - 1;

	return 0;
}