#include <iostream>

using namespace std;

int main(void)
{
	int arr[3][3]{};
	char input;

	cin >> input;

	int num = 1;
	if (input >= '0' && input <= '9')
	{
		for (int i = 2; i >= 0; --i)
		{
			for (int j = 2; j >= i; --j)
			{
				arr[i][j] = num++;
			}
		}
	}
	else if (input >= 'A' && input <= 'Z')
	{
		for (int i = 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				arr[i][j] = num++;
			}
		}
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (!data)
				cout << " " << " ";
			else
				cout << data << " ";
		}
		cout << endl;
	}

	return 0;
}