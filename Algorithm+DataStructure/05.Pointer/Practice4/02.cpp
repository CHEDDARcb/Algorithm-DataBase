#include <iostream>

using namespace std;

int arr[3][3] =
{
	{1, 1, 1},
	{1, 2, 1},
	{3, 6, 3}
};

int Count(int x)
{
	int count = 0;

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data == x)
				count++;
		}
	}

	return count;
}

int main(void)
{
	int input;

	cin >> input;

	cout << Count(input);

	return 0;
}
