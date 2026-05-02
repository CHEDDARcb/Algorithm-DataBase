#include <iostream>

using namespace std;

int n;
char path[6]{};
char visited[5]{};
char member[5] = { 'B', 'T', 'S', 'K', 'R' };
int result;

void GroupPermutation(int level)
{
	if (level == n)
	{
		if (visited[2])
		{
			result++;
		}

		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		if (visited[i])
			continue;

		path[level] = member[i];
		visited[i] = true;

		GroupPermutation(level + 1);
		path[level] = '\0';
		visited[i] = false;
	}
}

int main(void)
{
	cin >> n;

	GroupPermutation(0);

	cout << result;

	return 0;
}