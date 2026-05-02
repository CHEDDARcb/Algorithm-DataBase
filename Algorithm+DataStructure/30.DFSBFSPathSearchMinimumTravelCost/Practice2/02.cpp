#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<char> value = { 'O', 'X' };
string path;
int MAXDEPTH;

void DFS(int level)
{
	if (level == MAXDEPTH)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < value.size(); ++i)
	{
		path[level] = value[i];
		DFS(level + 1);
		path[level] = '\0';
	}
}

int main()
{
	cin >> MAXDEPTH;

	path.resize(MAXDEPTH + 1, '\0');

	DFS(0);

	return 0;
}