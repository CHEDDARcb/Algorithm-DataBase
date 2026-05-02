#include <iostream>
#include <cmath>

using namespace std;

int arr[5] = { 3, 5, 1, 9, 7 };
char input;

void MoveRight()
{
	int last = arr[4];
	for (int i = 3; i >= 0; --i)
	{
		arr[i + 1] = arr[i];
	}
	arr[0] = last;
}

void MoveLeft()
{
	int first = arr[0];
	for (int i = 1; i <= 4; ++i)
	{
		arr[i - 1] = arr[i];
	}
	arr[4] = first;
}

int main(void)
{
	for (int i = 0; i < 4; ++i)
	{
		cin >> input;

		if (input == 'R')
		{
			MoveRight();
		}
		else if (input == 'L')
		{
			MoveLeft();
		}
	}

	for (const auto& data : arr)
		cout << data << " ";

	return 0;
}