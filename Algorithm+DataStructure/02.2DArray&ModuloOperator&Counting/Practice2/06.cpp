#include <iostream>

using namespace std;

int main(void)
{
	int arr[2][4]{};
	int x, y;

	cin >> y >> x;
	arr[y][x] = 1;

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