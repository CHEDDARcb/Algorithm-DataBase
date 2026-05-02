#include <iostream>
#include <vector>

using namespace std;

const vector<pair<char, int>> db =
{
	{'B', 10},
	{'T', 15},
	{'S', 12},
	{'G', 15},
	{'O', 14},
	{'D', 13},
	{'Z', 16},
};

struct Node
{
	char code;
	int killCount;
	Node* next;
};
vector<Node> pool(db.size());
vector<Node*> table(100, nullptr);

int Hash(int c)
{
	return c;
}

void Init()
{
	for (int i = 0; i < db.size(); ++i)
	{
		int h = Hash(db[i].first);

		pool[i].code = db[i].first;
		pool[i].killCount = db[i].second;
		pool[i].next = table[h];

		table[h] = &pool[i];
	}
}

int main(void)
{
	Init();

	char c;
	cin >> c;

	int h = Hash(c);

	Node* cur = table[h];
	while (cur != nullptr)
	{
		cout << cur->killCount << " ";
		cur = cur->next;
	}

	return 0;
}