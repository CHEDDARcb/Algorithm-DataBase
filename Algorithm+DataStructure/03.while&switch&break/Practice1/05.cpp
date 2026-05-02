#include <iostream>

using namespace std;

int main(void)
{
	int arr[6] = { 3, 4, 1, 6, 7, 5 };

	int cnt = 0;
	while (cnt < 6)
	{
		cout << arr[cnt++] << " ";
	}

	return 0;
}