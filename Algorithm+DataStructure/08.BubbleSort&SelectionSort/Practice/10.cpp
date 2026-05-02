#include <iostream>

using namespace std;

int main(void)
{
	char strs[2][6];
	char arr[12];

	cin >> strs[0] >> strs[1];

	int arIdx = 0;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; strs[i][j] != '\0'; ++j)
		{
			arr[arIdx++] = strs[i][j];
		}
	}
	arr[arIdx] = '\0';

	cout << arr;

	return 0;
}