#include <iostream>
#include <vector>

using namespace std;

vector<string> value(3);
vector<string> path(3);

void DFS(int curIdx, int curLev)
{
	if (curLev == 3)
	{
		for (auto& data : path)
			cout << data << " ";
		cout << endl;
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		path[curLev] = value[i];
		DFS(i, curLev + 1);
		path[curLev].erase();
	}
}

int main()
{
	for (int i = 0; i < 3; ++i)
	{
		cin >> value[i];
	}

	DFS(-1, 0);
}