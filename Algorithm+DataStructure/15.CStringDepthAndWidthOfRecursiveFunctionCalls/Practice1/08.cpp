#include <iostream>
#include <cstring>

using namespace std;

void MovePosition(int* _xPos, int* _yPos, const char* _order)
{
	if (!strcmp(_order, "up"))
	{
		*_yPos -= 1;
	}
	else if (!strcmp(_order, "down"))
	{
		*_yPos += 1;

	}
	else if (!strcmp(_order, "right"))
	{
		*_xPos += 1;
	}
	else if (!strcmp(_order, "left"))
	{
		*_xPos -= 1;
	}
	else if (!strcmp(_order, "click"))
	{
		cout << *_yPos << "," << *_xPos << endl;
	}
}

int main()
{
	int xpos = 5;
	int ypos = 5;
	int num;

	cin >> num;

	char order[100];
	for (int i = 0; i < 3; ++i)
	{
		cin >> order;
		MovePosition(&xpos, &ypos, order);
	}
	return 0;
}