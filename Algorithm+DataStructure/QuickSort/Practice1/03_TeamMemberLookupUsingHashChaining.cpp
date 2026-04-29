#include <iostream>

using namespace std;

const int TABLESIZE = 100;
const int POOLSIZE = 100;
struct Node
{
	char str[40];
	int nxt;
};
Node pool[POOLSIZE];
int table[TABLESIZE];
int poolCnt = 0;

unsigned int Hash(const char* str)
{
	unsigned int h = 0;
	while (*str)
	{
		h = h * 31 + (unsigned int)(*str);
		++str;
	}

	return h % TABLESIZE;
}

void Init()
{
	for (int i = 0; i < TABLESIZE; ++i)
	{
		table[i] = -1;
	}
}

void Insert(const char* str)
{
	int h = Hash(str);
	int newNode = poolCnt++;

	strcpy_s(pool[newNode].str, str);
	pool[newNode].nxt = table[h];
	table[h] = newNode;
}

bool Find(const char* str)
{
	int h = Hash(str);
	int cur = table[h];

	while (cur != -1)
	{
		if (!strcmp(pool[cur].str, str))
			return true;
		cur = pool[cur].nxt;
	}

	return false;
}

int main(void)
{
	Init();

	Insert("A");
	Insert("AF");
	Insert("POP");
	Insert("TOM");
	Insert("MC");
	Insert("JASON");
	Insert("KFC");

	int n;
	cin >> n;

	while (n--)
	{
		char str[40];
		cin >> str;

		if (Find(str))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}