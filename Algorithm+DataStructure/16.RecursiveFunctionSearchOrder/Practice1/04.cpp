#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int floor = 1;
	char input[10];
	for (int i = 0; i < 5; ++i)
	{
		cin >> input;

		if (strcmp(input, "up") == 0)
		{
			if (floor == -1) floor = 1;
			else ++floor;
		}
		else if (strcmp(input, "down") == 0)
		{
			if (floor == 1) floor = -1;
			else --floor;
		}
	}

	if (floor > 0)
		cout << floor;
	else
		cout << 'B' << floor * -1 << endl;

	return 0;
}