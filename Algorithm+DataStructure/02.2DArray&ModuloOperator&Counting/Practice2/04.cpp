#include <iostream>

using namespace std;

int main(void)
{
	char arr[3][5];
	char input;

	cin >> input;

	for (int y = 0; y < sizeof(arr) / sizeof(arr[0]); ++y)
	{
		for (int x = 0; x < sizeof(arr[0]) / sizeof(char); ++x)
		{
			arr[y][x] = input++;
		}
	}

	return 0;
}