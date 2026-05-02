#include <iostream>

using namespace std;

int main(void)
{
	char arr[4][4];
	char c;

	cin >> c;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			arr[i][j] = c;
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

	return 0;
}#include <iostream>

using namespace std;

int main(void)
{
	int arr[3];

	for (int i = 0; i < 3; ++i)
		cin >> arr[i];

	int min = arr[0];
	int max = arr[0];

	for (int i = 1; i < 3; ++i)
	{
		if (min > arr[i])
			min = arr[i];

		if (max < arr[i])
			max = arr[i];
	}

	cout << "MAX=" << max << endl;
	cout << "MIN=" << min << endl;

	return 0;
}