#include <iostream>

using namespace std;

int main(void)
{
	char arr[5];
	int cnt = 0;

	for (int i = 0; i < 5; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 5; ++i)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			++cnt;
		}
	}

	if (cnt < 1)
		cout << "숫자미발견" << endl;
	else
		cout << "숫자" << cnt << "개발견";

	return 0;
}