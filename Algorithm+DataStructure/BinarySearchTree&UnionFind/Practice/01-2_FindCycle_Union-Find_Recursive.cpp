#include <iostream>
#include <vector>

using namespace std;

vector<int> parent(256);
bool isCycle = false;

int GetParent(char c)
{
	if (parent[c] == 0)
		return c;
	else
	{
		int grandP = GetParent(parent[c]);
		parent[c] = grandP;
		return grandP;
	}
}

bool MakeGroup(char c1, char c2)
{
	int p1 = GetParent(c1);
	int p2 = GetParent(c2);

	if (p1 < p2)
	{
		parent[p2] = p1;
		return false;
	}
	else if (p1 > p2)
	{
		parent[p1] = p2;
		return false;
	}
	else
	{
		parent[p1] = p2;
		return true;
	}

}

void Input()
{
	int n;
	cin >> n;

	for (int k = 0; k < n; ++k)
	{
		char c1, c2;
		cin >> c1 >> c2;

		if (isCycle = MakeGroup(c1, c2))
			break;
	}
}

int main(void)
{
	Input();

	cout << (isCycle ? "발견" : "미발견");
}