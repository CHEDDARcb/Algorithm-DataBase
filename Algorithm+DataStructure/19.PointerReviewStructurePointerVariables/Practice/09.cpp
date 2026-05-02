#include <iostream>

using namespace std;

char path[4]{};
const char battle[2] = { 'O', 'X' };
int winCNT, lossCNT;

void GenPermu(int level)
{
	if (level == 3)
	{
		if (winCNT)
			cout << winCNT << "½Â";
		if (lossCNT)
			cout << lossCNT << "ÆÐ";

		cout << "(";
		for (int i = 0; i < 3; ++i)
		{
			if (path[i] == 'O')
				cout << "½Â";
			else if (path[i] == 'X')
				cout << "ÆÐ";
		}
		cout << ")";
		cout << endl;

		return;
	}

	for (int i = 0; i < 2; ++i)
	{
		if (i)
			lossCNT++;
		else
			winCNT++;

		path[level] = battle[i];
		GenPermu(level + 1);
		path[level] = '\0';

		if (i)
			lossCNT--;
		else
			winCNT--;
	}
}

int main(void)
{
	GenPermu(0);
	return 0;
}