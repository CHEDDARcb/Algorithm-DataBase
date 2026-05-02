#include <iostream>

using namespace std;

char arr[3][5] =
{
	{'D', 'A', 'C', 'C', 'D'},
	{'s', 'D', 'F', 'A', 'E'},
	{'E', 'E', 'T', 'J', 'H'},
};

int CHECK(char d)
{
	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data == d)
				return 1;
		}
	}

	return 0;
}

void INPUT()
{
	char input;

	cin >> input;

	int result = CHECK(input);

	if (result)
		cout << "있음";
	else
		cout << "없음";
}

int main(void)
{
	INPUT();

	return 0;
}