#include <iostream>

using namespace std;

char arr[3][3] =
{
	{'A', 'D', 'F'},
	{'Q', 'W', 'E'},
	{'Z', 'X', 'C'}
};

void Find(char target, int* iIdx, int* jIdx)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] == target)
			{
				*iIdx = i;
				*jIdx = j;

				return;
			}
		}
	}
}

int main(void)
{
	char input;
	cin >> input;

	int i, j;
	Find(input, &i, &j);

	cout << i << ", " << j;

	return 0;
}