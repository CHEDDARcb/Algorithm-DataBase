/*
* 그룹묶으때 해당 그룹에 그룹번호(gCnt)를 부여
*/

#include <iostream>

using namespace std;

int name[256]{};
int n = 0;

int group[256]{};
int gCnt = 1;

void MakeGroup(char a, char b)
{
	if (group[a] == 0)
		name[n++] = a;
	if (group[b] == 0)
		name[n++] = b;

	// a그룹있음. b그룹없음
	if (group[a] != 0 && group[b] == 0)
	{
		group[b] = group[a];
	}// a그룹없음. b그룹있음
	else if (group[a] == 0 && group[b] != 0)
	{
		group[a] = group[b];
	}// a, b그룹 없음
	else if (group[a] == 0 && group[b] == 0)
	{
		group[a] = gCnt;
		group[b] = gCnt;
		++gCnt;
	}
	else // a, b 그룹 있음 -> b그룹을 A그룹으로 통합
	{
		int targetGroup = group[b];
		for (int i = 0; i < n; ++i)
		{
			if (group[name[i]] == targetGroup)
				group[name[i]] = group[a];
		}
	}
}

int main()
{
	MakeGroup('A', 'B');
	MakeGroup('A', 'C');

	MakeGroup('E', 'Q');
	MakeGroup('F', 'E');

	MakeGroup('A', 'F');
	return 0;
}

