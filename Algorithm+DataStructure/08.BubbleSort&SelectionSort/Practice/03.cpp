#include <iostream>

using namespace std;

int main(void)
{
	char input;
	char arr[3][3]{};

	cin >> input;
	int i = 2;
	while (i >= 0)
	{
		int j = 0;
		while (j <= 2 - i)
		{
			arr[i][j++] = input++;
		}
		--i;
	}

	i = 0;
	while (i < 3)
	{
		int j = 0;
		while (j < 3)
		{
			if (arr[i][j] == '0')
			{
				cout << " ";
			}
			else
			{
				cout << arr[i][j];
			}
			j++;
		}
		cout << endl;
		++i;
	}

	return 0;
}