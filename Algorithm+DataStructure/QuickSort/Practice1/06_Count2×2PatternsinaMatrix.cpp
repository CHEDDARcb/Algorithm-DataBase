#include <iostream>

using namespace std;

const int TABLESIZE = 100;
const int POOLSIZE = 100;
struct Node
{
	string str;
	int size;
	int nxt;

	Node()
		: size(0)
	{
	}
};
Node pool[POOLSIZE];
int table[TABLESIZE];
int poolCnt = 0;

const char base[6][6] =
{
	{'A', 'B', 'A', 'B', 'A', 'B'},
	{'C', 'D', 'C', 'D', 'C', 'D'},
	{'A', 'G', 'G', 'F', 'H', 'A'},
	{'B', 'B', 'F', 'A', 'B', 'C'},
	{'D', 'D', 'C', 'C', 'D', 'D'},
	{'F', 'F', 'D', 'H', 'A', 'S'},
};

unsigned int Hash(const string& str)
{
	unsigned int h = 0;
	for (int i = 0; i < str.size(); ++i)
		h = h * 31 + (unsigned int)(str[i]);

	return h % TABLESIZE;
}

void Insert(const string& str)
{
	unsigned int h = Hash(str);
	int newNode = poolCnt++;

	if (table[h] == -1)
		pool[newNode].size = 1;
	else
		pool[newNode].size = pool[table[h]].size + 1;

	pool[newNode].str = str;
	pool[newNode].nxt = table[h];
	table[h] = newNode;

}

void Init()
{
	for (int i = 0; i < TABLESIZE; ++i)
		table[i] = -1;

	const int dir[4][2] =
	{
		0, 0,
		0, 1,
		1, 0,
		1, 1
	};

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6 - 1; ++j)
		{
			string str;
			int k = 0;
			for (; k < 4; ++k)
			{
				int newI = i + dir[k][0];
				int newJ = j + dir[k][1];

				if (newI < 0 || newI >= 6 ||
					newJ < 0 || newJ >= 6)
					break;

				str.push_back(base[newI][newJ]);
			}
			if(k == 4)
				Insert(str);
		}
	}
}

int Find(const string& str)
{
	int h = Hash(str);
	int cur = table[h];

	if (cur == -1)
		return 0;

	int cnt = 0;
	while (cur != -1)
	{
		if (pool[cur].str == str)
			cnt++;

		cur = pool[cur].nxt;
	}

	return cnt;
}

int main(void)
{
	Init();

	string input;
	for (int i = 0; i < 4; ++i)
	{
		char c;
		cin >> c;
		input.push_back(c);
	}

	int result = Find(input);
	cout << result << endl;

	return 0;
}