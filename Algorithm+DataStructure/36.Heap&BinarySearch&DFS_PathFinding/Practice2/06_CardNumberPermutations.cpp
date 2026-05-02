#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> name;
string path;
vector<bool> visited;
int cnt = 0;

void Input()
{
	for (int k = 0; k < 4; ++k)
	{
		char c;
		cin >> c;
		name.push_back(c);
	}

	visited.resize(name.size(), false);
}

bool IsBigger3000(string& snum)
{
	int num = stoi(snum);
	if (num > 3000)
		return true;
	else
		return false;
}

void DFS(int curLev)
{
	if (curLev == 4)
	{
		if (IsBigger3000(path))
		{
			cout << path << endl;
			++cnt;
		}

		return;
	}

	for (int i = 0; i < name.size(); ++i)
	{
		if (visited[i]) continue;

		path.push_back(name[i]);
		visited[i] = true;

		DFS(curLev + 1);

		path.pop_back();
		visited[i] = false;
	}
}

int main()
{
	Input();

	DFS(0);

	return 0;
}