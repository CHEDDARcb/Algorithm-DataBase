#include <iostream>

using namespace std;

int main(void)
{
	int arr[6][2];

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < 6; ++i)
	{
		int data1 = arr[i][0];
		int data2 = arr[i][1];

		if (data1 < data2)
		{
			int tmp = data1;
			arr[i][0] = arr[i][1];
			arr[i][1] = tmp;

			++cnt;
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
	cout << cnt << "Έν" << endl;

	return 0;
}