#include <iostream>
#include <vector>

using namespace std;

int inputN;
vector<int> group(256);
int gCnt = 1;
vector<char> names;
bool isCycle = false;

bool CheckCycle(char c1, char c2)
{
	if (group[c1] != 0 && group[c2] != 0)
	{
		if (group[c1] == group[c2])
			return true;
	}
	return false;
}

void MakeGroup(char c1, char c2)
{
	if (group[c1] == 0)
		names.push_back(c1);
	if (group[c2] == 0)
		names.push_back(c2);

	if (group[c1] != 0 && group[c2] == 0)
	{
		group[c2] = group[c1];
	}
	else if (group[c1] == 0 && group[c2] != 0)
	{
		group[c1] = group[c2];
	}
	else if (group[c1] == 0 && group[c2] == 0)
	{
		group[c1] = gCnt;
		group[c2] = gCnt;
		++gCnt;
	}
	else
	{
		int targetGroup = group[c2];
		for (int i = 0; i < names.size(); ++i)
		{
			if (group[names[i]] == targetGroup)
				group[names[i]] = group[c1];
		}
	}
}

void Input()
{
	cin >> inputN;

	for (int k = 0; k < inputN; ++k)
	{
		char c1, c2;

		cin >> c1 >> c2;

		isCycle |= CheckCycle(c1, c2);
		MakeGroup(c1, c2);
	}
}

int main(void)
{
	Input();

	cout << (isCycle ? "발견" : "미발견");
}