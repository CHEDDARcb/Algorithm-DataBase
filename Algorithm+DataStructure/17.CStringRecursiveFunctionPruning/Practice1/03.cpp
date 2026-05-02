#include <iostream>

using namespace std;

char path[5]{};
char choco[3] = { 'A', 'B', 'C' };
int result = 0;

void ChocoPermutation(int level)
{
	if (level == 3)
	{
		cout << path << endl;
		result++;
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (level >= 2 &&
			((choco[i] == path[level - 2]) &&
				(choco[i] == path[level - 1])))
			continue;

		path[level] = choco[i];
		ChocoPermutation(level + 1);
		path[level] = '\0';
	}
}

int main(void)
{
	ChocoPermutation(0);

	cout << result;

	return 0;
}