#include <iostream>

using namespace std;

char path[10]{};
char name[5] = "ABCD";
int recurCount = 0;
bool isFound = false;
char target[10];

void Tracking(int _curLev, int _maxLev)
{
	if (_curLev == _maxLev)
	{
		++recurCount;
		if (strcmp(target, path) == 0)
			isFound = true;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (isFound)
			return;
		path[_curLev] = name[i];
		Tracking(_curLev + 1, _maxLev);
		path[_curLev] = '\0';
	}
}

int main()
{
	cin >> target;

	Tracking(0, 3);

	cout << recurCount << "¹øÂ°";

	return 0;
}