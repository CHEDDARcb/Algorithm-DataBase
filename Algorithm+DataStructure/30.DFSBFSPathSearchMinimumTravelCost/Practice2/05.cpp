#include <iostream>
#include <vector>

using namespace std;

string value;
string path;
int maxLevel;

void Input()
{
	cin >> value;
	cin >> maxLevel;

	path.resize(value.size() + 1, '\0');
}

void DFS(int curLev)
{
	if (curLev == maxLevel)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < value.size(); ++i)
	{
		path[curLev] = value[i];
		DFS(curLev + 1);
		path[curLev] = '\0';
	}
}


int main()
{
	Input();
	DFS(0);

	return 0;
}