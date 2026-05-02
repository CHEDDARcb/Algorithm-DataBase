#include <iostream>

using namespace std;

int main()
{
	int input[4][2] =
	{
		{0, 1},
		{1, 0},
		{3, 0},
		{3, 1},
	};
	int vect[4][3]{};

	for (int i = 0; i < 4; ++i)
	{
		int y = input[i][0];
		int x = input[i][1];

		vect[y][x] = 5;
	}

	for (auto& row : vect)
	{
		for (auto& data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}

	return 0;
}