#include <iostream>

using namespace std;

void run(int input)
{
	int arr[3][3];

	int num = 1;
	if (input < 10)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				arr[i][j] = num++;
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 2; j >= 0; --j)
			{
				arr[i][j] = num++;
			}
		}
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			cout << data;
		}
		cout << endl;
	}
}

int main(void)
{
	int input;

	cin >> input;

	run(input);

	return 0;
}