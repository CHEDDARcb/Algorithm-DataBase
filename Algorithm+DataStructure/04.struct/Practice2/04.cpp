#include <iostream>

using namespace std;

int main(void)
{
	int arr[3][3] =
	{
		{10, 3, 20},
		{60, 30, 40},
		{20, 30, 40}
	};
	int input1, input2;

	cin >> input1 >> input2;

	int cnt = 0;
	for (const auto& row : arr)
		for (const auto& data : row)
			if (data >= input1 && data <= input2)
				++cnt;

	cout << cnt;

	return 0;
}
