#include<iostream>

using namespace std;

int arr[3][3] =
{
	{3, 5, 9},
	{4, 2, 1},
	{5, 1, 5}
};

bool isExist(const int target)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] == target)
				return true;
		}
	}
	return false;
}

int main()
{
	int input[3];

	cin >> input[0] >> input[1] >> input[2];

	for (int i = 0; i < 3; ++i)
	{
		cout << input[i] << ": ";
		if (isExist(input[i]))
			cout << "존재" << endl;
		else
			cout << "미발견" << endl;
	}

	return 0;
}