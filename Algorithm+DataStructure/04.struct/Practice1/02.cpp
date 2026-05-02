#include <iostream>

using namespace std;

int main(void)
{
	int arr[3][5] =
	{
		{'A', 'B', 'C', 'D', 'E'},
		{'E', 'A', 'B', 'A', 'B'},
		{'A', 'C', 'D', 'E', 'R'}
	};
	char input;

	cin >> input;

	int cnt = 0;
	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data == input)
				cnt++;
		}
	}

	if (cnt >= 3)
		cout << "대발견" << endl;
	else if (cnt >= 1 && cnt <= 2)
		cout << "발견" << endl;
	else
		cout << "미발견" << endl;

	return 0;
}