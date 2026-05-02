#include <iostream>

using namespace std;

int main(void)
{
	char arr[4] = { 'B', 'T', 'K', 'A' };
	int num;

	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < sizeof(arr) / sizeof(char); ++j)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}

	return 0;
}