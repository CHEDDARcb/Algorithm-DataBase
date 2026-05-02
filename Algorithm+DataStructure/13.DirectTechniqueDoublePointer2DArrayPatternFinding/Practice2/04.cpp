#include <iostream>

using namespace std;

int main()
{
	int arr[4][4]{};
	char line;
	int idx;

	for (int k = 0; k < 3; ++k)
	{
		cin >> line >> idx;

		if (line == 'G')
		{
			for (int i = 0; i < 4; ++i)
			{
				arr[idx][i] = 1;
			}
		}
		else if (line == 'S')
		{
			for (int i = 0; i < 4; ++i)
			{
				arr[i][idx] = 1;
			}
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