#include <iostream>

using namespace std;

char elements[4];
char path[4];
int result = 0;

void GenPermutation(int level)
{
	if (level == 4)
	{
		++result;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (level >= 1 &&
			((path[level - 1] == 'B' && elements[i] == 'T') ||
				(path[level - 1] == 'T' && elements[i] == 'B')))
			continue;

		path[level] = elements[i];
		GenPermutation(level + 1);
		path[level] = '\0';
	}
}

int main(void)
{
	for (auto& data : elements)
	{
		cin >> data;
	}

	GenPermutation(0);

	cout << result;

	return 0;
}
