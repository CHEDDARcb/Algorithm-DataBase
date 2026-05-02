#include <iostream>

using namespace std;

int arr[3][4] =
{
	{4, 3, 1, 1},
	{3, 1, 2, 1},
	{0, 0, 1, 2}
};

int main(void)
{
	int arr[3][4] =
	{
		{4, 3, 1, 1},
		{3, 1, 2, 1},
		{0, 0, 1, 2}
	};
	int input;

	cin >> input;

	int cnt = 0;
	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (input == data)
				++cnt;
		}
	}

	cout << cnt << "개 존재합니다.";

	return 0;
}