#include <iostream>

using namespace std;

int main(void)
{
	char arr[3][3] =
	{
		{'a', 'b', 'E'},
		{'E', '2', 'W'},
		{'3', '2', '4'}
	};

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data >= 'A' && data <= 'Z')
				cout << static_cast<char>(data - 'A' + 'a') << " ";
			else if (data >= 'a' && data <= 'z')
				cout << static_cast<char>(data - 'a' + 'A') << " ";
			else if (data >= '0' && data <= '9')
				cout << static_cast<int>(data - '0') + 5 << " ";
		}
		cout << endl;
	}

	return 0;
}
