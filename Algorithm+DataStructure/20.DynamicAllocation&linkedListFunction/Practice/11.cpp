#include <iostream>

using namespace std;

int base[3][3] =
{
	{0, 5, 4},
	{3, 0, 0},
	{0, 0, 1}
};

void Rotate()
{

	for (int i = 0; i < 3; ++i)
	{
		for (int j = i; j < 3; ++j)
		{
			int tmp = base[i][j];
			base[i][j] = base[j][i];
			base[j][i] = tmp;
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		int tmp = base[i][0];
		base[i][0] = base[i][2];
		base[i][2] = tmp;
	}
}

int main(void)
{
	int n;
	cin >> n;

	n %= 4;
	for (int i = 0; i < n; ++i)
	{
		Rotate();
	}

	for (const auto& row : base)
	{
		for (const auto& data : row)
		{
			if (data == 0)
				cout << "_";
			else
				cout << data;
		}
		cout << endl;
	}

	return 0;
}