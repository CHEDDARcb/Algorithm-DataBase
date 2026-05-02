#include <iostream>

using namespace std;

char path[4]{};
char name[6] = { '1', '2', '3', '4', '5', '6' };
int n;

void DicePermu(int level)
{
	if (level == n)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 6; ++i)
	{
		path[level] = name[i];
		DicePermu(level + 1);
		path[level] = '\0';
	}
}

int main(void)
{
	cin >> n;
	DicePermu(0);

	return 0;
}