/*
* 그룹으로 엮을 때 그룹 내의 한 요소를 대표(부모)로써 설정.
*/
#include <iostream>

using namespace std;

char parent[256]{};

char GetParent(char x)
{
	// 아직 부모가 없을 경우, 자기 자신을 부모로 설정.
	if (parent[x] == 0)
		return x;

	// 부모가 존재할 경우, 최상위 부모까지 올라가 해당 부모로 그룹을 엮는다.
	int ret = GetParent(parent[x]);
	parent[x] = ret;

	return ret;
}

void MakeGroup(char ch1, char ch2)
{
	int a = GetParent(ch1);
	int b = GetParent(ch2);

	// b를 a그룹으로 통합.
	if (a != b)
		parent[b] = a;
}

int main(void)
{
	MakeGroup('A', 'B');
	MakeGroup('B', 'C');

	MakeGroup('E', 'Q');
	MakeGroup('F', 'E');

	MakeGroup('A', 'F');
}