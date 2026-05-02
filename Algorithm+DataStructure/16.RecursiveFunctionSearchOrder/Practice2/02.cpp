#include <iostream>
#include <cstring>

using namespace std;

char combi[10]{};
char compatibility[2] = { 'X', 'O' };
int maxNum;

void CompatiPlan(int _pNum)
{
	if (maxNum == _pNum)
	{
		cout << combi << endl;
		return;
	}

	for (int i = 0; i < 2; ++i)
	{
		combi[_pNum] = compatibility[i];
		CompatiPlan(_pNum + 1);
		combi[_pNum] = '\0';
	}
}

int main()
{
	cin >> maxNum;

	CompatiPlan(0);

	return 0;
}