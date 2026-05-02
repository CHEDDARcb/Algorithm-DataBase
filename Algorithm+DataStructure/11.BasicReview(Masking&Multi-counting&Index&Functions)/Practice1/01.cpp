#include<iostream>

using namespace std;

int main()
{
	char base[3][4] =
	{
		{'A', 'T', 'K', 'B'},
		{'C', 'Z', 'F', 'D'},
		{'H', 'G', 'E', 'I'}
	};
	char input;

	cin >> input;

	int xOffset, yOffset;
	cin >> yOffset >> xOffset;

	bool isfind = false;
	char* target;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			target = *(base + i) + j;
			if (*target == input)
			{
				isfind = true;
				break;
			}
		}
		if (isfind)
			break;
	}

	if (isfind)
		cout << *(target + yOffset * 4 + xOffset) << endl;
}