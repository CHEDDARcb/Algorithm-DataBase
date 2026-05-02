#include <iostream>

using namespace std;

int main(void)
{
	char arr[5][3] =
	{
		{'D', 'A', 'A'},
		{'B', 'C', 'D'},
		{'E', 'F', 'A'},
		{'A', 'A', 'D'},
		{'F', 'G', 'E'}
	};
	char input;

	cin >> input;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] == input)
				cout << '{' << i << "," << j << '}' << endl;
		}
	}

	return 0;
}