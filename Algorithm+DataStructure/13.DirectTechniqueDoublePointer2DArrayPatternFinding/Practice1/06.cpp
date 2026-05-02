#include <iostream>

using namespace std;

struct Train
{
	bool CompName(const char _name[])
	{
		int i = 0;
		while (name[i] != '\0' && _name[i] != '\0')
		{
			if (name[i] != _name[i])
				return false;
			++i;
		}

		return true;
	}

	int win;
	char name[100];
};

int main()
{
	Train train[7] =
	{ {15, "summer"}, {33, "cloe"}, {24, "summer"}, {28, "niki"},
		{32, "jenny"}, {20, "summer"}, {40, "coco"} };

	int flWin;
	char flName[100];

	cin >> flName >> flWin;

	int result;
	for (int i = 0; i < 7; ++i)
	{
		if (flWin == train[i].win)
		{
			if (train[i].CompName(flName))
			{
				result = i;
				break;
			}
		}
	}

	cout << result;

	return 0;
}