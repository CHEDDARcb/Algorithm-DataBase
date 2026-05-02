#include <iostream>

using namespace std;

int main(void)
{
	char c1, c2;
	char arr[3][6];

	cin >> c1 >> c2;

	int i = 0;
	while (i < 3)
	{
		int j = 0;
		while (j < 6)
		{
			if (j > 3 && i + j >= 4)
				arr[i][j] = c2;
			else
				arr[i][j] = c1;
			++j;
		}
		++i;
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