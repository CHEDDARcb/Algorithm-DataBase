#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const vector<pair<int, string>> db =
{
	{1000000005, "Sour"},
	{1000000002, "Dav"},
	{1000000003, "Nica"},
	{1000000006, "Timer"},
	{1000000015, "Pico"},
	{1000000022, "Topisl"},
	{1000000013, "Whab" },
	{1000000009, "Hap"}
};

vector<int> table(10, -1);
struct Node
{
	string name;
	int nxt;
};
vector<Node> pool;
int poolSize = 0;

int Hash(int key)
{
	return key % 10;
}

void Init()
{
	for (int i = 0; i < db.size(); ++i)
	{
		int h = Hash(db[i].first);
		int newNode = poolSize++;

		pool.push_back({ db[i].second, table[h] });
		table[h] = pool.size() - 1;

		//pool[newNode].name = db[i].second;
		//pool[newNode].nxt = table[h];
		//table[h] = newNode;
	}
}

int main(void)
{
	Init();

	int input;
	cin >> input;

	int h = Hash(input);

	int cur = h;
	while (table[cur] != -1)
	{
		cout << pool[table[cur]].name << endl;
		cur = pool[table[cur]].nxt;
	}

	return 0;
}