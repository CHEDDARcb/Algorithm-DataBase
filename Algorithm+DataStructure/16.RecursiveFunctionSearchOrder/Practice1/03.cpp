#include <iostream>

using namespace std;

char path[100]{};
char name[4] = { 'B', 'G', 'T', 'K' };

int num = 0;

void Tracking(int _curLev, const int _maxLev)
{
	++num;
	if (_curLev == _maxLev)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		path[_curLev] = name[i];
		Tracking(_curLev + 1, _maxLev);
		path[_curLev] = '\0';
	}
}

int main()
{
	int level;

	cin >> level;

	Tracking(0, level);

	cout << num;

	return 0;
}
