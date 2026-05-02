#include <iostream>
#include <vector>

using namespace std;

int maxDepth;
vector<char> path(maxDepth, '0');
vector<char> name = { 'A', 'B', 'C', 'D' };
vector<bool> visit;

void GenNon_RepeitPermutation(int level)
{
	if (level == maxDepth)
	{
		for (auto& data : path) cout << data;
		cout << endl;
		return;
	}

	for (int i = 0; i < name.size(); ++i)
	{
		if (visit[i]) continue;

		path[level] = name[i];
		visit[i] = true;
		GenNon_RepeitPermutation(level + 1);
		path[level] = '0';
		visit[i] = false;
	}
}

int main()
{
	cin >> maxDepth;

	path.resize(maxDepth, '0');
	visit.resize(name.size(), false);

	GenNon_RepeitPermutation(0);

	return 0;
}