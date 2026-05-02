#include <iostream>
#include <vector>

using namespace std;

string adj = " ";

void DFS(int cur, int level)
{
	if (cur >= adj.size()) return;

	cout << adj[cur];

	DFS(cur * 2, level + 1);
	DFS(cur * 2 + 1, level + 1);
}

int main()
{
	string input;

	cin >> input;

	adj += input;

	DFS(1, 0);

	return 0;
}