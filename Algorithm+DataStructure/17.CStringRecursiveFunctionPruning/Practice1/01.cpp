#include <iostream>

using namespace std;

char path[5]{};
bool visited[5]{};
char names[4];

void GenPermutation(int level)
{
	if (level == 3)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (visited[i] == true)
			continue;

		path[level] = names[i];
		visited[i] = true;

		GenPermutation(level + 1);

		path[level] = '\0';
		visited[i] = false;
	}
}

int main()
{
	for (auto& data : names)
	{
		cin >> data;
	}

	GenPermutation(0);

	return 0;
}