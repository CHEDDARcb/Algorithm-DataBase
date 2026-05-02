#include <iostream>

using namespace std;

char excepted;
char friends[5] = { 'E', 'W', 'A', 'B', 'C' };
bool visited[5]{};
char path[5]{};

void RidePermutation(int level)
{
	if (level == 4)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		if (friends[i] == excepted ||
			visited[i])
			continue;

		path[level] = friends[i];
		visited[i] = true;

		RidePermutation(level + 1);

		path[level] = '\0';
		visited[i] = false;
	}
}
int main(void)
{
	cin >> excepted;

	RidePermutation(0);

	return 0;
}