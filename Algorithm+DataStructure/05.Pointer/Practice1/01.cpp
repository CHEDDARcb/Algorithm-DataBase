#include <iostream>

using namespace std;

int main(void)
{
	int arr[4][4]{};
	int input;

	cin >> input;

	if (input % 2)
	{
		for (int i = 3; i >= 0; --i)
		{
			arr[3 - i][i] = (i - 4) * (-1);
		}
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			arr[i][i] = i + 1;
		}
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}
	return 0;
}
