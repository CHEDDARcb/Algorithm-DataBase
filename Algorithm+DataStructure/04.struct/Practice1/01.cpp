#include <iostream>

using namespace std;

int main(void)
{
	int arr[7] = { 4, 3, 6, 1, 3, 1, 5 };
	int input;

	cin >> input;

	int cnt = 0;
	for (const auto& data : arr)
	{
		if (data == input)
			++cnt;
	}

	cout << "숫자" << input << "개수는" << cnt << "개";

	return 0;
}
