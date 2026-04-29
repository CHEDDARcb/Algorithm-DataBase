#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int n, k;

vector<int> parent; //고기 식별은 숫자
vector<int> lev;
vector<char> rnk;

int GetParent(int c)
{
	if (parent[c] == c)
		return c;
	int ret = GetParent(parent[c]);
	return parent[c] = ret;
}

void MakeGroup(int c1, int c2)
{
	int a = GetParent(c1);
	int b = GetParent(c2);

	if (lev[a] < lev[b])
		swap(a, b);

	parent[b] = a;

	if (lev[a] == lev[b])
		lev[a]++;
}

void RankingGroup(char rank, int target)
{
	rnk[target] = rank;

	int tp = GetParent(target);
	for (int i = 0; i < parent.size(); ++i)
	{
		if (GetParent(parent[i]) == tp)
			rnk[i] = rank;
	}
}

void Input()
{
	cin >> n >> k;

	parent.resize(k + 1);
	iota(parent.begin(), parent.end(), 0);

	lev.resize(k + 1, 0);
	rnk.resize(k + 1, '\0');

	for (int i = 0; i < n; ++i)
	{
		char c1, c2;
		cin >> c1 >> c2;

		if (c1 >= '1' && c1 <= '9' &&
			c2 >= '1' && c2 <= '9')
		{
			MakeGroup(c1 - '0', c2 - '0');

			if (rnk[c1 - '0'] >= 'A' && rnk[c1 - '0'] <= 'F')
				RankingGroup(rnk[c1 - '0'], c2 - '0');
			else if (rnk[c2 - '0'] >= 'A' && rnk[c2 - '0'] <= 'F')
				RankingGroup(rnk[c2 - '0'], c1 - '0');
		}
		else if (c1 >= 'A' && c1 <= 'F' &&
			c2 >= '1' && c2 <= '9')
		{
			RankingGroup(c1, c2 - '0');
		}
		else if (c1 >= '1' && c1 <= '9' &&
			c2 >= 'A' && c2 <= 'F')
		{
			RankingGroup(c2, c1 - '0');
		}

	}
}

void PrintAllRank()
{
	for (int i = 1; i < rnk.size(); ++i)
	{
		cout << rnk[i];
	}
}

int main(void)
{
	Input();

	PrintAllRank();

	return 0;
}