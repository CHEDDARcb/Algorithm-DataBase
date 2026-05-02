#include <iostream>

using namespace std;

int main(void)
{
	int arr[3][3] =
	{
		{3, 4, 1},
		{2, 1, 4},
		{3, 3, 0}
	};

	int evenCnt = 0;
	int oddCnt = 0;
	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data % 2)
				++oddCnt;
			else
				++evenCnt;
		}
	}

	cout << "Â¦¼ö: " << evenCnt << endl;
	cout << "È¦¼ö: " << oddCnt << endl;

	return 0;
}