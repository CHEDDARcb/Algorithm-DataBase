#include <iostream>

using namespace std;

int main(void)
{
	int arr[3][3]{};
	int y, x, n;

	cin >> y >> x >> n;

	arr[y][x] = n;

	int i = 0;
	while (i < 3)
	{
		int j = 0;
		while (j < 3)
		{
			cout << arr[i][j];
			++j;
		}
		cout << endl;
		++i;
	}

	return 0;
}