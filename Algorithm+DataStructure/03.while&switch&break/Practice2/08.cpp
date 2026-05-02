#include <iostream>

using namespace std;

int main(void)
{
	int arr[6][3]{};
	int n1, n2;

	cin >> n1 >> n2;

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i <= 5 / 2)
				arr[i][j] = n1;
			else
				arr[i][j] = n2;
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}