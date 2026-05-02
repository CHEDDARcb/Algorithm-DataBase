#include <iostream>

using namespace std;

int main(void)
{
	char arr[3][5] =
	{
		{'a', 'b', 'a', 'c', 'z'},
		{'c', 't', 'a', 'c', 'd'},
		{'c', 'c', 'c', 'c', 'a'}
	};
	char input;

	cin >> input;

	int count = 0;

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data == input)
				count++;
		}

	}

	if (count >= 7)
		cout << "세상에";
	else if (count >= 5)
		cout << "와우";
	else if (count >= 3)
		cout << "이야";
	else
		cout << "이런";
	return 0;
}
