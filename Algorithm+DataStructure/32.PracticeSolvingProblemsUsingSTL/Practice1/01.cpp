#include <iostream>
#include <vector>

using namespace std;

struct Set
{
	int n;
	char c;

	bool operator<(const Set& sur)
	{
		if (n != sur.n)
			return n < sur.n;
		else
			return c < sur.n;
	}
};
vector<Set> set;
int n;

void Init()
{
	cin >> n;
	set.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> set[i].n >> set[i].c;
	}
}

void InsertSort()
{
	if (set.size() <= 1) return;

	for (int i = 1; i < set.size(); ++i)
	{
		Set min = set[i];
		int j = i - 1;
		for (; j >= 0 && min < set[j]; --j)
		{
			set[j + 1] = set[j];
		}
		set[j + 1] = min;
	}
}

int main(void)
{
	Init();

	InsertSort();

	for (auto& data : set)
	{
		cout << data.n << " " << data.c << endl;
	}
}