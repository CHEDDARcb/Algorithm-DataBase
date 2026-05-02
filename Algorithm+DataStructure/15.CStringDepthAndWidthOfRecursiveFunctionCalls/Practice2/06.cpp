#include <iostream>

using namespace std;

int main()
{
	int arr[4][3] =
	{
		1, 5, 3,
		4, 5, 5,
		3, 3, 5,
		4, 6, 2
	};
	int a, b;

	cin >> a >> b;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] >= a && arr[i][j] <= b)
				arr[i][j] = 0;
		}
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data)
				cout << data << " ";
			else
				cout << "# ";
		}
		cout << endl;
	}

	return 0;
}