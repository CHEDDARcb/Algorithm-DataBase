#include <iostream>

using namespace std;

char arr[2][3] =
{
	{'F', 'E', 'W'},
	{'D', 'C', 'A'}
};

void findCh(char _target)
{
	int counting = 0;

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data == _target)
			{
				++counting;
				break;
			}
		}
	}

	if (counting)
		cout << "발견";
	else
		cout << "미발견";
}

int main(void)
{
	char input;

	cin >> input;

	findCh(input);

	return 0;
}
