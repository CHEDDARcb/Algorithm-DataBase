#include <iostream>

using namespace std;

int main(void)
{
	int num;
	char ch;
	char arr[5][5]{};

	cin >> num >> ch;

	for (int j = 4; j >= 0; --j)
	{
		arr[num - 1][j] = ch++;
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data == '\0')
			{
				cout << "0" << " ";
			}
			else
			{
				cout << data << " ";
			}
		}
		cout << endl;
	}

	return 0;
}