#include <iostream>

using namespace std;

int main(void)
{
	char c;
	int arr[3];

	for (int i = 0; i < 3; ++i)
	{
		cin >> c;
		arr[i] = static_cast<int>(c);
	}

	for (const auto& data : arr)
	{
		cout << data << endl;
	}

	return 0;
}