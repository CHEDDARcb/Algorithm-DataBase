#include <iostream>

using namespace std;

int main(void)
{
	char arr[2];

	for (int i = 0; i < 2; ++i)
		cin >> arr[i];

	for (int i = 0; i < 2; ++i)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
			arr[i] = static_cast<char>(arr[i] - 'a' + 'A');
		else if (arr[i] >= 'A' && arr[i] <= 'Z')
			arr[i] = static_cast<char>(arr[i] - 'A' + 'a');
	}

	for (const auto& data : arr)
	{
		cout << data;
	}

	return 0;
}