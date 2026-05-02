#include <iostream>
#include <vector>

using namespace std;

string input;

void DFS(int cur, int level)
{
	if (cur >= input.size() || input[cur] == '#') return;

	if (input[cur] >= 'A' &&
		input[cur] <= 'Z')
		cout << input[cur];

	DFS(cur * 2, level + 1);
	DFS(cur * 2 + 1, level + 1);
}

int main()
{
	cin >> input;

	DFS(1, 0);

	return 0;
}