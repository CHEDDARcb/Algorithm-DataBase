#include <iostream>
#include <vector>

using namespace std;

const vector<pair<char, int>> db =
{
	{'A', 21},
	{'E', 15},
	{'E', 6},
	{'A', 15},
	{'E', 34},
	{'B', 32},
	{'C', 35},
	{'C', 36},
	{'D', 14},
	{'A', 3},
};
struct Node
{
	int d;
	int nxt;
};
vector<Node> pool;
vector<int> table(100, -1);

void Init()
{
	for (int i = db.size() - 1; i >= 0; --i)
	{
		int h = db[i].first;

		pool.push_back({ db[i].second, table[h] });
		table[h] = pool.size() - 1;
	}
}

int main(void)
{
	Init();

	char c;
	cin >> c;

	int cur = table[c];
	while (cur != -1)
	{
		cout << pool[cur].d << " ";
		cur = pool[cur].nxt;
	}

	return 0;
}