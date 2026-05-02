#include <iostream>

using namespace std;

char arr[4][3] =
{
	{'D', 'A', 'D'},
	{'D', 'W', 'Q'},
	{'A', 'S', 'D'},
	{'A', 'S', 'D'},
};

void find(char c)
{
	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data == c)
			{
				cout << "존재";
				return;
			}
		}
	}

	cout << "없음";
}

int main(void)
{
	char input;

	cin >> input;

	find(input);

	return 0;
}