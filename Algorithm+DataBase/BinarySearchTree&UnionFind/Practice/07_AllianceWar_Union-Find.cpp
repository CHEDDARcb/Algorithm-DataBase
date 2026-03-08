#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct Country
{
	char parent;
	int num;
};

int n;
vector<Country> parents;
vector<int> rnk;

void Input()
{
	cin >> n;

	parents.resize(n);
	rnk.resize(n, 0);

	int i = 0;
	for (auto iter = parents.begin(); iter != parents.end(); ++iter)
	{
		int pN;
		cin >> pN;

		(*iter).parent = 'A' + i++;
		(*iter).num = pN;
	}
}

char GetParent(char c)
{
	if (parents[c - 'A'].parent == c)
		return c;

	char ret = GetParent(parents[c - 'A'].parent);
	return parents[c - 'A'].parent = ret;
}

void MakeGroup(char c1, char c2)
{
	int a = GetParent(c1) - 'A';
	int b = GetParent(c2) - 'A';

	if (rnk[a] < rnk[b])
		swap(a, b);
	if (a == b)
		return;

	parents[b].parent = a + 'A';

	if (rnk[a] == rnk[b])
		++rnk[a];
}

int War(char c1, char c2)
{
	int c1GroupNum = 0;
	int c2GroupNum = 0;
	int c1PeopleNum = 0;
	int c2PeopleNum = 0;

	for (int i = 0; i < parents.size(); ++i)
	{
		if (GetParent(i + 'A') == GetParent(c1))
		{
			++c1GroupNum;
			c1PeopleNum += parents[i].num;
		}
		else if (GetParent(i + 'A') == GetParent(c2))
		{
			++c2GroupNum;
			c2PeopleNum += parents[i].num;
		}
	}

	if (c1PeopleNum > c2PeopleNum)
		return parents.size() - c2GroupNum;
	else
		return parents.size() - c1GroupNum;
}

int main(void)
{
	Input();

	int cmdCnt;
	cin >> cmdCnt;

	while (cmdCnt--)
	{
		vector<string> cmd(3);
		for (int i = 0; i < cmd.size(); ++i)
			cin >> cmd[i];

		if (cmd[0] == "alliance")
			MakeGroup(cmd[1][0], cmd[2][0]);
		else if (cmd[0] == "war")
			cout << War(cmd[1][0], cmd[2][0]);
	}

	return 0;
}