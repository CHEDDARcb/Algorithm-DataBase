#include <iostream>

using namespace std;

int arr[2][3];
int sum = 0;

void input()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> arr[i][j];
		}
	}
}

void process()
{
	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			sum += data;
		}
	}
}

void output()
{
	cout << sum;
}

int main(void)
{
	input();
	process();
	output();

	return 0;
}