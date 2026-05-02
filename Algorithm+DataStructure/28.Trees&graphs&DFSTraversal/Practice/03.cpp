#include <iostream>
#include <vector>

using namespace std;

char value[10] = " ADFZCGQH";

char pc1, pc2;
bool IsParrent_Child(int cur, int prev, int level)
{
	if (value[cur] == '\0') return false;

	if (cur > 1)
	{
		if (value[cur] == pc1
			&& value[prev] == pc2)
			return true;
		else if (value[cur] == pc2
			&& value[prev] == pc1)
			return true;
	}

	if (IsParrent_Child(cur * 2, cur, level + 1)) return true;
	if (IsParrent_Child(cur * 2 + 1, cur, level + 1)) return true;

	return false;
}

int main()
{
	cin >> pc1 >> pc2;

	if (IsParrent_Child(1, -1, 0))
		cout << "부모자식관계" << endl;
	else
		cout << "아님" << endl;

	return 0;
}