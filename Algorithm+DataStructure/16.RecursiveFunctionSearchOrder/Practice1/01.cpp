#include <iostream>

using namespace std;

char path[10]{};
char name[10] = "ABC";

void Tracking(int _level)
{
	if (_level == 2)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		path[_level] = name[i];
		Tracking(_level + 1);
		path[_level] = '\0';
	}
}


int main()
{
	Tracking(0);

	return 0;
}