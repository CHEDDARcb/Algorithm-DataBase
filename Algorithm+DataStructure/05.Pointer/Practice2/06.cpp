#include <iostream>

using namespace std;

int main(void)
{
	int arr[7] = { 3, 4, 1, 3, 2, 7, 3 };
	int input;

	cin >> input;

	bool flg = false;

	for (const auto& data : arr)
	{
		if (data == input)
		{
			flg = true;
			break;
		}
	}

	if (flg)
		cout << "발견";
	else
		cout << "미발견";

	return 0;
}