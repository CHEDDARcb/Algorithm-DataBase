#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int map[3][6] =
	{
		3, 5, 4, 2, 2, 3,
		1, 3, 3, 3, 4, 2,
		5, 4, 4, 2, 3, 5
	};
	char price[5] = { 'T', 'P', 'G', 'K', 'C' };
	char input1;
	int input2;

	cin >> input1 >> input2;

	int y = input1 - 'A';
	int resultIdx = map[y][input2] - 1;

	cout << price[resultIdx];

	return 0;
}